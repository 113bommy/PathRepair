#include <bits/stdc++.h>
using namespace std;
const double eps(1e-8);
int n, k;
char s[4][410];
int sx, sy;
queue<pair<int, int> > Q;
int dp[100][4][400];
void solve() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] == 's') {
        sx = i, sy = j;
        break;
      }
  s[sx][sy] = '.';
  for (int i = 0; i < 3; i++)
    for (int j = n; j < 2 * n; j++) s[i][j] = '.';
  memset(dp, 0, sizeof(dp));
  dp[0][sx][sy] = 1;
  for (int t = 1; t <= n / 2 + 1; t++) {
    for (int x = 0; x < 3; x++)
      for (int y = 0; y < 2 * n; y++) {
        if (!dp[t - 1][x][y]) continue;
        if (s[x][y + 1] != '.') continue;
        if (y + 3 < 2 * n && s[x][y + 2] == '.' && s[x][y + 1] == '.' &&
            s[x][y] == '.' && s[x][y + 3] == '.')
          dp[t][x][y + 3] = 1;
        if (y + 3 < 2 * n && s[x][y] == '.' && x - 1 >= 0 &&
            s[x - 1][y + 1] == '.' && s[x - 1][y + 2] == '.' &&
            s[x - 1][y + 3] == '.')
          dp[t][x - 1][y + 3] = 1;
        if (y + 3 < 2 * n && s[x][y] == '.' && x + 1 < 3 &&
            s[x + 1][y + 1] == '.' && s[x + 1][y + 2] == '.' &&
            s[x + 1][y + 3] == '.')
          dp[t][x + 1][y + 3] = 1;
        if (y + 3 < 2 * n && s[x][y] == '.' && s[x][y + 1] == '.' &&
            s[x][y + 2] == '.' && s[x][y + 3] == '.')
          dp[t][x][y + 3] = 1;
      }
  }
  int ok = 0;
  for (int t = 1; t <= n / 2 + 1; t++) {
    for (int x = 0; x < 2; x++) {
      for (int y = n; y < 2 * n; y++) {
        if (dp[t][x][y] && s[x][y] == '.') {
          puts("YES");
          ok = 1;
          break;
        }
      }
      if (ok) break;
    }
    if (ok) break;
  }
  if (!ok) puts("NO");
  return;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 3; i++) {
      scanf("%s", s[i]);
    }
    solve();
  }
  return 0;
}
