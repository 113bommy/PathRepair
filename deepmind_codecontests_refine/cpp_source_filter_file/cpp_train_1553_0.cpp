include<iostream>
#include<cstdio>
#include<complex>
#include<cmath>
using namespace std;typedef double elem;typedef complex<elem> point,vec;
const elem eps=1.0e-8;
#define ERR 0x00
#define FRONT 0x01
#define RIGHT 0x02
#define BACK 0x04
#define LEFT 0x08
#define OVER 0x10
point origin(0,0);bool eq(elem a, elem b){ return abs(a-b) < eps; }bool lt(elem a, elem b){ return !eq(a,b) && a < b; }bool leq(elem a, elem b){ return eq(a,b) || a < b; }bool gt(elem a, elem b){ return !eq(a,b) && a > b; }bool geq(elem a, elem b){ return eq(a,b) || a > b; }bool ltz(elem a){ return lt( a, 0 ); }bool gtz(elem a){ return gt( a, 0 ); }elem cross(vec a, vec b){ return ( a.real() * b.imag() - a.imag() * b.real() ); }elem dist(point a, point b){ return abs(a-b); }int ccw(point a, point b, point x){vec vb = b - a;vec vx = x - a;elem z = cross( vb, vx );if( eq(abs(vb),0) )return ERR;if( eq(z,0) ){elem d_ab = dist(a,b);elem d_bx = dist(b,x);elem d_ax = dist(a,x);if( eq(d_ab,d_ax+d_bx) )return OVER;if( gt( d_ax, d_ab ) && gt( d_ax, d_bx ) )return FRONT;if( gt( d_bx, d_ab ) && gt( d_bx, d_ax ) )return BACK;}else if( gtz( z ) )return LEFT;else if( ltz( z ) )return RIGHT;return ERR;}int main(){while(true){double D,px,py,vx,vy;scanf("%lf",&D);if(D==0)break;scanf("%lf%lf%lf%lf",&px,&py,&vx,&vy);point p(px,py);vec v(vx,vy);int progress = ccw(p,p+v,origin);double going = -1;if(progress&(FRONT|OVER)&&leq(dist(p,origin),D))going=dist(p,origin);else if(progress&BACK&&leq(2-dist(p,origin),D))going=2-dist(p,origin);if(gtz(going))printf("%.6lf\n",going);else puts("impossible");}return 0;}