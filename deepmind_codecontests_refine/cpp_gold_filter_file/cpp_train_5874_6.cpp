#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[1009][1009], vis[1009][1009];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char G[1009][1009], str[10] = {"DIMA"};
int dfs(int x, int y, int idx) {
  if (vis[x][y] == 1) {
    cout << "Poor Inna!" << endl;
    exit(0);
  }
  int& r = dp[x][y];
  if (r != -1) return r;
  vis[x][y] = 1;
  r = 0;
  idx = (idx + 1) % 4;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && ny >= 0 && ny < m && nx < n && G[nx][ny] == str[idx])
      r = max(r, dfs(nx, ny, idx));
  }
  vis[x][y] = 0;
  return r += 1;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  int ans = 0;
  for (int i = 0; i < n; i++) scanf("%s", G[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (G[i][j] == 'D') ans = max(ans, dfs(i, j, 0));
  if (ans < 4) return cout << "Poor Dima!", 0;
  cout << ans / 4 << endl;
}
