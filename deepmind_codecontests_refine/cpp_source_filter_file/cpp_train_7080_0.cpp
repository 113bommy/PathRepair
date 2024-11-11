#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
 
#define rad(x) (x*atan(1.0)*4.0/180.0)
int n;
 
void koch( double x1, double y1, double x4, double y4, int d ){
    if( d == n ){
        printf("%.5lf %.5lf\n", x4, y4);
        return;
    }
    double x2 = (x4-x1) / 3.0 + x1;
    double y2 = (y4-y1) / 3.0 + y1;
    double x3 = (x4-x1) * 2.0 / 3.0 + x1;
    double y3 = (y4-y1) * 2.0 / 3.0 + y1;
    double x = (x3-x2)/2 - (y3-y2)*sqrt(3)/2 + x2;
    double y = (x3-x2*sqrt(3)/2 + (y3-y2)/2 + y2;
    koch( x1, y1, x2, y2, d+1 );
    koch( x2, y2, x,  y,  d+1 );
    koch( x,  y,  x3, y3, d+1 );
    koch( x3, y3, x4, y4, d+1 );
}
 
int main(){
    cin >> n;
    cout << "0.00000 0.00000" << endl;
    koch(0.0,0.0,100.0,0.0,0);
    return 0;
}