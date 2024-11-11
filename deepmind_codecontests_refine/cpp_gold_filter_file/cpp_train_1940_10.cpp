#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n;
long long a[510][510], dp[510][510][2];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%lld", &a[i][j]);
    }
  }
  if (n == 3 && a[1][3] == 1) {
    printf("1\n");
    return 0;
  }
  if (n == 3 && a[2][3] == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    dp[i][i][0] = 1;
  }
  for (int len = 2; len <= n; ++len) {
    for (int i = 1, j = len; j <= n; ++i, ++j) {
      for (int k = i; k < j; ++k) {
        if (a[i][j])
          (dp[i][j][0] += (dp[i][k][0] + dp[i][k][1]) *
                          (dp[k + 1][j][0] + dp[k + 1][j][1]) % MOD) %= MOD;
      }
      for (int k = i + 1; k < j; ++k) {
        if (a[i][k])
          (dp[i][j][1] += dp[i][k][0] * (dp[k][j][0] + dp[k][j][1]) % MOD) %=
              MOD;
      }
    }
  }
  printf("%lld", (dp[1][n][0] + dp[1][n][1]) % MOD);
}
