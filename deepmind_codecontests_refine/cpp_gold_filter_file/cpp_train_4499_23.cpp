#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  long long f[100];
  f[1] = 1;
  f[2] = 2;
  int cnt;
  for (cnt = 3;; cnt++) {
    f[cnt] = f[cnt - 1] + f[cnt - 2];
    if (f[cnt] > 1e18) break;
  }
  while (t--) {
    long long n;
    scanf("%I64d", &n);
    long long b[100], x = 0;
    for (int i = cnt - 1; n && i >= 1; i--)
      if (n >= f[i]) {
        b[x++] = i;
        n -= f[i];
      }
    long long dp[100][2];
    dp[x - 1][1] = 1;
    dp[x - 1][0] = (b[x - 1] - 1) / 2;
    for (int i = x - 2; i >= 0; i--) {
      dp[i][1] = dp[i + 1][1] + dp[i + 1][0];
      dp[i][0] = dp[i + 1][1] * ((b[i] - b[i + 1] - 1) / 2) +
                 dp[i + 1][0] * ((b[i] - b[i + 1]) / 2);
    }
    printf("%I64d\n", dp[0][0] + dp[0][1]);
  }
  return 0;
}
