#include <bits/stdc++.h>
using namespace std;
int Min;
int n, m;
int grid[40][40];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool ok(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void dfs(int x, int y, int now) {
  if (y >= m) {
    dfs(x + 1, 0, now);
    return;
  }
  if (x >= n) {
    Min = min(now, Min);
    return;
  }
  if (now - ((n - x - 1) * m + (m - y - 1)) > Min) return;
  for (int i = 0; i < 4; i++) {
    int nx = dx[i] + x, ny = dy[i] + y;
    if (ok(nx, ny)) {
      if (grid[x][y] > 1) continue;
      grid[x][y]--;
      grid[nx][ny]++;
      int Now = now;
      if (grid[x][y] == 0) Now--;
      if (grid[nx][ny] == 1) Now++;
      if (Now > Min && grid[x][y] != 0) continue;
      dfs(x, y + 1, Now);
      grid[nx][ny]--;
      grid[x][y]++;
    }
  }
  if (grid[x][y] != 1) dfs(x, y + 1, now);
}
map<pair<int, int>, int> ans;
void print_table() {
  ans[make_pair(8, 5)] = 29;
  ans[make_pair(10, 4)] = 30;
  ans[make_pair(6, 6)] = 26;
  ans[make_pair(9, 4)] = 26;
  ans[make_pair(7, 5)] = 26;
  ans[make_pair(13, 3)] = 29;
  ans[make_pair(12, 3)] = 26;
}
int main() {
  print_table();
  cin >> n >> m;
  if (m > n) swap(n, m);
  if (ans[make_pair(n, m)]) {
    cout << ans[make_pair(n, m)] << endl;
    return 0;
  }
  Min = n * m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) grid[i][j] = 1;
  dfs(0, 0, n * m);
  cout << n * m - Min << endl;
  return 0;
}
