#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}, n, m;
const int N = 1505;
char c[N][N];
int k, comp[N][N], start_x, start_y;
bool seen_edge;
void dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) {
    seen_edge = true;
    return;
  }
  if (comp[x][y] || c[x][y] == '#') return;
  if (c[x][y] == 'S') start_x = x, start_y = y;
  comp[x][y] = k;
  for (int k = 0; k < 4; k++) dfs(x + dx[k], y + dy[k]);
}
int dist[10000];
const int inf = 1 << 27;
bool relax(int a, int b, int w) {
  if (dist[b] < inf && dist[a] > dist[b] + w) {
    dist[a] = dist[b] + w;
    return true;
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> c[i];
  k = 1;
  memset(comp, 0, sizeof(comp));
  start_x = -1;
  start_y = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!comp[i][j] && c[i][j] != '#') {
        seen_edge = false;
        dfs(i, j);
        if (seen_edge)
          k++;
        else if (start_x >= 0 && start_y >= 0 && comp[start_x][start_y] == k) {
          cout << "No" << endl;
          return 0;
        }
      }
  bool flag = false;
  for (int z = 0; z < 4; z++) {
    for (int i = 1; i < k; i++) dist[i] = inf;
    dist[comp[start_x][start_y]] = 0;
    for (int t = 0; t < k; t++) {
      bool u, v;
      int a, b, dw;
      for (int i = 0; i < n; i++)
        if (c[i][0] != '#' && c[i][m - 1] != '#') {
          a = comp[i][0];
          b = comp[i][m - 1];
          dw = z / 2 ? 1 : -1;
          flag = relax(a, b, dw);
          v = relax(b, a, -dw);
          if (t == k - 1 && (u || v)) flag = true;
        }
      for (int j = 0; j < m; j++)
        if (c[0][j] != '#' && c[n - 1][j] != '#') {
          a = comp[0][j];
          b = comp[n - 1][j];
          dw = z % 2 ? 1 : -1;
          u = relax(a, b, dw);
          v = relax(b, a, -dw);
          if (t == k - 1 && (u || v)) flag = true;
        }
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}
