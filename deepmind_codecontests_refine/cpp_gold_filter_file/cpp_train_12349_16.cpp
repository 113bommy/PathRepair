#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[51], b[51], p[51];
double f[55][5001];
bool Check(double k) {
  int sum = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) f[i][j] = 1e18;
  }
  for (int i = n; i >= 1; i--) {
    sum += a[i];
    for (int j = m; j >= sum; j--) {
      if (j >= b[i]) {
        f[i][j] = 1.0 * p[i] / 100.0 * (min(f[i + 1][j - a[i]], k) + a[i]) +
                  (1.0 - p[i] / 100.0) * (min(f[i + 1][j - b[i]], k) + b[i]);
      } else {
        f[i][j] = 1.0 * p[i] / 100.0 * (min(f[i + 1][j - a[i]], k) + a[i]) +
                  (1.0 - p[i] / 100.0) * (k + b[i]);
      }
    }
  }
  return f[1][m] < k;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &p[i]);
  }
  double x = 0.0, y = 2e9;
  while (x + 1e-8 < y) {
    double mid = (x + y) / 2;
    if (Check(mid))
      y = mid;
    else
      x = mid;
  }
  printf("%.9lf", y);
  return 0;
}
