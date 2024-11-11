#include <iostream>
#include <complex>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	typedef complex<double> xy;
	xy p[20];
	int n = 0;
	double x, y, s;
	while ( ~scanf( "%lf, %lf", &x, &y ) ) {
		p[n++] = xy( x, y );
	}
	for ( int i = 1; i < n - 1; i++ ) {
		s += ( conj( p[i] - p[0] ) * ( p[i + 1] - p[0] ) ).imag() / 2;
	}
	printf( "%.6f\n", abs(s) );
}