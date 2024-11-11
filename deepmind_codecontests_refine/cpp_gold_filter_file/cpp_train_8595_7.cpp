#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int MAXM = 300010;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
struct graph {
  struct edge {
    int ne, to, w;
    edge(int N = 0, int T = 0, int W = 0) : ne(N), to(T), w(W) {}
  } e[MAXM << 1];
  int fir[MAXN], num;
  inline void reset() {
    for (int i = 1; i <= n; i++) fir[i] = 0;
    num = 0;
  }
  inline void join(int a, int b, int c = 0) {
    e[++num] = edge(fir[a], b, c);
    fir[a] = num;
  }
} T, G;
int deg[MAXN];
long long dis[MAXN];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    hp;
inline void dijk(int s) {
  for (int i = 1; i <= n; i++) dis[i] = INF;
  while (!hp.empty()) hp.pop();
  hp.push(make_pair(dis[s] = 0, s));
  while (!hp.empty()) {
    int u = hp.top().second;
    long long nd = hp.top().first;
    hp.pop();
    if (dis[u] != nd) continue;
    for (int i = G.fir[u]; i; i = G.e[i].ne) {
      int v = G.e[i].to;
      if (dis[v] > dis[u] + G.e[i].w) {
        dis[v] = dis[u] + G.e[i].w;
        hp.push(make_pair(dis[v], v));
      }
    }
  }
}
int anc[MAXN][20], dep[MAXN], lg[MAXN], fa[MAXN];
inline int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = lg[dep[x]]; ~i; i--)
    if (dep[anc[x][i]] >= dep[y]) x = anc[x][i];
  if (x == y) return x;
  for (int i = lg[dep[x]]; ~i; i--)
    if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
  return anc[x][0];
}
int q[MAXN], he = 1, ta = 0;
inline void topo(int s) {
  he = 1;
  ta = 0;
  q[++ta] = s;
  while (he <= ta) {
    int u = q[he++];
    dep[u] = dep[anc[u][0] = fa[u]] + 1;
    for (int i = 1; i <= lg[dep[u]]; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
    if (fa[u]) G.join(fa[u], u);
    for (int i = T.fir[u]; i; i = T.e[i].ne) {
      int v = T.e[i].to;
      if (fa[v])
        fa[v] = LCA(fa[v], u);
      else
        fa[v] = u;
      if (!--deg[v]) q[++ta] = v;
    }
  }
}
int siz[MAXN];
void dfs(int u) {
  siz[u] = 1;
  for (int i = G.fir[u]; i; i = G.e[i].ne) {
    int v = G.e[i].to;
    dfs(v);
    siz[u] += siz[v];
  }
}
int x[MAXM], y[MAXM];
inline void rebuild() {
  for (int u = 1; u <= n; u++) {
    if (dis[u] == INF) continue;
    for (int i = G.fir[u]; i; i = G.e[i].ne) {
      int v = G.e[i].to;
      if (dis[v] == INF) continue;
      if (dis[v] == dis[u] + G.e[i].w) T.join(u, v), ++deg[v];
    }
  }
}
int main() {
  int s;
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= m; i++) {
    int w;
    scanf("%d%d%d", &x[i], &y[i], &w);
    G.join(x[i], y[i], w);
    G.join(y[i], x[i], w);
  }
  dijk(s);
  rebuild();
  G.reset();
  topo(s);
  dfs(s);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (i != s) ans = max(ans, siz[i]);
  printf("%d\n", ans);
  return 0;
}
