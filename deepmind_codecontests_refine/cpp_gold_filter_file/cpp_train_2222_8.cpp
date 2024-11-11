#include <bits/stdc++.h>
using namespace std;
int n, m, timer, ans;
vector<vector<char>> graph;
vector<vector<bool>> vis;
vector<vector<int>> tin, low;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int r, int c, int pr, int pc) {
  vis[r][c] = true;
  tin[r][c] = low[r][c] = timer++;
  int children = 0;
  for (int i = 0; i < 4; i++) {
    int _r = r + dy[i], _c = c + dx[i];
    if (_r < 0 or _c < 0 or _r >= n or _c >= m or graph[_r][_c] == '.' or
        (_r == pr and _c == pc))
      continue;
    if (vis[_r][_c]) {
      low[r][c] = min(low[r][c], tin[_r][_c]);
    } else {
      dfs(_r, _c, r, c);
      low[r][c] = min(low[r][c], low[_r][_c]);
      if (low[_r][_c] >= tin[r][c] and pr != -1 and pc != -1) ans++;
      children++;
    }
  }
  if (children > 1 and pr == -1 and pc == -1) ans++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  graph.resize(n, vector<char>(m));
  vis.resize(n, vector<bool>(m, false));
  tin.resize(n, vector<int>(m, -1));
  low.resize(n, vector<int>(m, -1));
  timer = 0;
  ans = 0;
  int uc, ur, nodes = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> graph[i][j];
      if (graph[i][j] == '#') {
        ur = i;
        uc = j;
        nodes++;
      }
    }
  }
  dfs(ur, uc, -1, -1);
  if (nodes <= 2)
    cout << -1;
  else if (!ans)
    cout << 2;
  else
    cout << 1;
  return 0;
}
