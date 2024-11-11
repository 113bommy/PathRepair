#include <bits/stdc++.h>
using namespace std;
double dp[1 << 20], p[20], ans[20];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &p[i]);
  }
  dp[0] = 1.0;
  for (int mask = 0; mask < (1 << n); mask++) {
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i))
        cnt++;
      else
        sum += p[i];
    }
    if (sum > 1e-9)
      for (int i = 0; i < n; i++)
        if (!(mask & (1 << i))) {
          dp[mask | (1 << i)] += dp[mask] * p[i] / sum;
        }
    if (cnt == k)
      for (int i = 0; i < n; i++)
        if (mask & (1 << i)) {
          ans[i] += dp[mask];
        }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] != 0.0) cnt++;
  }
  if (cnt < k) {
    for (int i = 0; i < n; i++) ans[i] = p[i] == 0.0 ? 0.0 : 1.0;
  }
  for (int i = 0; i < n; i++) {
    printf("%.9lf%c", ans[i], i == n ? '\n' : ' ');
  }
  return 0;
}
