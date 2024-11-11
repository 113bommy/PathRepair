#include <bits/stdc++.h>
using namespace std;
int dp[4005][4005], nxta[4005][35], nxtb[4005][35];
char a[4005], b[4005];
inline void upd(int &x, int y) {
  if (x > y) x = y;
}
int main() {
  int ti, td, tr, te;
  scanf("%d%d%d%d%s%s", &ti, &td, &tr, &te, a, b);
  int n = strlen(a), m = strlen(b);
  for (int i = 0; i < 26; i++) nxta[n][i] = n;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) nxta[i][j] = nxta[i + 1][j];
    nxta[i][a[i] - 'a'] = i;
  }
  for (int i = 0; i < 26; i++) nxtb[n][i] = m;
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) nxtb[i][j] = nxtb[i + 1][j];
    nxtb[i][b[i] - 'a'] = i;
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (j < m) upd(dp[i][j + 1], dp[i][j] + ti);
      if (i < n) upd(dp[i + 1][j], dp[i][j] + td);
      if (i < n && j < m) upd(dp[i + 1][j + 1], dp[i][j] + tr);
      if (i < n && j < m && a[i] == b[j]) upd(dp[i + 1][j + 1], dp[i][j]);
      if (i < n && j < m) {
        int x = nxta[i + 1][b[j] - 'a'], y = nxtb[j + 1][a[i] - 'a'];
        if (x < n && y < m)
          upd(dp[x + 1][y + 1],
              dp[i][j] + te + td * (x - i - 1) + ti * (y - j - 1));
      }
    }
  }
  printf("%d\n", dp[n][m]);
  return 0;
}
