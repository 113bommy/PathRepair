#include <bits/stdc++.h>
int main() {
  double vx, vy;
  double px, py, a, b, c, d;
  double len, vxn, vyn;
  double x[8], y[8];
  scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &px, &py, &vx, &vy, &a, &b, &c, &d);
  len = sqrt(vx * vx + vy * vy);
  vxn = vx / len;
  vyn = vy / len;
  x[1] = b * vxn + px;
  y[1] = b * vyn + py;
  x[2] = -a / 2 * vyn + px;
  y[2] = a / 2 * vxn + py;
  x[7] = a / 2 * vyn + px;
  y[7] = -a / 2 * vxn + py;
  x[3] = -c / 2 * vyn + px;
  y[3] = c / 2 * vxn + py;
  x[6] = c / 2 * vyn + px;
  y[6] = -c / 2 * vxn + py;
  x[4] = x[3] - d * vxn;
  y[4] = y[3] - d * vyn;
  x[5] = x[6] - d * vxn;
  y[5] = y[6] - d * vyn;
  for (int i = 1; i <= 7; i++) printf("%lf %lf\n", x[i], y[i]);
  return 0;
}
