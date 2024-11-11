#include <bits/stdc++.h>
using namespace std;
bool vis[15][15][15];
char arr[15][15][15];
vector<pair<int, int>> v;
int n, m, k, x, y, ans;
void dfs(int i, int j, int c) {
  if (arr[i][j][c] == '#' || (i < 1 || i > k) || (j < 1 || j > n) ||
      (c < 1 || c > m) || vis[i][j][c])
    return;
  if (!vis[i][j][c] && arr[i][j][c] == '.') {
    ans++;
    vis[i][j][c] = true;
    dfs(i, j, c + 1);
    dfs(i, j, c - 1);
    dfs(i, j + 1, c);
    dfs(i, j - 1, c);
    dfs(i + 1, j, c);
    dfs(i - 1, j, c);
  }
}
int main() {
  ans = 0;
  memset(vis, 0, sizeof vis);
  cin >> k >> n >> m;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      for (int c = 1; c <= m; c++) {
        cin >> arr[i][j][c];
      }
    }
  }
  cin >> x >> y;
  dfs(1, x, y);
  cout << ans;
  return 0;
}
