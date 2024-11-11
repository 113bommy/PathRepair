#include <bits/stdc++.h>
using namespace std;
long long dp[1005][105];
long long d[1005];
int main() {
  int n, k;
  long long m;
  scanf("%d%d%I64d", &n, &k, &m);
  d[1] = 1;
  for (int i = 2; i <= n; i++) (d[i] = d[i - 1] * 10) %= k;
  for (int i = 1; i <= 9; i++) {
    (dp[1][i % k] += 1) %= m;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j) (dp[i][d[i] * j % k] += 1) %= m;
      for (int h = 0; h < k; h++) {
        if (h == 0) {
          (dp[i][0] += dp[i - 1][h]) %= m;
        } else {
          (dp[i][(d[i] * j + h) % k] += dp[i - 1][h]) %= m;
        }
      }
    }
  }
  long long ans = (dp[n][0] - dp[n - 1][0] + m) % m;
  printf("%I64d\n", ans);
  return 0;
}
