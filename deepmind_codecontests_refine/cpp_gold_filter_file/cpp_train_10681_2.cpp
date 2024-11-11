#include <bits/stdc++.h>
using namespace std;
const int mn = 2510;
const double eps = 1e-8;
int n;
double x[mn], f, h, ans;
double calc(double x1, double x2) {
  double res, x3, x4;
  x3 = x1 * (f + h) / (f - h), x4 = x2 * (f + h) / (f - h);
  if (x1 - x4 < -eps && x3 - x2 < -eps) return (x1 + x3) * h;
  if (x1 - x4 > eps && x3 - x2 > eps) return (x2 + x4) * h;
  if (x1 + x2 - x3 - x4 > eps) swap(x1, x4), swap(x2, x3);
  res = (x1 + x2) * h;
  if (x4 - x1 > eps && x3 - x2 > eps) {
    double a = x4 - x1, b = x3 - x2, h1 = h * b / (a + b), h2 = h - h1;
    res += ((a + b) * h - b * h1 - a * h2) * 0.5;
  }
  return res;
}
int main() {
  scanf("%d%lf%lf", &n, &h, &f);
  int i, j;
  for (i = 1; i <= n + n; ++i) scanf("%lf", x + i);
  sort(x + 1, x + n + n + 1);
  double a, b;
  for (i = 1; i <= n; ++i) {
    a = x[i + i] - x[i + i - 1];
    b = a * (f + h) / (f - h);
    ans += 2 * h * (a + b);
  }
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      ans -= calc(x[i + i], x[j + j]) + calc(x[i + i - 1], x[j + j - 1]);
      ans += calc(x[i + i], x[j + j - 1]) + calc(x[i + i - 1], x[j + j]);
    }
  printf("%.10lf\n", ans);
  return 0;
}
