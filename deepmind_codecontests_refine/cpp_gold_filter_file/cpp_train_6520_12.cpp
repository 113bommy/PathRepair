#include <bits/stdc++.h>
using namespace std;
void dbg(char* fmt, ...) {}
const double INF = 1e100;
const double eps = 1e-10;
struct Point {
  double x, y, z;
  Point() {}
  Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
  void read() { scanf("%lf%lf%lf", &x, &y, &z); }
  Point operator+(const Point& p) const {
    return Point(x + p.x, y + p.y, z + p.z);
  }
  Point operator-(const Point& p) const {
    return Point(x - p.x, y - p.y, z - p.z);
  }
  Point operator*(double k) const { return Point(x * k, y * k, z * k); }
  double operator%(const Point& p) const { return x * p.x + y * p.y + z * p.z; }
  double abs() const { return sqrt((*this) % (*this)); }
  Point operator*(const Point& p) const {
    double xx = y * p.z - z * p.y;
    double yy = z * p.x - x * p.z;
    double zz = x * p.y - y * p.x;
    return Point(xx, yy, zz);
  }
};
Point A, v;
int R;
double resT;
double solveSq(double a, double b, double c) {
  dbg("%.4lf %.4lf %.4lf\n", a, b, c);
  double d = b * b - 4 * a * c;
  if (d < -eps) {
    dbg("no roots\n");
    return INF;
  }
  if (d < 0) d = 0;
  d = sqrt(d);
  double t1 = (-b - d) / (2 * a);
  double t2 = (-b + d) / (2 * a);
  if (t1 > t2) swap(t1, t2);
  dbg("%.5lf %.5lf\n", t1, t2);
  if (t1 > 0) return t1;
  if (t2 > 0) return t2;
  return INF;
}
double findDistToPoint(Point p, double r) {
  p = A - p;
  double a = v % v;
  double b = 2 * (v % p);
  double c = p % p - r * r;
  return solveSq(a, b, c);
}
double findDistToLine(Point p1, Point p2, double d) {
  Point p = p2 - p1;
  Point k = v * p;
  Point l = (A - p1) * p;
  double a = k % k;
  double b = 2 * (k % l);
  double c = l % l - d * d * (p % p);
  return solveSq(a, b, c);
}
void checkCircle(Point O, double r) {
  double t = findDistToPoint(O, r + R);
  resT = min(resT, t);
}
bool touch(Point p1, Point p2, Point O, double R) {
  double t = ((O - p1) % (p2 - p1)) / ((p2 - p1) % (p2 - p1));
  return (0 <= t && t <= 1);
}
void checkSegment(Point O, Point p) {
  double t1 = findDistToPoint(O + p, R);
  resT = min(resT, t1);
  double t2 = findDistToLine(O, O + p, R);
  if (touch(O, O + p, A + v * t2, R)) resT = min(resT, t2);
}
int main() {
  A.read();
  v.read();
  scanf("%d", &R);
  int n;
  resT = INF;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    Point O;
    O.read();
    int r;
    scanf("%d", &r);
    checkCircle(O, r);
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; ++j) {
      Point p;
      p.read();
      checkSegment(O, p);
    }
  }
  if (fabs(resT - INF) < eps)
    printf("-1\n");
  else
    printf("%.15lf\n", resT);
  return 0;
}
