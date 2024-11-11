#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<vector<long long>>> dp(
      n + 2, vector<vector<long long>>(m + 2, vector<long long>(4, 0)));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dp[i][j][1] = dp[i][j - 1][0] + 1;
      dp[i][j][0] = dp[i - 1][j][1] + 1;
    }
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--) {
      dp[i][j][2] = dp[i + 1][j][3] + 1;
      dp[i][j][3] = dp[i][j + 1][2] + 1;
    }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      ans += (dp[i][j][0]);
      ans += (dp[i][j][1]);
    }
  ans -= n * m;
  int q;
  cin >> q;
  vector<vector<int>> vis(n + 2, vector<int>(m + 2, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      vis[i][j] = 1;
    }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    if (vis[x][y] == 1) {
      vis[x][y] ^= 1;
      ans -= (dp[x][y - 1][0] + 1) * (dp[x + 1][y][3] + 1);
      ans -= (dp[x][y + 1][2] + 1) * (dp[x - 1][y][1] + 1);
      ans++;
      for (int k = 0; k < 4; k++) dp[x][y][k] = 0;
    } else {
      vis[x][y] ^= 1;
      ans += (dp[x][y - 1][0] + 1) * (dp[x + 1][y][3] + 1);
      ans += (dp[x][y + 1][2] + 1) * (dp[x - 1][y][1] + 1);
      ans--;
      for (int k = 0; k < 4; k++) dp[x][y][k] = 1;
    }
    int px = x, py = y;
    int qx = x, qy = y;
    for (int k = 0; k <= 2 * max(n, m); k++) {
      if (k & 1) {
        py++;
        qx++;
      } else if (k != 0) {
        px++;
        qy++;
      }
      if (px <= n && py <= m && vis[px][py])
        dp[px][py][1] = 1 + dp[px][py - 1][0];
      if (qx <= n && qy <= m && vis[qx][qy])
        dp[qx][qy][0] = 1 + dp[qx - 1][qy][1];
    }
    px = x, py = y;
    qx = x, qy = y;
    for (int k = 0; k <= 2 * max(n, m); k++) {
      if (k & 1) {
        py--;
        qx--;
      } else if (k != 0) {
        px--;
        qy--;
      }
      if (px >= 1 && py >= 1 && vis[px][py])
        dp[px][py][3] = 1 + dp[px][py + 1][2];
      if (qx >= 1 && qy >= 1 && vis[qx][qy])
        dp[qx][qy][2] = 1 + dp[qx + 1][qy][3];
    }
    cout << ans << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
}
