#include <bits/stdc++.h>
const int mod = 998244353;
using namespace std;
int n, m, k;
int g[1010][1010];
vector<pair<int, int>> gg[100];
int dis[1002][1002][45];
int v[1002][1002];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vv[50];
int vis[100];
void bfs(int col) {
  queue<pair<int, int>> Q;
  for (pair<int, int> v : gg[col]) {
    dis[v.first][v.second][col] = 0;
    Q.push(v);
  }
  for (int i = 1; i < k + 1; ++i) vis[i] = 0;
  while (!Q.empty()) {
    pair<int, int> tmp = Q.front();
    Q.pop();
    int x = tmp.first, y = tmp.second;
    for (int i = 0; i < 4; ++i) {
      int nx = x + d[i][0];
      int ny = y + d[i][1];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || dis[nx][ny][col] != -1)
        continue;
      dis[nx][ny][col] = dis[x][y][col] + 1;
      Q.push(make_pair(nx, ny));
    }
    if (!vis[g[x][y]]) {
      vis[g[x][y]] = 1;
      for (pair<int, int> v : gg[g[x][y]]) {
        if (dis[v.first][v.second][col] == -1) {
          dis[v.first][v.second][col] = dis[x][y][col] + 1;
          Q.push(v);
        }
      }
    }
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &g[i][j]);
      gg[g[i][j]].push_back(make_pair(i, j));
    }
  }
  memset(dis, -1, sizeof(dis));
  for (int i = 1; i < k + 1; ++i) {
    bfs(i);
  }
  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--;
    y1--;
    x2--;
    y2--;
    int c1 = g[x1][y1];
    int c2 = g[x2][y2];
    int ans = abs(x2 - x1) + abs(y2 - y1);
    for (int i = 1; i < k + 1; ++i) {
      ans = min(ans, dis[x1][y1][i] + dis[x2][y2][i] + 1);
    }
    printf("%d\n", ans);
  }
}
