// OpenGlJanelas.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
		
#include <GL\glut.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

void display(void);
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);
void spinDisplay(void);


static GLfloat spin = 0.0;
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(0.25, 0.90, 1.0);
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();
	glutSwapBuffers();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) { glutIdleFunc(spinDisplay); }
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) { glutIdleFunc(NULL); }
		break;
	default:
		break;
	
	}

}
void spinDisplay(void) {
	spin = spin + 2.0;
	if (spin > 360.0) { spin = spin - 360.0; }
	glutPostRedisplay();
}