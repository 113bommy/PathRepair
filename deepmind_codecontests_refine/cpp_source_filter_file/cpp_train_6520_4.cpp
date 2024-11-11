#include <bits/stdc++.h>
using namespace std;
double x0, y2, z0, vx, vy, vz, R;
double root(double x, double y, double z, double r) {
  double a = (vx * vx) + (vy * vy) + (vz * vz);
  double b = 2 * ((x0 - x) * vx + (y2 - y) * vy + (z0 - z) * vz);
  double c = (x - x0) * (x - x0) + (y - y2) * (y - y2) + (z - z0) * (z - z0) -
             (R + r) * (R + r);
  double d = b * b - 4 * a * c;
  if (d < 0) return 10000000.0;
  double x1 = (-b - sqrt(d)) / (2 * a), x2 = (-b + sqrt(d)) / (2 * a);
  double mi = min(x1, x2), ma = max(x1, x2);
  if (x1 < 0) {
    if (x2 < 0)
      return 10000000.0;
    else
      return x2;
  }
  return x1;
}
int main() {
  while (scanf("%lf%lf%lf%lf%lf%lf%lf", &x0, &y2, &z0, &vx, &vy, &vz, &R) !=
         EOF) {
    int n, m;
    scanf("%d", &n);
    double px, py, pz, r, ans = 20000000.0, ox, oy, oz;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf%d", &ox, &oy, &oz, &r, &m);
      ans = min(ans, root(ox, oy, oz, r));
      for (int j = 0; j < m; j++) {
        scanf("%lf%lf%lf", &px, &py, &pz);
        px += ox;
        py += oy;
        pz += oz;
        ans = min(ans, root(px, py, pz, 0));
      }
    }
    if (ans >= 10.0)
      printf("-1\n");
    else
      printf("%.6lf\n", ans);
  }
  return 0;
}
