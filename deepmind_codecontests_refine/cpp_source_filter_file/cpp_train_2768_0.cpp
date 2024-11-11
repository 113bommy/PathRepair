#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-6;
class Point {
 public:
  double x, y;
  Point() {}
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
  bool operator==(const Point &b) const {
    return (abs(x - b.x) < EPS and abs(y - b.y) < EPS);
  }
  bool operator<(const Point &b) const {
    return ((x < b.x) or ((x == b.x) and y < b.y));
  }
  double operator^(const Point &b) const {
    return (this->x * b.y) - (this->y * b.x);
  }
  double operator*(const Point &b) const {
    return (this->x * b.x) + (this->y * b.y);
  }
  Point operator*(double k) { return Point(x * k, y * k); }
  Point operator/(double k) {
    if (k == 0.0) cout << "Class Point (operador /): divisao por zero" << endl;
    return Point(x / k, y / k);
  }
  Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  double len() { return sqrt(x * x + y * y); }
  double dpp(const Point &b) { return ((*this) - b).len(); }
  double proj(Point &b) { return ((*this) * b) / (b.len() * b.len()); }
  Point norm() { return Point(x / this->len(), y / this->len()); }
  Point perp() { return Point(this->y, -1.0 * this->x); }
  double distToLine(const Point a, const Point b, Point &c) {
    Point p = *this;
    if (a == b) return p.dpp(a);
    Point ap = Point(p - a), ab = Point(b - a);
    double u = ap.proj(ab);
    if (u < 0.0) u = 0.0;
    if (u > 1.0) u = 1.0;
    c = a + ab * u;
    return p.dpp(c);
  }
};
ostream &operator<<(ostream &os, Point const &p) {
  return os << p.x << " " << p.y;
}
const int N = 1e3 + 3;
int n;
Point p[N];
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
  double res = 1e18;
  for (int i = 0; i < n; i++) {
    Point p1 = p[i], p2 = p[(i + 1) % n], p3 = p[(i + 2) % 2];
    Point lixo;
    res = min(res, p2.distToLine(p1, p3, lixo) / 2.0);
  }
  printf("%.13lf\n", res);
  return 0;
}
