#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
#include<iostream>
using namespace std;

int currentSlide = 0;

float busX = -500.0f, busY = 200.0f, busSpeed = 4.0f;
float carX = -200.0f, carY = 100.0f, carSpeed = 3.0f;
float airplaneX = 100.0f, airplaneY = 900.0f, airplaneSpeed = 2.0f;
float studentX = 200.0f, studentSpeed = 1.0f;
float sunX = 900.0f, sunY = 950.0f;
float sunRadius = 50.0f, sunSpeed = 0.5f; // Speed of movement
bool movingUp = true;


void drawStars() {
    glColor3f(1.0f, 1.0f, 1.0f); // White color for stars

    glPointSize(2.0); // Size of stars
    glBegin(GL_POINTS);
    // Draw 20 stars at random positions
    glVertex2f(190, 750);
    glVertex2f(410, 800);
    glVertex2f(350, 830);
    glVertex2f(290, 810);
    glVertex2f(470, 950);
    glVertex2f(700, 950);
    glVertex2f(900, 900);
    glVertex2f(950, 820);
    glVertex2f(800, 820);
    glVertex2f(670, 750);
    glVertex2f(600, 970);
    glVertex2f(230, 890);
    glVertex2f(200, 950);
    glVertex2f(300, 950);
    glVertex2f(140, 970);
    glVertex2f(100, 910);
    glVertex2f(890, 965);
    glVertex2f(80, 950);
    glVertex2f(30, 770);
    glVertex2f(30, 970);
    glVertex2f(50, 890);
    glVertex2f(120, 765);
    glVertex2f(200, 850);
    glVertex2f(370, 940);
    glVertex2f(400, 900);
    glVertex2f(450, 870);
    glVertex2f(500, 890);
    glVertex2f(550, 930);
    glVertex2f(600, 860);
    glVertex2f(650, 840);
    glVertex2f(700, 850);
    glVertex2f(750, 900);
    glVertex2f(820, 980);
    glVertex2f(870, 760);
    glVertex2f(940, 930);
    glVertex2f(990, 880);
    glVertex2f(90, 800);
    glEnd();
}
//tree circle
void drawCircle(float x, float y, float radius) {
    int i;
    int triangleAmount = 20; // Number of triangles used to draw circle

    GLfloat twicePi = 2.0f * pi;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void drawMoon(float x, float y, float radius) {
    int i;
    int triangleAmount = 50; // Number of triangles used to draw the circle
    GLfloat twicePi = 2.0f * 3.14159f; // 2π for full circle

    // Draw the circular moon
    glColor3ub(252, 252, 220); // Light yellow color for the moon
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


void drawSun_S(float x, float y, float radius) {
    int i;
    int triangleAmount = 50; // Number of triangles used to draw circle
    GLfloat twicePi = 2.0f * pi;

    // Draw the glow
    glColor3ub(240, 235, 189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    // Center of circle
    glColor3f(1.0, 0.87, 0.33); // Semi-transparent yellow for the glow
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + ((radius + 15) * cos(i * twicePi / triangleAmount)), // Slightly larger radius for glow
            y + ((radius + 15) * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Draw the sun itself
    glColor3ub(240, 235, 189);// Yellow color for the sun
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of circle
    glColor3f(1.0, 0.87, 0.33);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


void drawCloud_S(float x, float y, float radius) {
    int i;
    int triangleAmount = 20; // Number of triangles used to draw circle

    GLfloat twicePi = 2.0f * pi;

    glColor3ub(250, 225, 195); // White color for clouds
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
}

void drawCloud_Ss() {

    //drawSun_S(893, 900, 60); //sun
    // half colud

    drawCloud_S(-10, 820, 40);//1
    drawCloud_S(38, 825, 30);//2
    drawCloud_S(10, 760, 30);//3
    drawCloud_S(45, 780, 32);//4

// Draw multiple clouds
    drawCloud_S(158, 900, 33);
    drawCloud_S(200, 920, 27);
    drawCloud_S(245, 918, 30);
    drawCloud_S(180, 867, 31);
    drawCloud_S(226, 880, 32);


// Draw multiple clouds
    drawCloud_S(660, 900, 33);
    drawCloud_S(702, 920, 27);
    drawCloud_S(747, 918, 30);
    drawCloud_S(682, 867, 31);
    drawCloud_S(728, 880, 32);

// Draw multiple clouds
    drawCloud_S(893, 960, 33);
    drawCloud_S(937, 980, 27);
    drawCloud_S(980, 978, 30);
    drawCloud_S(915, 927, 31);
    drawCloud_S(961, 940, 32);


}
//student
void drawCircle_S(float x, float y, float radius) {
    int i;
    int triangleAmount = 20; // Number of triangles used to draw circle

    GLfloat twicePi = 2.0f * pi;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void drawStudent_S(float x, float y) {

    // Head
    glColor3ub(255, 204, 153); // Skin color
    drawCircle_S(x, y + 60, 10); // Draw head with radius 10

    // Body (T-shirt)
    glColor3ub(130, 135, 168); // Light blue t-shirt
    glBegin(GL_QUADS);
    glVertex2f(x - 15, y + 40);
    glVertex2f(x + 15, y + 40);
    glVertex2f(x + 15, y);
    glVertex2f(x - 15, y);
    glEnd();

    // Arms (extending from the body)
    glColor3ub(255, 204, 153); // Skin color for arms
    glBegin(GL_QUADS);
    glVertex2f(x - 25, y + 35);
    glVertex2f(x - 15, y + 35);
    glVertex2f(x - 15, y + 10);
    glVertex2f(x - 25, y + 10);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + 15, y + 35);
    glVertex2f(x + 25, y + 35);
    glVertex2f(x + 25, y + 10);
    glVertex2f(x + 15, y + 10);
    glEnd();

    // Legs (pants)
    glColor3ub(99, 150, 115); // Dark blue jeans
    glBegin(GL_QUADS);
    glVertex2f(x - 10, y);
    glVertex2f(x, y);
    glVertex2f(x, y - 30);
    glVertex2f(x - 10, y - 30);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 10, y);
    glVertex2f(x + 10, y - 30);
    glVertex2f(x, y - 30);
    glEnd();

    // Shoes
    glColor3ub(0, 0, 0); // Black shoes
    glBegin(GL_QUADS);
    glVertex2f(x - 10, y - 30);
    glVertex2f(x - 5, y - 30);
    glVertex2f(x - 5, y - 35);
    glVertex2f(x - 10, y - 35);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + 5, y - 30);
    glVertex2f(x + 10, y - 30);
    glVertex2f(x + 10, y - 35);
    glVertex2f(x + 5, y - 35);
    glEnd();

}
void drawStudent(float x, float y) {
    // Head
    glColor3ub(255, 204, 153); // Skin color
    drawCircle_S(x, y + 60, 10); // Draw head with radius 10


    // Body (T-shirt)
    glColor3ub(53, 51, 59); // Light blue t-shirt
    glBegin(GL_QUADS);
    glVertex2f(x - 15, y + 40);
    glVertex2f(x + 15, y + 40);
    glVertex2f(x + 15, y);
    glVertex2f(x - 15, y);
    glEnd();

    // Arms (extending from the body)
    glColor3ub(255, 204, 153); // Skin color for arms
    glBegin(GL_QUADS);
    glVertex2f(x - 25, y + 35);
    glVertex2f(x - 15, y + 35);
    glVertex2f(x - 15, y + 10);
    glVertex2f(x - 25, y + 10);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + 15, y + 35);
    glVertex2f(x + 25, y + 35);
    glVertex2f(x + 25, y + 10);
    glVertex2f(x + 15, y + 10);
    glEnd();

    // Legs (pants)
    glColor3ub(13, 51, 112); // Dark blue jeans
    glBegin(GL_QUADS);
    glVertex2f(x - 10, y);
    glVertex2f(x, y);
    glVertex2f(x, y - 30);
    glVertex2f(x - 10, y - 30);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 10, y);
    glVertex2f(x + 10, y - 30);
    glVertex2f(x, y - 30);
    glEnd();

    // Shoes
    glColor3ub(1, 1, 0); // Black shoes
    glBegin(GL_QUADS);
    glVertex2f(x - 10, y - 30);
    glVertex2f(x - 5, y - 30);
    glVertex2f(x - 5, y - 35);
    glVertex2f(x - 10, y - 35);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + 5, y - 30);
    glVertex2f(x + 10, y - 30);
    glVertex2f(x + 10, y - 35);
    glVertex2f(x + 5, y - 35);
    glEnd();

}

