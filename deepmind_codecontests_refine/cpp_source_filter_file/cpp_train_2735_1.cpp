#include <bits/stdc++.h>
const int N = 5e5 + 7;
int n, m, sx, sy, fx, fy;
int tot, to[N << 1], nex[N << 1], head[N], val[N << 1];
int vis[N];
int dis[N];
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x;
}
struct node {
  int x, y, op;
} a[N];
void add(int x, int y, int z) {
  to[++tot] = y;
  nex[tot] = head[x];
  val[tot] = z;
  head[x] = tot;
}
bool cmp1(node a, node b) { return a.x < b.x; }
bool cmp2(node a, node b) { return a.y < b.y; }
std::priority_queue<std::pair<int, int> > q;
int dijkstra() {
  memset(dis, 0x3f, sizeof dis);
  dis[0] = 0;
  q.push(std::make_pair(0, 0));
  while (!q.empty()) {
    int x = q.top().second;
    q.pop();
    vis[x] = 1;
    for (int i = head[x]; i; i = nex[i]) {
      int v = to[i];
      if (dis[x] + val[i] < dis[v]) {
        dis[v] = dis[x] + val[i];
        q.push(std::make_pair(-dis[v], v));
      }
    }
    while (!q.empty() && vis[q.top().second]) q.pop();
  }
  return dis[m + 1];
}
int main() {
  n = read(), m = read();
  sx = read(), sy = read(), fx = read(), fy = read();
  for (int i = 1; i <= m; ++i) {
    a[i].x = read(), a[i].y = read();
    a[i].op = i;
    add(0, i, std::min(abs(a[i].x - sx), abs(a[i].y - sy)));
    add(i, m + 1, abs(a[i].x - fx) + abs(a[i].y - fy));
  }
  add(0, m + 1, abs(fx - sx) + abs(fy - sy));
  std::sort(a + 1, a + 1 + m, cmp1);
  for (int i = 2; i <= m; ++i) {
    add(a[i - 1].op, a[i].op, a[i].x - a[i - 1].x);
    add(a[i].op, a[i - 1].op, a[i].x - a[i - 1].x);
  }
  std::sort(a + 1, a + 1 + m, cmp2);
  for (int i = 2; i <= m; ++i) {
    add(a[i - 1].op, a[i].op, a[i].y - a[i - 1].y);
    add(a[i].op, a[i - 1].op, a[i].y - a[i - 1].y);
  }
  printf("%d\n", dijkstra());
  return 0;
}
