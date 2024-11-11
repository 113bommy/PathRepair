#include <bits/stdc++.h>
using namespace std;
int vis[55][55];
char a[55][55];
bool dp[55][55][2][5];
void dfs(int i, int j, int c, char k) {
  if (a[i][j] != 'B' || c > 2 || dp[i][j][c][k]) return;
  dp[i][j][c][k] = 1;
  if (vis[i][j] != -1)
    vis[i][j] = min(c, vis[i][j]);
  else
    vis[i][j] = c;
  if (k == 0) {
    dfs(i + 1, j, c, 1);
    dfs(i - 1, j, c, 2);
    dfs(i, j + 1, c, 3);
    dfs(i, j - 1, c, 4);
  } else if (k == 2) {
    dfs(i - 1, j, c, 2);
    dfs(i + 1, j, c + 1, 1);
    dfs(i, j + 1, c + 1, 3);
    dfs(i, j - 1, c + 1, 4);
  } else if (k == 1) {
    dfs(i + 1, j, c, 1);
    dfs(i - 1, j, c + 1, 2);
    dfs(i, j + 1, c + 1, 3);
    dfs(i, j - 1, c + 1, 4);
  } else if (k == 3) {
    dfs(i, j + 1, c, 3);
    dfs(i + 1, j, c + 1, 1);
    dfs(i - 1, j, c + 1, 2);
    dfs(i, j - 1, c + 1, 4);
  } else {
    dfs(i, j - 1, c, 4);
    dfs(i + 1, j, c + 1, 1);
    dfs(i - 1, j, c + 1, 2);
    dfs(i, j + 1, c + 1, 3);
  }
}
int n, m;
bool good() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'B' && vis[i][j] == -1) return 0;
      if (a[i][j] == 'B' && vis[i][j] > 2) return 0;
    }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n + 5; i++)
    for (int j = 0; j < m + 5; j++) a[i][j] = '.';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != 'B') continue;
      memset(vis, -1, sizeof(vis));
      memset(dp, 0, sizeof(dp));
      dfs(i, j, 0, 0);
      if (!good()) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
}
