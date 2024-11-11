#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
const int Q = 1e9 + 7;
int dp[1010][110][2];
int main() {
  srand(time(NULL));
  int n, k, m, kk, k0, c, st, i;
  scanf("%d%d%d", &n, &k, &m);
  dp[0][0][0] = 1;
  st = 1;
  for (i = 1; i <= n; i++) {
    for (kk = 0; kk < k; kk++) {
      for (c = ((i == n) ? 1 : 0); c < 10; c++) {
        k0 = (int)((((kk - (long long)st * (long long)c) % k) + k) % k);
        if (kk) {
          dp[i][kk][0] = (dp[i][kk][0] + dp[i - 1][k0][0]) % m;
          dp[i][kk][1] = (dp[i][kk][1] + dp[i - 1][k0][1]) % m;
        } else {
          if (c == 0) {
            dp[i][kk][0] = (dp[i][kk][0] + dp[i - 1][k0][0]) % m;
            dp[i][kk][1] = (dp[i][kk][1] + dp[i - 1][k0][1]) % m;
          } else
            dp[i][kk][1] =
                (dp[i][kk][1] + dp[i - 1][k0][0] + dp[i - 1][k0][1]) % m;
        }
      }
    }
    st = (int)(((long long)st * 10) % k);
  }
  int ans = 0;
  for (i = 0; i < k; i++) ans = (ans + dp[n][i][1]) % m;
  printf("%d", ans);
  return 0;
}
