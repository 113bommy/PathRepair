#ifndef ___Geometry_Library
#define ___Geometry_Library

// ------ Includes ------ //
#include <cmath>
#include <complex>
#include <utility>
#include <algorithm>

// ------ Defines ------ //
typedef long double GType;
typedef std::complex<GType> Point;
typedef std::pair<Point, Point> Segment;

// ------ Constants ------ //
const GType EPS = 1.0e-10L;

// ------ Functions Level 1 ------ //
GType dot(const Point& p1, const Point& p2) {
	return (std::conj(p1) * p2).real();
}
GType cross(const Point& p1, const Point& p2) {
	return (std::conj(p1) * p2).imag();
}
int ccw(const Point& p1, const Point& p2, const Point& p3) {
	Point v1 = p2 - p1, v2 = p3 - p1;
	if (cross(v1, v2) > EPS) return +1;
	if (cross(v1, v2) < -EPS) return -1;
	if (dot(v1, v2) < -EPS) return +2;
	if (std::norm(v1) < std::norm(v2)) return -2;
	return 0;
}

#endif

#include <iomanip>
#include <iostream>
using namespace std;
int q, xa, ya, xb, yb; Point p1, p2, p3;
int main() {
	cin >> xa >> ya >> xb >> yb;
	p1 = Point(xa, ya);
	p2 = Point(xb, yb);
	cin >> q;
	while (q--) {
		cin >> xa >> ya; p3 = Point(xa, ya);
		int res = ccw(p1, p2, p3);
		if(res == +1) cout << "COUNTER_CLOCKWISE" << endl;
		if(res == -1) cout << "CLOCKWISE" << endl;
		if(res == +2) cout << "ONLINE_BACK" << endl;
		if(res == -2) cout << "ONLINE_FRONT" << endl;
		if(res == +0) cout << "ON_SEGMENT" << endl;
	}
	return 0;
}