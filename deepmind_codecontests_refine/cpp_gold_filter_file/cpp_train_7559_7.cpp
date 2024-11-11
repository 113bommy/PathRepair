#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
char mp[maxn][maxn];
int vis[maxn][maxn], dis[maxn][maxn];
struct Node {
  int x, y;
  Node(int x = 0, int y = 0) : x(x), y(y) {}
};
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int sx, sy, ex, ey;
int n, m, k;
void bfs() {
  Node p1, p2;
  queue<Node> q;
  q.push(Node(sx, sy));
  vis[sx][sy] = (1 << 4) - 1;
  dis[sx][sy] = 0;
  while (!q.empty()) {
    p2 = q.front();
    q.pop();
    if (p2.x == ex && p2.y == ey) return;
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= k; j++) {
        int dx = p2.x + d[i][0] * j;
        int dy = p2.y + d[i][1] * j;
        if (dx < 0 || dx >= n || dy < 0 || dy >= m || mp[dx][dy] == '#') break;
        if (vis[dx][dy] & (1 << i)) break;
        int ok = 0;
        if (!vis[dx][dy]) ok = 1;
        vis[dx][dy] |= (1 << i);
        if (ok) {
          dis[dx][dy] = dis[p2.x][p2.y] + 1;
          q.push(Node(dx, dy));
        }
      }
    }
  }
}
int main() {
  memset(dis, -1, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", mp[i]);
  scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
  sx--;
  sy--;
  ex--;
  ey--;
  bfs();
  printf("%d\n", dis[ex][ey]);
}
