#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;
int n, m, p, q = 1;
long long dp[2][35][35][35][2];
long long ans;
void inc(long long &x, long long y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int main() {
  scanf("%d%d", &n, &m);
  dp[0][0][0][0][1] = 1ll;
  for (int i = 0; i < n; i++) {
    memset(dp[q], 0, sizeof(dp[q]));
    for (int j = 0; j <= m; j++)
      for (int k = j; k <= m; k++)
        for (int l = k; l <= m; l++)
          for (int o = 0; o < 2; o++)
            if (dp[p][j][k][l][o] != 0ll) {
              long long pre = dp[p][j][k][l][o];
              int nj = min(m, j + 1), nk = min(m, k + 1), nl = min(m, l + 1);
              inc(dp[q][nj][nk][nl][o], pre);
              if (o) {
                inc(dp[q][0][nk][nl][nj < m], pre);
                inc(dp[q][0][nj][nl][nk < m], pre);
                inc(dp[q][0][nj][nk][nl < m], pre);
              } else {
                inc(dp[q][nk][nl][m][nj < m], pre);
                inc(dp[q][nj][nl][m][nk < m], pre);
                inc(dp[q][nj][nk][m][nl < m], pre);
              }
            }
    p ^= 1;
    q ^= 1;
  }
  for (int i = 0; i <= m; i++)
    for (int j = i; j <= m; j++)
      for (int k = j; k <= m; k++)
        for (int o = 0; o < 2; o++)
          if (o || i < m || j < m || k < m) inc(ans, dp[p][i][j][k][o]);
  printf("%I64d\n", ans);
  return 0;
}
