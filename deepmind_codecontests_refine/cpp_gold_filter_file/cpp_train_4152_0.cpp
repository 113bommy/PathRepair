#include <iostream>
#include <stdio.h>
#include <complex>
#include <cmath>
using namespace std;
typedef complex<double> xy_t;


double dot_product(xy_t a, xy_t b){
        return (conj(a)*b).real();
}

double cross_product(xy_t a, xy_t b){
        return (conj(a)*b).imag();
}
int main(){
        xy_t o,a,b;
        double sum = 0,x,y;
        scanf("%lf,%lf", &x, &y);
        o = xy_t (x, y);
        scanf("%lf,%lf", &x, &y);
        a = xy_t (x, y) - o;
        b = a;
        while(~scanf("%lf,%lf", &x, &y)){
                a = xy_t (x, y) - o;
                sum += cross_product(a,b) / 2.0;
                b = a;
        }
        printf("%.6f\n", abs(sum));
return 0;
}