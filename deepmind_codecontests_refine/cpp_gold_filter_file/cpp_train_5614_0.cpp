//??????????????????????????????
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std;
typedef complex<double> Point;

namespace std {
  bool operator < (const Point& a, const Point& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

double cross(Point u, Point v) {
	return u.real() * v.imag() - u.imag() * v.real();
}

double dot(Point u, Point v) {
	return u.real() * v.real() + u.imag() * v.imag();
}

//Define : e_Re(???), e_Im(???)
//a -> b -> counter clockwise -> c ???  1
//a -> b -> clockwise -> c         ??? -1
//c--a--b  ???  2
//a--b--c  ??? -2
//a--b(=c) ???  0
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > 0) return 1;
	if (cross(b, c) < 0) return -1;
	if (dot(b, c) < 0) return 2;
	if (norm(b) < norm(c)) return -2;
	return 0;
}

//counter clockwise, ring buffer(ch[0] == ch[last])
vector<Point> convex_hull(vector<Point> points) {
	int n = points.size();
	int k = 0;
	vector<Point> ch(2 * n);
	
	sort(points.begin(), points.end());
	
	//lower hull
	for (int i = 0; i < n; i++) {
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], points[i]) <= 0) k--;
		ch[k] = points[i];
		k++;
	}
	
	//upper hull
	int low_k = k;
	for (int i = n - 1; i >= 0; i--) {
		while (k > low_k && ccw(ch[k - 2], ch[k - 1], points[i]) <= 0) k--;
		ch[k] = points[i];
		k++;
	}
	ch.resize(k);
	return ch;
}

//If line (a->b), (c->d) are hit with a point, return true.
bool is_hit_line(Point a, Point b, Point c, Point d) {
	double u = cross(b - a, c - a) * cross(b - a, d - a);
	double v = cross(d - c, a - c) * cross(d - c, b - c);
	if (u > 0 || v > 0) return false;
	if (u != 0 || v != 0) return true;
	
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);
	
	double eps = 1e-10;
	if (abs(d - a) + eps > abs(b - a) + abs(d - c)) return false;
	return true;
}

//poly1, poly2 is convex polygon.
bool is_hit(vector<Point> poly1, vector<Point> poly2) {
	for (int i = 0; i < (int)poly1.size() - 1; i++) {
		for (int j = 0; j < (int)poly2.size() - 1; j++) {
			if (is_hit_line(poly1[i], poly1[i + 1], poly2[j], poly2[j + 1])) {
				return true;
			}
		}
	}
	return false;
}

bool is_cover(vector<Point> poly, Point point) {
	bool in = false;
	for (int i = 0; i < (int)poly.size() - 1; i++) {
		Point a = poly[i] - point;
		Point b = poly[i + 1] - point;
		if (imag(a) > imag(b)) swap(a, b);
		if (imag(a) <= 0 && 0 < imag(b)) if (cross(a, b) < 0) in = !in;
		if (cross(a, b) == 0 && dot(a, b) <= 0) return false;	//on poly
	}
	return in;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (!n) break;
		
		vector<Point> poly1, poly2;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			poly1.push_back(Point((double)x, (double)y));
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			poly2.push_back(Point((double)x, (double)y));
		}
		poly1 = convex_hull(poly1);
		poly2 = convex_hull(poly2);
		
		if (is_hit(poly1, poly2) || is_cover(poly1, poly2[0]) || is_cover(poly2, poly1[0])) { cout << "NO" << endl; }
		else { cout << "YES" << endl; }
	}
	return 0;
}