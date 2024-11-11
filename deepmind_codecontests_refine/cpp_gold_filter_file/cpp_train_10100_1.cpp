#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<cstring>
#include<queue>
#include<complex>
using namespace std;

typedef complex<double> P;

struct L : public vector<P>{
    L(const P &a, const P &b){
        push_back(a), push_back(b);
    }
};

struct C {
    P p; double r;
    C(const P &p, double r) : p(p), r(r) { }
};

const double EPS = 1e-8;

namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

void crossPointsOfCircleAndLine(C &circle, L &l){
    P p0 = circle.p;
    double r = circle.r;
    P p1 = l[0];
    P p2 = l[1];
    double x = real(p1-p0);
    double y = imag(p1-p0);
    double z = real(p2-p0);
    double w = imag(p2-p0);
    double a = y-w;
    double b = -(x-z);
    double c = y*z - x*w;

    P cross1((a*c - b*sqrt((a*a+b*b)*r*r - c*c))/(a*a + b*b), (b*c + a*sqrt((a*a+b*b)*r*r - c*c))/(a*a + b*b));
    P cross2((a*c + b*sqrt((a*a+b*b)*r*r - c*c))/(a*a + b*b), (b*c - a*sqrt((a*a+b*b)*r*r - c*c))/(a*a + b*b));

    if(cross2 < cross1){
        swap(cross1, cross2);
    }
    printf("%.10f %.10f ", cross1.real() + p0.real(), cross1.imag() + p0.imag());
    printf("%.10f %.10f\n", cross2.real() + p0.real(), cross2.imag() + p0.imag());
}

int main(){
    double cx, cy, r, x1, y1, x2, y2;
    int q;
    cin >> cx >> cy >> r >> q;
    P p0(cx, cy);
    C circle(p0, r);

    for (int i=0;i<q;i++){
        cin >> x1 >> y1 >> x2 >> y2 ;
        P p1(x1, y1);
        P p2(x2, y2);
        L l(p1, p2);
        crossPointsOfCircleAndLine(circle, l);
    }
    return 0;
}