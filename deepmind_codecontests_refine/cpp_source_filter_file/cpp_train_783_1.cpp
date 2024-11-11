#include <bits/stdc++.h>
const double eps = 1e-8;
const int maxn = 10000 + 500;
int n;
double w, u, v;
double x[maxn], y[maxn];
bool judge(double t) {
  for (int i = 1; i <= n; i++) {
    if (x[i] * u - y[i] * v - u * v * t > eps) return 0;
  }
  return 1;
}
int main() {
  scanf("%d %lf %lf %lf", &n, &w, &v, &u);
  for (int i = 1; i <= n; i++) scanf("%lf %lf", &x[i], &y[i]);
  bool f = 1;
  for (int i = 1; i <= n; i++) {
    if (x[i] * u - y[i] * v < eps) {
      f = 0;
      break;
    }
  }
  if (f) {
    printf("%.9lf", w / u);
    return 0;
  }
  double l = 0, r = 1e9;
  while (r - l > eps) {
    double mid = (l + r) / 2.0;
    if (judge(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.9lf", w / u + r);
  return 0;
}
