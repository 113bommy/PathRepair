#include<iostream>
using namespace std;
#include<cstdio>
#include<complex>

typedef double type_n;
typedef complex<type_n> point;

int main()
{
    point a, b, c, z, h, w;
    int i, q;
    type_n a1, a2, b1, b2, z1, z2;
    scanf("%lf %lf %lf %lf", &a1, &a2, &b1, &b2);
    a.real(a1), a.imag(a2), b.real(b1), b.imag(b2);
    c = b - a;

    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%lf %lf", &z1, &z2);
        z.real(z1), z.imag(z2);
        h = a + c * (((z - a) / c).real());
        w = 2 * h - z;
        printf("%.12f %.12f\n", w.real(), w.imag());
    }
    return 0;
}