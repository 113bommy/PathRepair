#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e2 + 7;
const int M = 1e6 + 7;
const long long mod = 1e9 + 7;
int c[27][27], dp[N][N][27];
char s[N];
signed main() {
  ios::sync_with_stdio(false);
  int n, m, mm;
  cin >> (s + 1) >> m >> mm;
  n = strlen(s + 1);
  while (mm--) {
    char u, v;
    int x;
    cin >> u >> v >> x;
    c[u - 'a' + 1][v - 'a' + 1] = x;
  }
  memset(dp, -0x3f, sizeof dp);
  for (int i = 1; i <= 26; i++)
    if (i == s[1] - 'a' + 1)
      dp[1][0][i] = 0;
    else
      dp[1][1][i] = 0;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int ch = 1; ch <= 26; ch++) {
        int &x = dp[i][j][ch];
        for (int k = 1; k <= 26; k++) {
          if (ch == s[i] - 'a' + 1)
            x = max(x, dp[i - 1][j][k] + c[k][ch]);
          else
            x = max(x, dp[i - 1][j - 1][k] + c[k][ch]);
        }
      }
  int ans = -INF;
  for (int j = 0; j <= m; j++)
    for (int ch = 1; ch <= 26; ch++) ans = max(ans, dp[n][j][ch]);
  cout << ans << "\n";
  return 0;
}
