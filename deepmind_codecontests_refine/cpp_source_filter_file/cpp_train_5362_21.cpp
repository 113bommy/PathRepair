#include <bits/stdc++.h>
using namespace std;
double sqr(double x) { return x * x; }
int main() {
  double x0, y0, x1, y1, dx, dy;
  scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y1);
  dx = x1 - x0, dy = y1 - y0;
  double vm, t;
  scanf("%lf %lf", &vm, &t);
  double u1, v1, u2, v2;
  scanf("%lf %lf %lf %lf", &u1, &v1, &u2, &v2);
  double dist = sqrt(sqr(x1 - x0) + sqr(y1 - y0));
  double l1 = sqrt(sqr(u1) + sqr(v1));
  double l2 = sqrt(sqr(u2) + sqr(v2));
  if (dist < 1e-10) {
    printf("%.10f\n", 0.0);
    return 0;
  }
  {
    double vx = (u1 * dx + v1 * dy) / dist;
    double vy = fabs((u1 * dy - v1 * dx) / dist);
    vx += sqrt(sqr(vm) - sqr(vy));
    double t1 = dist / vx;
    if (t1 <= t + 1e-7) {
      printf("%f\n", t1);
      return 0;
    }
  }
  {
    dx -= u1 * t, dy -= v1 * t;
    double l = 0.0, r = 100000.0;
    for (int i = 0; i < 100; i++) {
      double m = (l + r) / 2.0;
      double tx = dx - m * u2, ty = dy - m * v2;
      if (sqrt(sqr(tx) + sqr(ty)) > vm * (t + m))
        l = m;
      else
        r = m;
    }
    printf("%.10f\n", t + l);
  }
  return 0;
}
