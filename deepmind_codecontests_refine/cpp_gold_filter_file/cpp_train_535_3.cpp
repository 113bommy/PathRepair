#include <bits/stdc++.h>
using std::make_pair;
using std::pair;
const int N = 50 * 101, M = 50 * 50 * 203, INF = 1000000000;
int dis[N], vis[N], f[N], last[N], n, a, b, c, d, k, flow[N], x, y;
int v[M << 1], w[M << 1], ans, to[M << 1], Next[M << 1], edge, S, T, m, tim;
pair<int, int> e[55];
std::queue<int> q;
int cal(int t, int id) { return n * (t - 1) + id; }
void add(int x, int y, int ww, int zz) {
  to[++edge] = y;
  Next[edge] = last[x];
  last[x] = edge;
  w[edge] = ww;
  v[edge] = zz;
}
void Add(int x, int y, int ww, int zz) {
  add(x, y, ww, zz);
  add(y, x, 0, -zz);
}
int cc(int x) { return (x & 1) ? x + 1 : x - 1; }
bool SPFA() {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  memset(flow, 0x3f, sizeof(flow));
  q.empty();
  q.push(S);
  dis[S] = 0;
  while (q.size()) {
    int x = q.front();
    vis[x] = 0;
    q.pop();
    for (int i = last[x]; i; i = Next[i]) {
      int u = to[i];
      if (w[i] > 0 && dis[x] + v[i] < dis[u]) {
        dis[u] = dis[x] + v[i];
        if (!vis[u]) vis[u] = 1, q.push(u);
        flow[u] = std::min(flow[x], w[i]);
        f[u] = i;
      }
    }
  }
  if (dis[T] < INF) return 1;
  return 0;
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
  tim = m + k;
  S = cal(tim + 1, 1), T = cal(tim, 1);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &x);
    Add(S, cal(1, x), 1, 0);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    e[i] = make_pair(x, y);
  }
  for (int i = 1; i < tim; i++) {
    Add(cal(i, 1), cal(i + 1, 1), INF, 0);
    for (int j = 2; j <= n; j++) Add(cal(i, j), cal(i + 1, j), INF, c);
    for (int j = 1; j <= m; j++) {
      int x = e[j].first, y = e[j].second;
      for (int h = 1, cos = 1; h <= k; h++, cos = h * h - (h - 1) * (h - 1)) {
        Add(cal(i, x), cal(i + 1, y), 1, d * cos + c);
        Add(cal(i, y), cal(i + 1, x), 1, d * cos + c);
      }
    }
  }
  while (SPFA()) {
    ans = ans + dis[T] * flow[T];
    int u = T;
    while (u != S) {
      w[f[u]] -= flow[T];
      w[cc(f[u])] += flow[T];
      u = to[cc(f[u])];
    }
  }
  printf("%d\n", ans);
}
