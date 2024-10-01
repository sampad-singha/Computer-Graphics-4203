#include<iostream>
#include<GL/glut.h>
#include<windows.h>
using namespace std;
int x1,x2,y1,y2;
const int windowWidth=650;
const int windowHeight=650;
void BresenhamLine()
{
      int dx=abs(x2-x1);
      int dy= abs(y2-y1);
      int x, y , xNext , yNext;
      float m = abs(dy/dx);
      if(m<1)
      {
          int p =2*dy-dx;
          int twoDY=2*dy;
          int twoDYDx=2 *(dy-dx);
          if(x1>x2)
          {
              x=x2;
              y=y2;
              xNext=x1;

          }
          else
          {
              x=x1;
              y=y1;
              xNext=x2;
          }
          glBegin(GL_POINTS);
          glVertex2i(x,y);

          while(x != xNext)
          {
              x++;

              if(p<0)
              {
                  p=p+twoDY;
              }
              else
              {
                  y++;
                  p=p+twoDYDx;
              }
              glVertex2i(x,y);
              cout  << x << " "  << y;
          }
          glEnd();
      }
      else
      {
          int p =2*dy-dx;

          int twoDx=2*dx;
          int twoDxDy=2 *(dx-dy);
          if(y1>y2)
          {
              x=x2;
              y=y2;
              yNext=y1;
          }
          else
          {
              x=x1;
              y=y1;
              yNext=y2;
          }
          glBegin(GL_POINTS);
          glVertex2i(x,y);
          while(y != yNext)
          {
              y++;

              if(p<0)
              {
                  p=p+twoDx;
              }
              else
              {
                  y++;
                  p=p+twoDxDy;
              }
              glVertex2i(x,y);
              cout << x << " "  << y;
          }
          glEnd();
      }
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glPointSize(3.0);
    BresenhamLine();
    glFlush();
}
void init()
{

    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,windowWidth, 0.0, windowHeight);
}
int main(int argc , char *argv[])
{
    cout << "Enter the values of x1 and y1: " << endl;
    cin >> x1>> y1;
    cout << "Enter the values of x2 and y2: " << endl;
    cin >> x2 >> y2;

    glutInit(&argc , argv);
    glutInitWindowSize(650,650);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
   return EXIT_SUCCESS;

}
