#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int dp[105][105][11];
int path[105][105][11];
int tu[105][105];
int main() {
  int n, m, K;
  cin >> n >> m >> K;
  for (int i = 1; i <= n; i++) {
    getchar();
    for (int j = 1; j <= m; j++) {
      char ch;
      scanf("%c", &ch);
      tu[i][j] = ch - '0';
    }
  }
  memset(dp, -0x3f, sizeof dp);
  for (int i = 1; i <= m; i++) {
    dp[1][i][tu[1][i] % (K + 1)] = tu[1][i];
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k <= K; k++) {
        if (dp[i - 1][j - 1][k] >= dp[i - 1][j + 1][k] &&
            dp[i - 1][j - 1][k] != -0x3f3f3f3f) {
          if (dp[i][j][(tu[i][j] + k) % (K + 1)] <=
              dp[i - 1][j - 1][k] + tu[i][j]) {
            dp[i][j][(tu[i][j] + k) % (K + 1)] =
                max(dp[i][j][(tu[i][j] + k) % (K + 1)],
                    dp[i - 1][j - 1][k] + tu[i][j]);
            path[i][j][(tu[i][j] + k) % (K + 1)] = 1;
          }
        } else if (dp[i - 1][j + 1][k] != -0x3f3f3f3f) {
          if (dp[i][j][(tu[i][j] + k) % (K + 1)] <=
              dp[i - 1][j + 1][k] + tu[i][j]) {
            dp[i][j][(tu[i][j] + k) % (K + 1)] =
                max(dp[i][j][(tu[i][j] + k) % (K + 1)],
                    dp[i - 1][j + 1][k] + tu[i][j]);
            path[i][j][(tu[i][j] + k) % (K + 1)] = 2;
          }
        }
      }
    }
  }
  int idx = 1;
  int maxv = 0;
  for (int i = 1; i <= m; i++) {
    if (maxv < dp[n][i][0]) {
      idx = i;
      maxv = max(maxv, dp[n][i][0]);
    }
  }
  int x = n, y = idx;
  if (maxv == 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << maxv << endl;
  cout << idx << endl;
  string ans;
  int kk = 0;
  while (x >= 1) {
    if (path[x][y][kk] == 1) {
      if (K) kk = (kk - tu[x][y] + (K + 1) * 100) % (K + 1);
      x--, y--;
      ans += "L";
    } else if (path[x][y][kk] == 2) {
      if (K) kk = (kk - tu[x][y] + (K + 1) * 100) % (K + 1);
      x--, y++;
      ans += "R";
    } else
      break;
  }
  cout << ans << endl;
}