//night lamp
void drawStreetLamp(float x, float y) {
    // Draw the pole of the lamp
    glBegin(GL_QUADS);
    glColor3ub(50, 50, 50); // Dark gray color for the pole
    glVertex2f(x - 5, y);         // Bottom left
    glVertex2f(x + 5, y);         // Bottom right
    glVertex2f(x + 5, y + 200);   // Top right
    glVertex2f(x - 5, y + 200);   // Top left
    glEnd();


    // Draw the light bulb
    glColor3ub(255, 255, 212); // Yellow for the light bulb
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y + 200); // Center of the bulb
    for (int i = 0; i <= 20; i++) {
        float angle = 2 * pi * i / 20;
        float dx = 15 * cos(angle);
        float dy = 15 * sin(angle);
        glColor3ub(230, 207, 7);
        glVertex2f(x + dx, y + 200 + dy);
    }
    glEnd();



    // Draw the base of the lamp
    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80); // Darker gray for the base
    glVertex2f(x - 5, y - 5);
    glVertex2f(x + 5, y - 5);
    glColor3ub(79, 25, 5);
    glVertex2f(x + 10, y+10);
    glVertex2f(x - 10, y+10);
    glEnd();
}

// Function to draw multiple street lamps in a grid
void drawStreetLampsGrid(float startX, float startY, int rows, int columns, float hSpacing, float vSpacing) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float x = startX + j * (hSpacing); // Horizontal position
            float y = startY - i * (vSpacing); // Vertical position
            drawStreetLamp(x, y); // Draw each street lamp
        }
    }
}


//day lamp
// Function to draw a single street lamp
void drawStreetLamp_S(float x, float y) {
   // Draw the pole of the lamp
    glBegin(GL_QUADS);
    glColor3ub(50, 50, 50); // Dark gray color for the pole
    glVertex2f(x - 5, y);         // Bottom left
    glVertex2f(x + 5, y);         // Bottom right
    glVertex2f(x + 5, y + 200);   // Top right
    glVertex2f(x - 5, y + 200);   // Top left
    glEnd();


    // Draw the light bulb
    glColor3ub(242, 242, 242); // Yellow for the light bulb
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y + 200); // Center of the bulb
    for (int i = 0; i <= 20; i++) {
        float angle = 2 * pi * i / 20;
        float dx = 15 * cos(angle);
        float dy = 15 * sin(angle);
        glVertex2f(x + dx, y + 200 + dy);
    }
    glEnd();

    // Draw the base of the lamp
    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80); // Darker gray for the base
    glVertex2f(x - 5, y - 5);
    glVertex2f(x + 5, y - 5);
    glColor3ub(79, 25, 5);
    glVertex2f(x + 10, y+10);
    glVertex2f(x - 10, y+10);
    glEnd();
}

