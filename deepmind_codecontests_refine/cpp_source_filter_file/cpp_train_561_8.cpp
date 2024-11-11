#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
char g[maxn][maxn];
int vis[maxn][maxn];
int n, m, k, remain, cur;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool dfs(int x, int y) {
  if (++cur >= remain) return true;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
      if (g[nx][ny] == '.' && !vis[nx][ny]) {
        vis[nx][ny] = 1;
        if (dfs(nx, ny)) return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) scanf("%s", g[i]);
  int cell = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (g[i][j] == '.') cell++;
    }
  remain = cell - k;
  int ok = 0;
  cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j] == '.') {
        vis[i][j] = 1;
        ok = 1;
        dfs(i, j);
        break;
      }
    }
    if (ok) break;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (vis[i][j] == 0 && g[i][j] == '.') g[i][j] = 'X';
    }
  for (int i = 0; i < n; ++i) printf("%s\n", g[i]);
}
