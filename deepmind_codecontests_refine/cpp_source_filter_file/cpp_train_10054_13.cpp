#include <bits/stdc++.h>
using namespace std;
int const inf = 1000 * 1000 * 1000;
long long const inf64 = 1ll * inf * inf;
int const N = 100005;
int n;
int a[3][N];
long long dp[8][3][N];
inline void upd(long long& x, long long y) { x = max(x, y); }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int mask = 0; mask < 8; mask++) {
    for (int pos = 0; pos < 3; pos++) {
      for (int i = 0; i < N; i++) {
        dp[mask][pos][i] = -inf64;
      }
    }
  }
  dp[1][0][1] = a[0][1];
  for (int i = 1; i <= n; i++) {
    for (int it = 0; it < 30; it++) {
      for (int pos = 0; pos < 3; pos++) {
        for (int mask = 0; mask < 8; mask++) {
          if (!((1 << pos) & mask)) continue;
          if (i < n) {
            upd(dp[1 << pos][pos][i + 1], dp[mask][pos][i] + a[pos][i + 1]);
          }
          if (pos > 0 && !((1 << (pos - 1)) & mask)) {
            upd(dp[mask | (1 << (pos - 1))][pos - 1][i],
                dp[mask][pos][i] + a[pos - 1][i]);
          }
          if (pos < 2 && !((1 << (pos + 1)) & mask)) {
            upd(dp[mask | (1 << (pos + 1))][pos + 1][i],
                dp[mask][pos][i] + a[pos + 1][i]);
          }
        }
      }
      if (i < n) {
        upd(dp[7][0][i + 1], dp[4][2][i] + a[2][i + 1] + a[1][i + 1] + a[1][i] +
                                 a[0][i] + a[0][i + 1]);
        upd(dp[7][2][i + 1], dp[1][0][i] + a[0][i + 1] + a[1][i + 1] + a[1][i] +
                                 a[2][i] + a[2][i + 1]);
      }
    }
  }
  long long res = 0;
  for (int mask = 0; mask < 8; mask++) {
    if (mask & 4) {
      upd(res, dp[mask][2][n]);
    }
  }
  cout << res << "\n";
  return 0;
}
