#include <bits/stdc++.h>
int main() {
  double yw, x, y, r, y1, y2, as, asy;
  double a, b, o, u, v;
  scanf("%lf%lf%lf%lf%lf%lf", &y1, &y2, &yw, &x, &y, &r);
  a = yw - y1 - 2 * r;
  b = yw - r - y;
  if (a < -1e-10 || b < -1e-10) {
    puts("-1");
    return 0;
  }
  as = a * x / (a + b);
  u = sqrt((x - as) * (x - as) + b * b);
  if (r * u > (y2 - y1 - r) * (x - as)) {
    puts("-1");
    return 0;
  }
  printf("%.10lf\n", as);
  return 0;
}
