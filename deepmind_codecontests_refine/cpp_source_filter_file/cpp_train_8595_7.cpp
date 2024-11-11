#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x;
}
const int maxn = 2e5 + 10;
const int maxm = 3e5 + 10;
struct Edge {
  int to, w, next;
} e1[maxm * 2], e2[maxm], e3[maxn];
int h1[maxn], h2[maxn], h3[maxn], cnt1 = 1, cnt2, cnt3;
inline void add1(int u, int v, int w) {
  e1[++cnt1].to = v, e1[cnt1].w = w, e1[cnt1].next = h1[u], h1[u] = cnt1;
  e1[++cnt1].to = u, e1[cnt1].w = w, e1[cnt1].next = h1[v], h1[v] = cnt1;
}
inline void add2(int u, int v) {
  e2[++cnt2].to = v, e2[cnt2].next = h2[u], h2[u] = cnt2;
}
inline void add3(int u, int v) {
  e3[++cnt3].to = v, e3[cnt3].next = h3[u], h3[u] = cnt3;
}
int n, m, s;
long long dis[maxn];
bool vis[maxn];
void dijkstra() {
  priority_queue<pair<long long, int> > Q;
  memset(dis, 0x3f, sizeof(dis));
  Q.push(make_pair(dis[s] = 0, s));
  while (!Q.empty()) {
    int x = Q.top().second;
    Q.pop();
    if (vis[x]) continue;
    vis[x] = true;
    for (int i = h1[x]; i; i = e1[i].next) {
      int y = e1[i].to, z = e1[i].w;
      if (dis[x] + z < dis[y]) {
        dis[y] = dis[x] + z;
        Q.push(make_pair(-dis[y], y));
      }
    }
  }
  for (int i = 2; i <= cnt1; i++) {
    int u = e1[i ^ 1].to, v = e1[i].to, w = e1[i].w;
    if (dis[u] + w == dis[v]) add2(v, u);
  }
}
int topo[maxn], idx;
void dfs(int x) {
  vis[x] = true;
  for (int i = h2[x]; i; i = e2[i].next)
    if (!vis[e2[i].to]) dfs(e2[i].to);
  topo[++idx] = x;
}
int f[maxn][16], dep[maxn];
inline int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 15; i >= 0; i--)
    if (dep[f[x][i]] >= dep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = 15; i >= 0; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
int siz[maxn];
void dfs_tr(int x) {
  siz[x] = 1;
  for (int i = h3[x]; i; i = e3[i].next) {
    int y = e3[i].to;
    dfs_tr(y);
    siz[x] += siz[y];
  }
}
int main() {
  n = read(), m = read(), s = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), w = read();
    add1(u, v, w);
  }
  dijkstra();
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i);
  for (int i = 2; i <= n; i++) {
    int x = topo[i];
    if (dis[x] == 0x3f3f3f3f3f3f3f3fll) continue;
    int t = h2[x], p = e2[t].to;
    for (t = e2[t].next; t; t = e2[t].next) p = lca(p, e2[t].to);
    add3(p, x);
    dep[x] = dep[p] + 1;
    f[x][0] = p;
    for (int k = 1; k <= 15; k++) f[x][k] = f[f[x][k - 1]][k - 1];
  }
  dfs_tr(s);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == s) continue;
    if (siz[i] > ans) ans = siz[i];
  }
  printf("%d\n", ans);
  return 0;
}
