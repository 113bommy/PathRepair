#include <bits/stdc++.h>
using namespace std;
int n, m, timer = 0;
bool cut_point = false;
vector<vector<char> > g;
vector<vector<int> > deg, used, tin, fup;
int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
inline bool in(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
void dfs(int i, int j, int p_x = -1, int p_y = -1) {
  used[i][j] = true;
  tin[i][j] = fup[i][j] = timer++;
  int ch = 0;
  for (int k = 0; k < (int)4; k++) {
    int x = i + dir[k][0], y = j + dir[k][1];
    if (!in(x, y)) continue;
    if (g[x][y] != '#') continue;
    if (used[x][y] && (x != p_x || y != p_y)) {
      fup[i][j] = min(fup[i][j], tin[x][y]);
    } else if (!used[x][y] && (x != p_x || y != p_y)) {
      dfs(x, y, i, j);
      fup[i][j] = min(fup[i][j], fup[x][y]);
      if (fup[x][y] >= tin[i][j] && p_x != -1) cut_point = true;
      ++ch;
    }
    deg[i][j]++;
  }
  if (p_x == -1 && ch > 1) cut_point = true;
}
int main() {
  cin >> n >> m;
  deg.assign(n, vector<int>(m, 0));
  used.assign(n, vector<int>(m, 0));
  tin.assign(n, vector<int>(m));
  fup.assign(n, vector<int>(m));
  g.resize(n);
  int x = -1, y = -1, cnt = 0;
  for (int i = 0; i < (int)n; i++) {
    g[i].resize(m);
    for (int j = 0; j < (int)m; j++) {
      cin >> g[i][j];
      if (g[i][j] == '#') x = i, y = j, cnt++;
    }
  }
  if (cnt <= 1) {
    cout << -1;
    return 0;
  }
  dfs(x, y);
  int min = cut_point ? 1 : deg[x][y];
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)m; j++) {
      if (deg[i][j] != 0 && deg[i][j] < min) min = deg[i][j];
    }
  }
  cout << min;
  return 0;
}
