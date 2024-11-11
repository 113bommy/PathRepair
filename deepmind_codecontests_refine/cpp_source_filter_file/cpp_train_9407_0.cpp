#include <bits/stdc++.h>
int main() {
  double y1, y2, yw, xb, yb, r, x, y, d;
  scanf("%lf%lf%lf%lf%lf%lf", &y1, &y2, &yw, &xb, &yb, &r);
  y = y1 + r;
  x = xb - (yw - r - yb) * xb / 2 / (yw - r - y1);
  d = ((y2 - y1 - r) * (y2 - y1 - r)) /
      (((x) * (x)) + ((yw - r - y1 - r) * (yw - r - y1 - r))) * ((x) * (x));
  if (d < r * r - 1e-10)
    printf("-1\n");
  else
    printf("%.10f\n", x);
  return 0;
}
