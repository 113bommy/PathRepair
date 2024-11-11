#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// ------ Classes ------ //
class Point {
public:
	long double px, py;
	Point() : px(0), py(0) {};
	Point(long double px_, long double py_) : px(px_), py(py_) {};
	friend bool operator==(const Point& p1, const Point& p2) { return p1.px == p2.px && p1.py == p2.py; }
	friend bool operator!=(const Point& p1, const Point& p2) { return p1.px != p2.px || p1.py != p2.py; }
	friend bool operator<(const Point& p1, const Point& p2) { return p1.px < p2.px ? true : (p1.px == p2.px && p1.py < p2.py); }
	friend bool operator>(const Point& p1, const Point& p2) { return p1.px > p2.px ? true : (p1.px == p2.px && p1.py > p2.py); }
	friend bool operator<=(const Point& p1, const Point& p2) { return !(p1 > p2); }
	friend bool operator>=(const Point& p1, const Point& p2) { return !(p1 < p2); }
	friend Point operator+(const Point& p1, const Point& p2) { return Point(p1.px + p2.px, p1.py + p2.py); }
	friend Point operator-(const Point& p1, const Point& p2) { return Point(p1.px - p2.px, p1.py - p2.py); }
	friend Point operator*(const Point& p1, long double d) { return Point(p1.px * d, p1.py + d); }
	friend Point operator*(long double d, const Point& p1) { return p1 * d; }
	friend Point operator/(const Point& p1, long double d) { return Point(p1.px / d, p1.py / d); }
	Point& operator+=(const Point& p1) { px += p1.px; py += p1.py; return *this; }
	Point& operator-=(const Point& p1) { px -= p1.px; py -= p1.py; return *this; }
	Point& operator*=(long double d) { px *= d; py *= d; return *this; }
	Point& operator/=(long double d) { px /= d; py /= d; return *this; }
};
// ------ Functions ------ //
long double norm(const Point& a) { return a.px * a.px + a.py * a.py; }
long double abs(const Point& a) { return sqrtl(norm(a)); }
long double dot(const Point& a, const Point& b) { return a.px * b.px + a.py * b.py; }
long double crs(const Point& a, const Point& b) { return a.px * b.py - a.py * b.px; }
long double area(vector<Point> v) {
	long double ret = 0.0L;
	for (int i = 0; i < v.size(); i++) ret += crs(v[i], v[(i + 1) % v.size()]);
	return ret / 2;
}
// ------ Main ------ //
int n, c; vector<Point> v;
int main() {
	while(scanf("%d", &n), n) {
		p.resize(n);
		for(int i = 0; i < n; i++) cin >> v[i].px >> v[i].py;
		printf("%d %.2f\n", ++c, area(v));
	}
}