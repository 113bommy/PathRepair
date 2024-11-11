#include <bits/stdc++.h>
using namespace std;
const long long N = 45;
long long ans, n, ch[N][2], nxt[N], dp[N][N][N];
char s[N];
inline void init() { scanf("%d%s", &n, s + 1); }
inline void solve() {
  long long len = strlen(s + 1);
  for (long long i = 1; i <= len; i++) ch[i - 1][s[i] - '0'] = i;
  for (long long i = 1; i <= len; i++) {
    for (long long j = 0; j <= 1; j++) {
      if (ch[i][j])
        nxt[ch[i][j]] = ch[nxt[i]][j];
      else
        ch[i][j] = ch[nxt[i]][j];
    }
  }
  ans = 1ll << n;
  for (long long i = 0; i <= len - 1; i++) {
    memset(dp, 0, sizeof dp);
    dp[0][0][i] = 1;
    for (long long j = 0; j <= n - 1; j++) {
      for (long long k = 0; k <= len - 1; k++) {
        for (long long kk = 0; kk <= len - 1; kk++) {
          for (long long c = 0; c < 2; c++) {
            dp[j + 1][ch[k][c]][ch[kk][c]] += dp[j][k][kk];
          }
        }
      }
    }
    for (long long j = 0; j < len; j++) ans -= dp[n][i][j];
  }
  printf("%I64d\n", ans);
}
signed main() {
  init();
  solve();
  return 0;
}
