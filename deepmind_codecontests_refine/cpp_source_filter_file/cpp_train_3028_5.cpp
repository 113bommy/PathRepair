#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main () {
    double a, b, x, y;
    int C;
    cin >> a >> b >> C;
    x = cos(M_PI*C/180)*b*tan(M_PI*C/180);
    y = a-cos(M_PI*C/180)*b;
    printf("%.8f %.8f %.8f\n", sin(M_PI*C/180)*a*b/2, a+b+hypot(x,y) , x)
}