// Function to draw multiple street lamps in a grid
void drawStreetLamp_SsGrid(float startX, float startY, int rows, int columns, float hSpacing, float vSpacing) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float x = startX + j * (hSpacing); // Horizontal position
            float y = startY - i * (vSpacing); // Vertical position
            drawStreetLamp_S(x, y); // Draw each street lamp
        }
    }
}
//night tong
void drawText_tong(const char* text, float x, float y) {
    glColor3ub(232, 84, 101); // Set text color (e.g., white)
    glRasterPos2f(x, y); // Position the text

    // Render each character
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

//day tong
void drawText_tong_S(const char* text, float x, float y) {
    glColor3ub(232, 84, 101); // Set text color (e.g., white)
    glRasterPos2f(x, y); // Position the text

    // Render each character
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawText_SEU(const char* text, float x, float y) {
    glColor3ub(0, 0, 0); // Set text color (e.g., white)
    glRasterPos2f(x, y); // Position the text

    // Render each character
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawText_SEUn(const char* text, float x, float y) {
    glColor3ub(0, 0, 0); // Set text color (e.g., white)
    glRasterPos2f(x, y); // Position the text

    // Render each character
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawText_flag(const char* text, float x, float y) {
    glColor3ub(232, 84, 101); // Set text color (e.g., white)
    glRasterPos2f(x, y); // Position the text

    // Render each character
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawText_flagS(const char* text, float x, float y) {
    glColor3ub(232, 84, 101); // Set text color (e.g., white)
    glRasterPos2f(x, y); // Position the text

    // Render each character
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawWindow(float x, float y, float size) {
    glBegin(GL_QUADS);
    glColor3ub(245, 247, 139); // Color for the window
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glColor3ub(247, 250, 212);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}

void drawWindow_S(float x, float y, float size) {
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // Color for the window
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}

void drawWindowsGrid(float startX, float startY, float windowSize, int rows, int columns, float hSpacing, float vSpacing) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float x = startX + j * (windowSize + hSpacing);
            float y = startY - i * (windowSize + vSpacing);
            drawWindow(x, y, windowSize);
        }
    }
}

void drawWindow_SsGrid(float startX, float startY, float windowSize, int rows, int columns, float hSpacing, float vSpacing) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float x = startX + j * (windowSize + hSpacing);
            float y = startY - i * (windowSize + vSpacing);
            drawWindow_S(x, y, windowSize);
        }
    }
}

void drawWindow1(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Color for the window
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawWindow_S1(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Color for the window
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

// Function to draw a grid of windows with dynamic sizes and scaling
void drawWindowsGrid1(float startX, float startY, float windowWidth, float windowHeight,float scale, int rows, int columns, float hSpacing, float vSpacing ) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float scaledWidth = windowWidth * scale;   // Scale width
            float scaledHeight = windowHeight * scale; // Scale height
            float x = startX + j * (scaledWidth + hSpacing);
            float y = startY - i * (scaledHeight + vSpacing);
            drawWindow1(x, y, scaledWidth, scaledHeight); // Use updated drawWindow
        }
    }
}

// Function to draw a grid of windows with dynamic sizes and scaling
void drawWindow_SsGrid1(float startX, float startY, float windowWidth, float windowHeight,float scale, int rows, int columns, float hSpacing, float vSpacing ) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float scaledWidth = windowWidth * scale;   // Scale width
            float scaledHeight = windowHeight * scale; // Scale height
            float x = startX + j * (scaledWidth + hSpacing);
            float y = startY - i * (scaledHeight + vSpacing);
            drawWindow_S1(x, y, scaledWidth, scaledHeight); // Use updated drawWindow_S
        }
    }
}

void drawWindow_S2(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glColor3ub(175, 213, 224); // Color for the window
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}
void drawWindow2(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glColor3ub(175, 213, 224); // Color for the window
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glColor3ub(73, 156, 184);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

// Function to draw a grid of windows with dynamic sizes and scaling
void drawWindowsGrid2(float startX, float startY, float windowWidth, float windowHeight,float scale, int rows, int columns, float hSpacing, float vSpacing ) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float scaledWidth = windowWidth * scale;   // Scale width
            float scaledHeight = windowHeight * scale; // Scale height
            float x = startX + j * (scaledWidth + hSpacing);
            float y = startY - i * (scaledHeight + vSpacing);
            drawWindow2(x, y, scaledWidth, scaledHeight); // Use updated drawWindow_S
        }
    }
}

void drawWindow_SsGrid2(float startX, float startY, float windowWidth, float windowHeight,float scale, int rows, int columns, float hSpacing, float vSpacing ) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float scaledWidth = windowWidth * scale;   // Scale width
            float scaledHeight = windowHeight * scale; // Scale height
            float x = startX + j * (scaledWidth + hSpacing);
            float y = startY - i * (scaledHeight + vSpacing);
            drawWindow_S2(x, y, scaledWidth, scaledHeight); // Use updated drawWindow_S
        }
    }
}

void drawTree(float x, float y) {

    // Draw the leaves of the tree
    glColor3ub(80, 97, 78); // Green color for the leaves
    drawCircle(x - 5, y + 200, 50);
    drawCircle(x - 20, y + 180, 60);
    drawCircle(x + 20, y + 180, 60);
    drawCircle(x + 2, y + 250, 50);


   // Draw the trunk of the tree
    glColor3ub(65,19,25); // Brown color for the trunk
    glBegin(GL_QUADS);
    glVertex2f(x - 10, y);
    glVertex2f(x + 10, y);
    glVertex2f(x + 10, y + 160);
    glVertex2f(x - 10, y + 160);
    glEnd();
}

