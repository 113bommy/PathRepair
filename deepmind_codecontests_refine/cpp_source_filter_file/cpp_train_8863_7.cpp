#include <bits/stdc++.h>
using namespace std;
const long long md = 998244353;
long long dp[4020][2010][2];
int fpw(int a, int n) {
  int cnt = a, ret = 1;
  while (n) {
    if (n & 1) {
      ret = int(1ll * ret * cnt % md);
    }
    cnt = int(1ll * cnt * cnt % md);
    n >>= 1;
  }
  return ret;
}
int main() {
  int n, kk, l;
  scanf("%d%d%d", &n, &kk, &l);
  dp[0][0][0] = 1;
  for (int i = 1; i <= 2 * n + 1; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= 1; k++) {
        if (dp[i - 1][j][k]) {
          if (j) {
            dp[i][j - 1][k] =
                (dp[i][j - 1][k] + 1ll * dp[i - 1][j][k] * j % md) % md;
          }
          if (i - 1 + j < 2 * n + k) {
            dp[i][j + 1][k] = (dp[i][j + 1][k] + dp[i - 1][j][k]) % md;
          }
          if (k == 0 && j >= kk) {
            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][k]) % md;
          }
        }
      }
    }
  }
  long long ans = dp[2 * n + 1][0][1];
  ans = (1ll * ans * fpw(2, 1ll * n)) % md;
  int po = 1;
  for (int i = n + 1; i <= 2 * n + 1; i++) {
    po = int((1ll * po * i) % md);
  }
  ans = (ans * fpw(po, md - 2)) % md;
  printf("%lld\n", ans);
  return 0;
}
