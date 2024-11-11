#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
const double eps = 1e-6;
int n;
double h, f, x[maxn << 1];
int sgn(double v) {
  if (fabs(v) < eps) return 0;
  if (v > 0.0)
    return 1;
  else
    return -1;
}
double calc(double x1, double x2) {
  double x3 = x1 * (f + h) / (f - h), x4 = x2 * (f + h) / (f - h);
  if (sgn(x1 - x4) > 0 && sgn(x3 - x2) > 0) return (x4 + x2) * h;
  if (sgn(x4 - x1) > 0 && sgn(x2 - x3) > 0) return (x1 + x3) * h;
  if (sgn(x1 + x2 - x3 - x4) > 0) swap(x1, x4), swap(x2, x3);
  double s = h * (x1 + x2);
  double v1 = x4 - x1, v2 = x3 - x2;
  if (sgn(v1 + v2) > 0)
    s += (h * (v1 + v2) - v2 * h * v2 / (v1 + v2) - v1 * h * v1 / (v1 + v2)) /
         2.0;
  return s;
}
int main() {
  scanf("%d%lf%lf", &n, &h, &f);
  for (int a = 1; a <= n; a++) scanf("%lf%lf", &x[a * 2 - 1], &x[a * 2]);
  sort(x + 1, x + 2 * n + 1);
  double ans = 0.0;
  for (int a = 1; a <= n; a++) {
    double v1 = x[a * 2] - x[a * 2 - 1];
    double v2 = v1 * (f + h) / (f - h);
    ans += (v1 + v2) * h * 2;
  }
  for (int a = 1; a <= n; a++)
    for (int b = 1; b <= n; b++)
      ans += calc(x[a + a], x[b + b - 1]) + calc(x[a + a - 1], x[b + b]) -
             calc(x[a + a], x[b + b]) - calc(x[a + a - 1], x[b + b - 1]);
  printf("%.9lf\n", ans);
  return 0;
}