void drawTree_S(float x, float y) {

    // Draw the leaves of the tree
    glColor3ub(145,160,119); // Green color for the leaves
    drawCircle_S(x - 5, y + 200, 50);
    drawCircle_S(x - 20, y + 180, 60);
    drawCircle_S(x + 20, y + 180, 60);
    drawCircle_S(x + 2, y + 250, 50);


   // Draw the trunk of the tree
    glColor3ub(65,19,25); // Brown color for the trunk
    glBegin(GL_QUADS);
    glVertex2f(x - 10, y);
    glVertex2f(x + 10, y);
    glVertex2f(x + 10, y + 160);
    glVertex2f(x - 10, y + 160);
    glEnd();
}

// Function to draw the bus
void drawBus_S(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0f);

    glColor3f(1.0, 0.8, 0.2); // Yellow color for the bus body

    // Draw the main body of the bus
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(500, 0);
    glVertex2f(500, 150);
    glVertex2f(0, 150);
    glEnd();

    // Draw the bus windows
    glColor3f(0.3, 0.7, 0.9); // Light blue for windows
    glBegin(GL_QUADS);
    for (int i = 50; i < 500; i += 100) {
        glVertex2f(i, 50);
        glVertex2f(i + 50, 50);
        glVertex2f(i + 50, 120);
        glVertex2f(i, 120);
    }
    glEnd();

    // Draw the bus wheels
    glColor3f(0.1, 0.1, 0.1); // Black color for wheels
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180;
        float wx = 100 + 30 * cos(angle);
        float wy = -30 * sin(angle);
        glVertex2f(wx, wy);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180;
        float wx = 400 + 30 * cos(angle);
        float wy = -30 * sin(angle);
        glVertex2f(wx, wy);
    }
    glEnd();

    glPopMatrix();
}

// Function to draw the car
void drawCar_S(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0f);

    glColor3f(0.8, 0.2, 0.2); // Red color for the car body

    // Draw the main body of the car
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(200, 0);
    glVertex2f(200, 80);
    glVertex2f(0, 80);
    glEnd();

    // Draw the roof of the car
    glBegin(GL_QUADS);
    glVertex2f(30, 80);
    glVertex2f(170, 80);
    glVertex2f(150, 120);
    glVertex2f(50, 120);
    glEnd();

    // Draw the car windows
    glColor3f(0.3, 0.7, 0.9); // Light blue for windows
    glBegin(GL_QUADS);
    glVertex2f(60, 80);
    glVertex2f(140, 80);
    glVertex2f(130, 110);
    glVertex2f(70, 110);
    glEnd();

    // Draw the car wheels
    glColor3f(0.1, 0.1, 0.1); // Black color for wheels
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180;
        float wx = 50 + 20 * cos(angle);
        float wy = -20 * sin(angle);
        glVertex2f(wx, wy);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180;
        float wx = 150 + 20 * cos(angle);
        float wy = -20 * sin(angle);
        glVertex2f(wx, wy);
    }
    glEnd();

    glPopMatrix();
}

