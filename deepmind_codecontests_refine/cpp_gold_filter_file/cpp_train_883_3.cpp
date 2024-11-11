#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
const int N = 410;
int vis[N][N];
vector<int> G[2][N];
int dis[2][N], d[N][N][2];
struct node {
  int x, y, dir;
  node() {}
  node(int x, int y, int dir) : x(x), y(y), dir(dir) {}
};
int n, m;
int bfs() {
  for (int i = 0; i < (int)2; i++) {
    queue<int> Q;
    memset(dis[i], -1, sizeof(dis[i]));
    dis[i][n] = 0;
    Q.push(n);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (auto v : G[i][u]) {
        if (dis[i][v] == -1) {
          dis[i][v] = dis[i][u] + 1;
          Q.push(v);
        }
      }
    }
  }
  int ans = inf;
  memset(d, -1, sizeof(d));
  queue<node> Q;
  d[1][1][0] = 0;
  Q.push(node(1, 1, 0));
  while (!Q.empty()) {
    node u = Q.front();
    Q.pop();
    int x = u.x, y = u.y, dir = u.dir;
    if (u.x == n || u.y == n) {
      ans = min(ans, d[x][y][dir] / 2 +
                         (x == n ? (dis[1][y] == -1 ? inf : dis[1][y])
                                 : (dis[0][x] == -1 ? inf : dis[0][x])));
      continue;
    }
    if (dir == 0) {
      for (auto i : G[dir][x]) {
        if (d[i][y][1] == -1)
          d[i][y][1] = d[x][y][dir] + 1, Q.push(node(i, y, 1));
      }
    } else {
      for (auto i : G[dir][y])
        if (i != x && i != y) {
          if (d[x][i][0] == -1)
            d[x][i][0] = d[x][y][dir] + 1, Q.push(node(x, i, 0));
        }
    }
  }
  return ans == inf ? -1 : ans;
}
int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    for (int i = (int)1; i <= (int)m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      vis[u][v] = vis[v][u] = 1;
      G[0][u].push_back(v);
      G[0][v].push_back(u);
    }
    for (int i = (int)1; i <= (int)n; i++)
      for (int j = (int)1; j <= (int)n; j++)
        if (i != j && !vis[i][j]) G[1][i].push_back(j);
    cout << bfs() << endl;
  }
  return 0;
}
