#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const long long maxn = 1e5 + 7;
const long long maxm = 1e6 + 7;
double pro;
double f[101][101];
int x[101], y[101];
int n, k, odds;
double dis(double x1, double x2, double y1, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool check(double r) {
  double p;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    double d = dis(x[i], x[0], y[i], y[0]);
    if (d <= r)
      p = 1;
    else
      p = exp(1 - d * d / (r * r));
    for (int j = 0; j <= n; j++) {
      f[i][j] = f[i - 1][j] * (1.0 - p);
      if (j > 0) f[i][j] += (f[i - 1][j - 1]) * p;
    }
  }
  double ans = 0;
  for (int i = k; i <= n; i++) {
    ans += f[n][i];
  }
  return (ans - pro >= eps);
}
double work() {
  double l = 0.0, r = 4000.0;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid - eps;
    else
      l = mid + eps;
  }
  return l;
}
int main() {
  scanf("%d", &n);
  scanf("%d%d%d%d", &k, &odds, &x[0], &y[0]);
  pro = (double)(1000 - odds) / 1000;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  printf("%.8lf", work());
  return 0;
}
