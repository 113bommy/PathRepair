#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int read(T& x) {
  x = 0;
  char c = getchar(), f = 1;
  while (!isdigit(c)) {
    if (c == -1) return -1;
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  x *= f;
  return 1;
}
template <typename T>
inline int write(T x) {
  if (x < 0) x = -x;
  if (x > 10) return write(x / 10) & putchar(x % 10 ^ 48);
  return putchar(x ^ 48);
}
template <typename T>
inline int write(T x, char c) {
  return write(x) + putchar(c);
}
int n, m, s, t;
struct Graph {
  struct edge {
    int v, nxt;
    long long w;
  } e[100005];
  int f[100005], tot = 1;
  inline void addEgde(int u, int v, long long w) {
    tot++, e[tot].v = v, e[tot].w = w, e[tot].nxt = f[u], f[u] = tot;
  }
  bool vis[100005];
  inline void dijkstra(long long* dis, int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                   greater<pair<long long, int> > >
        q;
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX >> 2, vis[i] = 0;
    dis[s] = 0;
    q.push(make_pair(0ll, s));
    while (!q.empty()) {
      int x = q.top().second;
      long long d = q.top().first;
      q.pop();
      if (vis[x]) continue;
      vis[x] = 1;
      for (int i = f[x]; i; i = e[i].nxt) {
        int v = e[i].v;
        long long w = e[i].w;
        if (dis[v] > dis[x] + w) {
          dis[v] = dis[x] + w;
          q.push(make_pair(dis[v], v));
        }
      }
    }
  }
  inline void tarjan(int x, int fa);
} g, rg, mg;
long long dis[2][100005];
int dfn[100005], low[100005], idx;
bool isc[100005];
inline void Graph::tarjan(int x, int fa) {
  dfn[x] = low[x] = ++idx;
  for (int i = f[x]; i; i = e[i].nxt) {
    int v = e[i].v;
    int id = e[i].w;
    if (!dfn[v]) {
      tarjan(v, x);
      if (low[v] > dfn[x]) isc[id] = 1;
      low[x] = ((low[x]) < (low[v]) ? (low[x]) : (low[v]));
    } else if (dfn[x] > dfn[v] && v != fa)
      low[x] = ((low[x]) < (dfn[v]) ? (low[x]) : (dfn[v]));
  }
}
long long ans[100005];
bool uniq[100005];
set<int> se[100005];
int main() {
  read(n), read(m), read(s), read(t);
  for (int i = 1, u, v; i <= m; i++) {
    long long w;
    read(u), read(v), read(w);
    g.addEgde(u, v, w);
    rg.addEgde(v, u, w);
  }
  g.dijkstra(dis[0], s);
  rg.dijkstra(dis[1], t);
  for (int i = 1; i <= n; i++) {
    for (int j = g.f[i]; j; j = g.e[j].nxt) {
      int v = g.e[j].v;
      long long w = g.e[j].w;
      if (se[i].count(v)) uniq[j] = 1;
      if (dis[0][i] + dis[1][v] + w == dis[0][t]) {
        se[i].insert(v);
        mg.addEgde(i, v, j), mg.addEgde(v, i, j);
      }
      ans[j] = w - (dis[0][t] - dis[0][i] - dis[1][v]) + 1;
      if (w - ans[j] <= 0) ans[j] = -1;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) mg.tarjan(i, 0);
  for (int i = 2; i <= m + 1; i++) {
    if (isc[i] && !uniq[i])
      puts("YES");
    else if (ans[i] == -1)
      puts("NO");
    else
      printf("CAN %d\n", ans[i]);
  }
}
