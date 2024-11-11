#include <bits/stdc++.h>
using namespace std;
const int MaxN = 10005;
const double eps = 1e-8;
struct Point {
  double x, y, z;
  Point() {}
  Point(double x, double y, double z) : x(x), y(y), z(z) {}
  Point operator+(const Point& p) const {
    return Point(x + p.x, y + p.y, z + p.z);
  }
  Point operator-(const Point& p) const {
    return Point(x - p.x, y - p.y, z - p.z);
  }
  Point operator*(const double& d) const { return Point(x * d, y * d, z * d); }
  Point operator/(const double& d) const { return Point(x / d, y / d, z / d); }
  double norm() const { return sqrt(x * x + y * y + z * z); }
  Point getOne() {
    Point ret = *this;
    ret = ret / norm();
    return ret;
  }
  void init() { scanf("%lf%lf%lf", &x, &y, &z); }
} p[MaxN], o;
double vp, vs;
double maxD;
int n;
Point getP(double t) {
  int pt = 0;
  double tmp;
  while (pt < n) {
    tmp = (p[pt + 1] - p[pt]).norm() / vs;
    if (t > tmp) {
      t -= tmp;
      pt++;
    } else {
      return p[pt] + (p[pt + 1] - p[pt]).getOne() * vs * t;
    }
  }
  return p[n];
}
void doit() {
  double l = 0, r = maxD, mid;
  Point d;
  if ((p[n] - o).norm() / vp - r > eps) {
    puts("NO");
    return;
  }
  for (int i = 0; i < 100; i++) {
    mid = (l + r) / 2.0;
    d = getP(mid);
    if ((d - o).norm() / vp - mid < eps) {
      r = mid;
    } else {
      l = mid;
    }
  }
  puts("YES");
  printf("%.10f\n", r);
  d = getP(r);
  printf("%.10f %.10f %.10f\n", d.x, d.y, d.z);
}
int main() {
  while (scanf("%d", &n) == 1) {
    maxD = 0;
    for (int i = 0; i <= n; i++) {
      p[i].init();
      if (i) maxD += (p[i] - p[i - 1]).norm();
    }
    scanf("%lf%lf", &vp, &vs);
    maxD /= vs;
    o.init();
    doit();
  }
  return 0;
}
