#include <bits/stdc++.h>
using namespace std;
const int maxn = 20050, maxp = 800050, big = 1e8;
const double eps = 1e-10, PI = acos(-1);
int dcmp(double x) {
  if (x > eps)
    return 1;
  else if (x < -eps)
    return -1;
  return 0;
}
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  void scan() { scanf("%lf%lf", &x, &y); }
};
Point O = Point(0, 0);
Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
Point operator*(Point A, double k) { return Point(A.x * k, A.y * k); }
Point operator/(Point A, double k) { return Point(A.x / k, A.y / k); }
double Len(Point A) { return A.x * A.x + A.y * A.y; }
double Ang(Point A) { return atan2(A.y, A.x); }
struct Circle {
  Point p;
  double r;
  Circle() {}
  Circle(Point p, double r) : p(p), r(r) {}
  void scan() { p.scan(), scanf("%lf", &r); }
} c[maxn];
int n, d, ps = 0, ans = 0;
struct Inter {
  double rad;
  int p;
  Inter() {}
  Inter(double rad, int p) : rad(rad), p(p) {}
  bool operator<(const Inter &yy) const {
    return !dcmp(rad - yy.rad) ? p > yy.p : dcmp(rad - yy.rad) < 0;
  }
} po[maxp];
void CirCirInter(Circle c1, Circle c2) {
  Point v = c2.p - c1.p;
  double d = sqrt(Len(v)), ang = Ang(v),
         rad = acos((d * d + c1.r * c1.r - c2.r * c2.r) / c1.r / d / 2);
  po[ps++] = Inter(ang - rad, 1);
  po[ps++] = Inter(ang + rad, -1);
}
int main() {
  int i, j;
  scanf("%d%d", &n, &d);
  for (i = 0; i < n; i++) {
    c[i].scan();
    double dis = Len(c[i].p);
    int lo = (sqrt(dis) - c[i].r - eps) / d + 1, hi = (sqrt(dis) + c[i].r) / d;
    for (j = max(lo, 1); j <= hi; j++) CirCirInter(Circle(O, j * d), c[i]);
  }
  sort(po, po + ps);
  for (i = j = 0; i < ps; i++) j += po[i].p, ans = max(ans, j);
  printf("%d\n", ans);
  return 0;
}
