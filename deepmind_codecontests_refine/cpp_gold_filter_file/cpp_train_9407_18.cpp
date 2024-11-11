#include <bits/stdc++.h>
double max(double a, double b) {
  if (a > b) return a;
  return b;
}
long long Y1, Y2, yw, xb, yb, r;
bool possible(double eps) {
  double ymax = Y1 - r - eps;
  double abs = sqrt((ymax - yb) * (ymax - yb) + xb * xb);
  double len = ((Y2 - yb) * xb - (ymax - yb) * xb) / abs;
  len = max(len, -len);
  return len > r;
}
double get_x() {
  double eps = 1;
  while (!possible(eps)) {
    eps /= 2;
  }
  double y = Y1 - r - eps;
  return xb * (y - yw) / (y - yb);
}
int main() {
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &Y1, &Y2, &yw, &xb, &yb, &r);
  Y2 = 2 * yw - Y2 - 2 * r;
  Y1 = 2 * yw - Y1 - 2 * r;
  yw -= r;
  if (!possible(1e-20)) {
    printf("-1\n");
    return 0;
  }
  printf("%.20f\n", get_x());
  fflush(stdin);
  getchar();
}
