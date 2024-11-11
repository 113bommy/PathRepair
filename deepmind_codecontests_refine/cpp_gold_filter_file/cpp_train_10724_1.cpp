#include <iostream>
#include <complex>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	typedef complex<double> com;
	double s = 0.0;
	int n, x0, y0, x1, y1, x2, y2;
	cin >> n >> x0 >> y0 >> x1 >> y1;
	for ( int i = 0; i < n - 2; i++ ) {
		cin >> x2 >> y2;
		s += ( conj( com( x1 - x0, y1 - y0 ) ) * com( x2 - x0, y2 - y0 ) ).imag() * 0.5;
		x1 = x2;
		y1 = y2;
	}
	printf( "%.1f\n", s );
}