#include <bits/stdc++.h>
const int N = 100 + 10;
int n, k, x[N], y[N];
double e, p[N];
const double eps = 1e-12;
bool check(double r) {
  for (int i = (int)0, _y = n; i <= _y; i++) p[i] = 0;
  p[0] = 1;
  r *= r;
  for (int i = (int)1, _y = n; i <= _y; i++) {
    double d = (x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]),
           _ = r - d > eps ? 1 : exp(1 - d / r);
    for (int j = (int)i - 1, _y = 0; j >= _y; j--)
      p[j + 1] += p[j] * _, p[j] *= 1 - _;
  }
  for (int i = (int)1, _y = k - 1; i <= _y; i++) p[0] += p[i];
  return e - p[0] > eps;
}
int main() {
  scanf("%d%d%lf", &n, &k, &e);
  e /= 1000;
  for (int i = (int)0, _y = n; i <= _y; i++) scanf("%d%d", &x[i], &y[i]);
  double l = 0, r = 10000, mid;
  for (; r - l > eps;)
    if (check(mid = (l + r) / 2))
      r = mid;
    else
      l = mid;
  printf("%.15lf\n", (l + r) / 2);
}