// Function to draw the airplane
void drawAirplane_S(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0f);

    glColor3ub(161, 161, 161); // White color for the airplane body


    // Draw the airplane body
    glBegin(GL_QUADS);
    glColor3ub(161, 161, 161);
    glVertex2f(-50, -10);
    glVertex2f(50, -10);
    glColor3ub(0, 0, 0);
    glVertex2f(50, 10);
    glVertex2f(-50, 10);
    glEnd();

    // Draw the airplane tail
    glColor3f(0.0, 0.0, 1.0); // Blue color for the tail
    glBegin(GL_TRIANGLES);
    glVertex2f(-50, 10);
    glVertex2f(-70, 10);
    glVertex2f(-50, 30);
    glEnd();

    // DRAW stick
    glBegin(GL_QUADS);
    glColor3ub(179, 9, 9);
    glVertex2f(-100, 5);
    glVertex2f(-10, 5);
    glVertex2f(-10, 10);
    glVertex2f(-100, 10);
    glEnd();

        // DRAW FLAG
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-480, -5);
    glVertex2f(-100, -5);
    glVertex2f(-100, 35);
    glVertex2f(-480, 35);
    glEnd();


    // Draw the airplane wings
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-20, 10);
    glVertex2f(0, 40);
    glVertex2f(20, 10);
    glEnd();

    // Draw the airplane windows
    glColor3f(0.3, 0.7, 0.9); // Light blue for windows
    glBegin(GL_QUADS);
    glVertex2f(-30, 0);
    glVertex2f(-20, 0);
    glVertex2f(-20, 10);
    glVertex2f(-30, 10);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-10, 0);
    glVertex2f(0, 0);
    glVertex2f(0, 10);
    glVertex2f(-10, 10);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(10, 0);
    glVertex2f(20, 0);
    glVertex2f(20, 10);
    glVertex2f(10, 10);
    glEnd();

    glPopMatrix();
}
void drawAirplane(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0f);

    glColor3ub(161, 161, 161); // White color for the airplane body

    // Draw the airplane body
    glBegin(GL_QUADS);
    glColor3ub(161, 161, 161);
    glVertex2f(-50, -10);
    glVertex2f(50, -10);
    glColor3ub(0, 0, 0);
    glVertex2f(50, 10);
    glVertex2f(-50, 10);
    glEnd();

    // Draw the airplane tail
    glColor3f(0.0, 0.0, 1.0); // Blue color for the tail
    glBegin(GL_TRIANGLES);
    glVertex2f(-50, 10);
    glVertex2f(-70, 10);
    glVertex2f(-50, 30);
    glEnd();

        // DRAW stick
    glBegin(GL_QUADS);
    glColor3ub(179, 9, 9);
    glVertex2f(-100, 5);
    glVertex2f(-10, 5);
    glVertex2f(-10, 10);
    glVertex2f(-100, 10);
    glEnd();

        // DRAW FLAG
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-480, -5);
    glVertex2f(-100, -5);
    glVertex2f(-100, 35);
    glVertex2f(-480, 35);
    glEnd();


    // Draw the airplane wings
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-20, 10);
    glVertex2f(0, 40);
    glVertex2f(20, 10);
    glEnd();

    // Draw the airplane windows
    glColor3ub(245, 255, 150); // Light blue for windows
    glBegin(GL_QUADS);
    glVertex2f(-30, 0);
    glVertex2f(-20, 0);
    glVertex2f(-20, 10);
    glVertex2f(-30, 10);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-10, 0);
    glVertex2f(0, 0);
    glVertex2f(0, 10);
    glVertex2f(-10, 10);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(10, 0);
    glVertex2f(20, 0);
    glVertex2f(20, 10);
    glVertex2f(10, 10);
    glEnd();

    glPopMatrix();
}
// Update function to animate objects
void update(int value) {
    busX += busSpeed;// busx = busx+ spseed
    carX -= carSpeed;
    airplaneX += airplaneSpeed;
    studentX += studentSpeed;

    if (studentX > 1000) { // Stop at a position
        studentX = 0;
    }

    if (movingUp) {
        sunY += sunSpeed;
        if (sunY > 550) {
            movingUp = false;
        }
    } else {
        sunY -= sunSpeed;
        if (sunY < 50) {
            movingUp = true;
        }
    }
    // Loop the bus and car when they go off-screen
    if (busX > 1400) {
        busX = -500;
    }
    if (carX < -600) {
        carX = 1000;
    }
    if (airplaneX > 1200) {
        airplaneX = 100; // Start from the left again
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}
void display2(){


glClear(GL_COLOR_BUFFER_BIT);


//background
//Quads
glBegin(GL_QUADS);
glColor3ub(66,76,101);
glVertex2f( 0,0 );
glColor3ub(4,35,71);
glVertex2f( 1000, 0 );
glColor3ub(12,39,74);
glVertex2f( 1000, 1000);
glColor3ub(6,7,26);
glVertex2f( 0, 1000);
glEnd();


//niche rasta  assh
glBegin(GL_QUADS);
glColor3ub(90,88,89);
glVertex2f( 0,0 );
glVertex2f( 1000, 0 );
glVertex2f( 1000, 200);
glVertex2f( 0, 200);
glEnd();



//pichoner building
glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 20,650 );
glVertex2f( 50, 650 );
glVertex2f( 50, 420);
glVertex2f( 20, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 50,730 );
glVertex2f( 100, 730 );
glVertex2f( 100, 420);
glVertex2f( 50, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 110,730 );
glVertex2f( 150, 700 );
glVertex2f( 150, 420);
glVertex2f( 110, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 150,580 );
glVertex2f( 200, 580 );
glVertex2f( 200, 420);
glVertex2f( 150, 420);
glEnd();



glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 200,700 );
glVertex2f( 250, 700 );
glVertex2f( 250, 420);
glVertex2f( 200, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(77,75,76);
glVertex2f( 240,770 );
glVertex2f( 290, 770 );
glVertex2f( 290, 420);
glVertex2f( 240, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 280,670 );
glVertex2f( 350, 670 );
glVertex2f( 350, 420);
glVertex2f( 280, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(77,75,76);
glVertex2f( 0,650 );
glVertex2f( 50, 650 );
glVertex2f( 50, 420);
glVertex2f( 0, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(77,75,76);
glVertex2f( 30,650 );
glVertex2f( 50, 650 );
glVertex2f( 50, 665);
glVertex2f( 30, 665);
glEnd();

glBegin(GL_QUADS);
glColor3ub(77,75,76);
glVertex2f( 30,650 );
glVertex2f( 50, 650 );
glVertex2f( 50, 665);
glVertex2f( 30, 665);
glEnd();



glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(300, 700);
glVertex2f(350, 700);
glVertex2f(350, 420);
glVertex2f(300, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(400, 700);
glVertex2f(450, 700);
glVertex2f(450, 420);
glVertex2f(400, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(500, 700);
glVertex2f(550, 700);
glVertex2f(550, 420);
glVertex2f(500, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(600, 700);
glVertex2f(680, 700);
glVertex2f(680, 420);
glVertex2f(600, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(700, 800);
glVertex2f(760, 750);
glVertex2f(760, 420);
glVertex2f(700, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(79,77,78);
glVertex2f(770, 720);
glVertex2f(820, 735);
glVertex2f(820, 420);
glVertex2f(770, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(790, 600);
glVertex2f(840, 600);
glVertex2f(840, 420);
glVertex2f(790, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(900, 700);
glVertex2f(950, 700);
glVertex2f(950, 420);
glVertex2f(900, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(1000, 700);
glVertex2f(1050, 700);
glVertex2f(1050, 420);
glVertex2f(1000, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(79,77,78);
glVertex2f(859, 750);
glVertex2f(900, 750);
glVertex2f(900, 420);
glVertex2f(859, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(79,77,78);
glVertex2f(960, 800);
glVertex2f(1000, 800);
glVertex2f(1000, 420);
glVertex2f(960, 420);
glEnd();

// moon
drawMoon(150,900,50);


//niche rasta  assh
glBegin(GL_QUADS);
glColor3ub(90,88,89);
glVertex2f( 0,0 );
glVertex2f( 1000, 0 );
glVertex2f( 1000, 200);
glVertex2f( 0, 200);
glEnd();

//rasta white border
glBegin(GL_QUADS);
glColor3ub(223,227,233);
glVertex2f( 0,200 );
glVertex2f( 1000, 200 );
glVertex2f( 1000, 220);
glVertex2f( 0, 220);
glEnd();

//rasta red border
glBegin(GL_QUADS);
glColor3ub(144,79,62);
glVertex2f( 0,220 );
glVertex2f( 1000, 220 );
glVertex2f( 1000, 250);
glVertex2f( 0, 250);
glEnd();


//rasta aash2
glBegin(GL_QUADS);
glColor3ub(157,157,157);
glVertex2f( 0,250 );
glVertex2f( 1000, 250 );
glVertex2f( 1000, 360);
glVertex2f( 0, 360);
glEnd();

//grn border rasta
glBegin(GL_QUADS);
glColor3ub(40, 54, 27);
glVertex2f( 0,360 );
glVertex2f( 1000, 360 );
glVertex2f( 1000, 520);
glVertex2f( 0, 520);
glEnd();


//tree
    drawTree(100, 360);  // Adjust the coordinates as needed
    drawTree(300, 360);
    drawTree(500, 360);
    drawTree(700, 360);
    drawTree(900, 360);


//cha kha
//main
glBegin(GL_QUADS);
glColor3ub(161, 161, 161);
glVertex2f( 50,240 );
glVertex2f( 190, 240 );
glColor3ub(90,88,89);
glVertex2f( 190, 390);
glVertex2f( 50, 390);
glEnd();

//nicher border
glBegin(GL_QUADS);
glColor3ub(39,25,29);
glVertex2f( 50,240 );
glVertex2f( 190, 240 );
glVertex2f( 190, 255);
glVertex2f( 50, 255);
glEnd();

//red table
glBegin(GL_QUADS);
glColor3ub(86,48,39);
glVertex2f( 90,255 );
glVertex2f( 190, 255 );
glVertex2f( 190, 300);
glVertex2f( 90, 300);
glEnd();

//blk border side
glBegin(GL_QUADS);
glColor3ub(32,32,30);
glVertex2f( 80,255 );
glVertex2f( 90, 255 );
glVertex2f( 90, 300);
glVertex2f( 80, 290);
glEnd();
//side
glBegin(GL_QUADS);
glColor3ub(54,54,54);
glVertex2f( 20,240 );
glVertex2f( 50, 240 );
glVertex2f( 50, 390);
glVertex2f( 20, 350);
glEnd();


//roof
glBegin(GL_QUADS);
glColor3ub(191,91,67);
glVertex2f( 90,340 );
glVertex2f( 230, 340 );
glVertex2f( 190, 390);
glVertex2f( 50, 390);
glEnd();

//border1
glBegin(GL_QUADS);
glColor3ub(60,49,51);
glVertex2f( 90,220 );
glVertex2f( 96, 220 );
glVertex2f( 96, 340);
glVertex2f( 90, 340);
glEnd();

//board
glBegin(GL_QUADS);
glColor3ub(247, 247, 247);
glVertex2f( 50,390 );
glVertex2f( 190, 390 );
glVertex2f( 190, 450);
glVertex2f( 50, 450);
glEnd();


//border2
glBegin(GL_QUADS);
glColor3ub(60,49,51);
glVertex2f( 224,220 );
glVertex2f( 230, 220 );
glVertex2f( 230, 340);
glVertex2f( 224, 340);
glEnd();



//seu building
glBegin(GL_QUADS);
glColor3ub(231,232,227);
glVertex2f( 480,250 );
glVertex2f( 540, 250 );
glVertex2f( 540, 840);
glVertex2f( 480, 840);
glEnd();


//seu building
glBegin(GL_QUADS);
glColor3ub(186, 186, 184);
glVertex2f( 480,250 );
glColor3ub(217, 217, 217);
glVertex2f( 540, 250 );
glVertex2f( 540, 840);
glColor3ub(231,232,227);
glVertex2f( 480, 840);
glEnd();


//aashbuilding1
glBegin(GL_QUADS);
glColor3ub(140,177,194);
glVertex2f( 410,250 );
glVertex2f( 480, 250 );
glColor3ub(78, 111, 128);
glVertex2f( 480, 750);
glVertex2f( 410, 750);
glEnd();

//red building
glBegin(GL_QUADS);
glColor3ub(231,103,79);
glVertex2f( 325,250 );
glVertex2f( 373, 250 );
glColor3ub(250, 139, 55);
glVertex2f( 373, 770);
glVertex2f( 325, 770);
glEnd();

//aashbuilding2
glBegin(GL_QUADS);
glColor3ub(140,177,194);
glVertex2f( 370,250 );
glVertex2f( 410, 250 );
glColor3ub(78, 111, 128);
glVertex2f( 410, 730);
glVertex2f( 370, 730);
glEnd();

//seu side building1
glBegin(GL_QUADS);
glColor3ub(132,132,132);
glVertex2f( 540,250 );
glVertex2f( 590, 250 );
glVertex2f( 590, 840);
glVertex2f( 540, 800);
glEnd();

//seu side building2
glBegin(GL_QUADS);
glColor3ub(132,132,132);
glVertex2f( 590,250 );
glVertex2f( 620, 250 );
glVertex2f( 620, 840);
glVertex2f( 590, 840);
glEnd();

//aashbuilding inside
glBegin(GL_QUADS);
glColor3ub(48, 70, 77);
glVertex2f( 390,250 );
glVertex2f( 460, 250 );
glColor3ub(82, 120, 133);
glVertex2f( 460, 340);
glColor3ub(14,177,194);
glVertex2f( 390, 340);
glEnd();

drawStars();
drawText_tong_S("Kuddus er tong",59,418);
drawStudent_S(studentX,260);
drawAirplane(airplaneX, airplaneY, 0.6f);
drawText_flag("Sir, Congratulations!!",airplaneX-250,airplaneY);
drawStudent(150,260);
drawText_SEU("SEU",491,800);
drawStreetLampsGrid(250, 200, 1, 5, 300, 200);
drawWindowsGrid(380, 700, 25, 11, 3, 6, 10);
drawWindowsGrid1(330, 680,15 ,100 ,0.5 ,6, 3, 5, 15);
drawWindowsGrid2(485, 740,20 ,60 ,0.5 ,9, 3, 8, 18);
drawCar_S(carX, carY, 0.8f);

glFlush();

}



void display1(){

glClear(GL_COLOR_BUFFER_BIT);

//background
//Quads

glBegin(GL_QUADS);
glColor3ub(252, 208, 182);
glVertex2f( 0,0 );
glVertex2f( 1000, 0 );
glColor3ub(252, 178, 104);
glVertex2f( 1000, 1000);
glVertex2f( 0, 1000);
glEnd();


drawSun_S(sunX, sunY, sunRadius);
//niche rasta  assh
glBegin(GL_QUADS);
glColor3ub(90,88,89);
glVertex2f( 0,0 );
glVertex2f( 1000, 0 );
glVertex2f( 1000, 200);
glVertex2f( 0, 200);
glEnd();



//pichoner building
glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 20,650 );
glVertex2f( 50, 650 );
glVertex2f( 50, 420);
glVertex2f( 20, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 50,730 );
glVertex2f( 100, 730 );
glVertex2f( 100, 420);
glVertex2f( 50, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 110,730 );
glVertex2f( 150, 700 );
glVertex2f( 150, 420);
glVertex2f( 110, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 150,580 );
glVertex2f( 200, 580 );
glVertex2f( 200, 420);
glVertex2f( 150, 420);
glEnd();



glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 200,700 );
glVertex2f( 250, 700 );
glVertex2f( 250, 420);
glVertex2f( 200, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(77,75,76);
glVertex2f( 240,770 );
glVertex2f( 290, 770 );
glVertex2f( 290, 420);
glVertex2f( 240, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42,46,49);
glVertex2f( 280,670 );
glVertex2f( 350, 670 );
glVertex2f( 350, 420);
glVertex2f( 280, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(77,75,76);
glVertex2f( 0,650 );
glVertex2f( 50, 650 );
glVertex2f( 50, 420);
glVertex2f( 0, 420);
glEnd();


glBegin(GL_QUADS);
glColor3ub(77,75,76);
glVertex2f( 30,650 );
glVertex2f( 50, 650 );
glVertex2f( 50, 665);
glVertex2f( 30, 665);
glEnd();

glBegin(GL_QUADS);
glColor3ub(77,75,76);
glVertex2f( 30,650 );
glVertex2f( 50, 650 );
glVertex2f( 50, 665);
glVertex2f( 30, 665);
glEnd();



glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(300, 700);
glVertex2f(350, 700);
glVertex2f(350, 420);
glVertex2f(300, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(400, 700);
glVertex2f(450, 700);
glVertex2f(450, 420);
glVertex2f(400, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(500, 700);
glVertex2f(550, 700);
glVertex2f(550, 420);
glVertex2f(500, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(600, 700);
glVertex2f(680, 700);
glVertex2f(680, 420);
glVertex2f(600, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(700, 800);
glVertex2f(760, 750);
glVertex2f(760, 420);
glVertex2f(700, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(79,77,78);
glVertex2f(770, 720);
glVertex2f(820, 735);
glVertex2f(820, 420);
glVertex2f(770, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(790, 600);
glVertex2f(840, 600);
glVertex2f(840, 420);
glVertex2f(790, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(900, 700);
glVertex2f(950, 700);
glVertex2f(950, 420);
glVertex2f(900, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(42, 46, 49);
glVertex2f(1000, 700);
glVertex2f(1050, 700);
glVertex2f(1050, 420);
glVertex2f(1000, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(79,77,78);
glVertex2f(859, 750);
glVertex2f(900, 750);
glVertex2f(900, 420);
glVertex2f(859, 420);
glEnd();

glBegin(GL_QUADS);
glColor3ub(79,77,78);
glVertex2f(960, 800);
glVertex2f(1000, 800);
glVertex2f(1000, 420);
glVertex2f(960, 420);
glEnd();



//niche rasta  assh
glBegin(GL_QUADS);
glColor3ub(90,88,89);
glVertex2f( 0,0 );
glVertex2f( 1000, 0 );
glVertex2f( 1000, 200);
glVertex2f( 0, 200);
glEnd();

//rasta white border
glBegin(GL_QUADS);
glColor3ub(223,227,233);
glVertex2f( 0,200 );
glVertex2f( 1000, 200 );
glVertex2f( 1000, 220);
glVertex2f( 0, 220);
glEnd();

//rasta red border
glBegin(GL_QUADS);
glColor3ub(144,79,62);
glVertex2f( 0,220 );
glVertex2f( 1000, 220 );
glVertex2f( 1000, 250);
glVertex2f( 0, 250);
glEnd();


//rasta aash2
glBegin(GL_QUADS);
glColor3ub(157,157,157);
glVertex2f( 0,250 );
glVertex2f( 1000, 250 );
glVertex2f( 1000, 360);
glVertex2f( 0, 360);
glEnd();

//grn border rasta
glBegin(GL_QUADS);
glColor3ub(95,123,39);
glVertex2f( 0,360 );
glVertex2f( 1000, 360 );
glVertex2f( 1000, 520);
glVertex2f( 0, 520);
glEnd();


//tree
    drawTree_S(100, 360);  // Adjust the coordinates as needed
    drawTree_S(300, 360);
    drawTree_S(500, 360);
    drawTree_S(700, 360);
    drawTree_S(900, 360);


//cha kha
//main
glBegin(GL_QUADS);
glColor3ub(161, 161, 161);
glVertex2f( 50,240 );
glVertex2f( 190, 240 );
glColor3ub(90,88,89);
glVertex2f( 190, 390);
glVertex2f( 50, 390);
glEnd();

//nicher border
glBegin(GL_QUADS);
glColor3ub(39,25,29);
glVertex2f( 50,240 );
glVertex2f( 190, 240 );
glVertex2f( 190, 255);
glVertex2f( 50, 255);
glEnd();

//red table
glBegin(GL_QUADS);
glColor3ub(86,48,39);
glVertex2f( 90,255 );
glVertex2f( 190, 255 );
glVertex2f( 190, 300);
glVertex2f( 90, 300);
glEnd();

//blk border side
glBegin(GL_QUADS);
glColor3ub(32,32,30);
glVertex2f( 80,255 );
glVertex2f( 90, 255 );
glVertex2f( 90, 300);
glVertex2f( 80, 290);
glEnd();
//side
glBegin(GL_QUADS);
glColor3ub(54,54,54);
glVertex2f( 20,240 );
glVertex2f( 50, 240 );
glVertex2f( 50, 390);
glVertex2f( 20, 350);
glEnd();


//roof
glBegin(GL_QUADS);
glColor3ub(191,91,67);
glVertex2f( 90,340 );
glVertex2f( 230, 340 );
glVertex2f( 190, 390);
glVertex2f( 50, 390);
glEnd();

//border1
glBegin(GL_QUADS);
glColor3ub(60,49,51);
glVertex2f( 90,220 );
glVertex2f( 96, 220 );
glVertex2f( 96, 340);
glVertex2f( 90, 340);
glEnd();

//board
glBegin(GL_QUADS);
glColor3ub(247, 247, 247);
glVertex2f( 50,390 );
glVertex2f( 190, 390 );
glVertex2f( 190, 450);
glVertex2f( 50, 450);
glEnd();


//border2
glBegin(GL_QUADS);
glColor3ub(60,49,51);
glVertex2f( 224,220 );
glVertex2f( 230, 220 );
glVertex2f( 230, 340);
glVertex2f( 224, 340);
glEnd();



//seu building
glBegin(GL_QUADS);
glColor3ub(231,232,227);
glVertex2f( 480,250 );
glVertex2f( 540, 250 );
glVertex2f( 540, 840);
glVertex2f( 480, 840);
glEnd();


//seu building
glBegin(GL_QUADS);
glColor3ub(231,232,227);
glVertex2f( 480,250 );
glVertex2f( 540, 250 );
glVertex2f( 540, 840);
glVertex2f( 480, 840);
glEnd();


//aashbuilding1
glBegin(GL_QUADS);
glColor3ub(140,177,194);
glVertex2f( 410,250 );
glVertex2f( 480, 250 );
glColor3ub(78, 111, 128);
glVertex2f( 480, 750);
glVertex2f( 410, 750);
glEnd();

//red building
glBegin(GL_QUADS);
glColor3ub(231,103,79);
glVertex2f( 325,250 );
glVertex2f( 373, 250 );
glVertex2f( 373, 770);
glVertex2f( 325, 770);
glEnd();

//aashbuilding2
glBegin(GL_QUADS);
glColor3ub(140,177,194);
glVertex2f( 370,250 );
glVertex2f( 410, 250 );
glColor3ub(78, 111, 128);
glVertex2f( 410, 730);
glVertex2f( 370, 730);
glEnd();

//seu side building1
glBegin(GL_QUADS);
glColor3ub(132,132,132);
glVertex2f( 540,250 );
glVertex2f( 590, 250 );
glVertex2f( 590, 840);
glVertex2f( 540, 800);
glEnd();

//seu side building2
glBegin(GL_QUADS);
glColor3ub(132,132,132);
glVertex2f( 590,250 );
glVertex2f( 620, 250 );
glVertex2f( 620, 840);
glVertex2f( 590, 840);
glEnd();

//aashbuilding inside
glBegin(GL_QUADS);
glColor3ub(48, 70, 77);
glVertex2f( 390,250 );
glVertex2f( 460, 250 );
glColor3ub(82, 120, 133);
glVertex2f( 460, 340);
glColor3ub(14,177,194);
glVertex2f( 390, 340);
glEnd();


drawCloud_Ss();
drawStudent_S(studentX, 260);
drawStreetLamp_SsGrid(250, 200, 1, 5, 300, 200);
drawWindow_SsGrid(380, 700, 25, 11, 3, 6, 10);
drawWindow_SsGrid1(330, 680,15 ,100 ,0.5 ,6, 3, 5, 15);
drawWindow_SsGrid2(485, 740,20 ,60 ,0.5 ,9, 3, 8, 18);
drawText_tong_S("Kuddus er tong",59,418);
drawText_SEU("SEU",491,800);
drawAirplane_S(airplaneX, airplaneY, 0.6f);
drawStudent(150,260);
drawBus_S(busX, busY, 0.7f);
drawCar_S(carX, carY, 0.8f);
drawText_flagS("Sir, Congratulations!!",airplaneX-250,airplaneY);
glFlush();


}

// Initialize OpenGL settings
void myInit() {
    glClearColor(128.0f / 255.0f, 0, 0, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1000, 0, 1000, -10.0, 10.0);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    if (currentSlide == 0) {
        display1();
    } else if (currentSlide == 1) {
            display2();
    }
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'm') {
        currentSlide = 0;  //
    } else if (key == 'n') {
        currentSlide = 1;  // switch to display1
    }
    glutPostRedisplay();  // request to redraw the screen
}

int main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 0);

	// Giving name to window
	glutCreateWindow("SEU");
    myInit();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);  // keypress handling

	//glutDisplayFunc(display2);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
}
