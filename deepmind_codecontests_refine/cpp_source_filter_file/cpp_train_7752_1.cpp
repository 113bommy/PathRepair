#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, e, x[101], y[101];
  scanf("%d%d%d", &n, &m, &e);
  for (int i = 0; i <= n; i++) scanf("%d%d", x + i, y + i);
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (x[i] == x[0] && y[i] == y[0]) cnt++;
  if (cnt >= m) return puts("0");
  double lo = 0, hi = 2000;
  for (int i = 0; i < 100; i++) {
    double r = (lo + hi) / 2;
    double dp[101] = {1};
    for (int i = 1; i <= n; i++) {
      double d = (x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]);
      double p = d > r * r ? exp(1 - d / r / r) : 1;
      for (int k = i; k >= 0; k--) dp[k] = dp[k - 1] * p + dp[k] * (1 - p);
    }
    double sum = 0;
    for (int i = m; i <= n; i++) sum += dp[i];
    if (sum * 1000 >= 1000 - e)
      hi = r;
    else
      lo = r;
  }
  printf("%.14f\n", lo);
}
