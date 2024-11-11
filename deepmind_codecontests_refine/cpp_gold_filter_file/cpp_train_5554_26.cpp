#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-10;
int xp, yp, vp, x, y, v, r;
double R;
double getmin(double a, double b) { return a < b ? a : b; }
double sqr(double a) { return a * a; }
void init() {
  scanf("%d%d%d", &xp, &yp, &vp);
  scanf("%d%d%d%d", &x, &y, &v, &r);
  R = sqrt(sqr(xp) + sqr(yp));
}
double dist(double x1, double y1, double x2, double y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
void getpos(double t, double &ax, double &ay) {
  double ag = atan2(double(yp), double(xp)) + double(t * vp) / R;
  ax = cos(ag) * R;
  ay = sin(ag) * R;
}
double ang(double l1, double l2, double l0) {
  return (sqr(l1) + sqr(l2) - sqr(l0)) / (2.0 * l1 * l2);
}
double to(double ax, double ay) {
  double l1 = sqrt(sqr(x) + sqr(y) - sqr(r)),
         l2 = sqrt(sqr(ax) + sqr(ay) - sqr(r)), l0 = dist(x, y, ax, ay);
  if (l1 + l2 > l0)
    return l0;
  else {
    double d1 =
        acos(ang(dist(x, y, 0, 0), dist(ax, ay, 0, 0), dist(x, y, ax, ay)));
    double d2 = acos(double(r) / dist(x, y, 0, 0));
    double d3 = acos(double(r) / dist(ax, ay, 0, 0));
    double d = d1 - d2 - d3;
    return l1 + l2 + d * r;
  }
}
void work() {
  double lower = 0.0, upper = 100000000.0;
  for (int i = 0; i < 100000; ++i) {
    double ax, ay, mid = (lower + upper) * 0.5;
    getpos(mid, ax, ay);
    if (to(ax, ay) < mid * v)
      upper = mid;
    else
      lower = mid;
  }
  double ans = lower;
  printf("%.9lf\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
