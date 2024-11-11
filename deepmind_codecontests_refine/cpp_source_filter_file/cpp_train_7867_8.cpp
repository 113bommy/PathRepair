#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, S, T, sz;
int fir[20005 * 16], cur[20005 * 16], nxt[20005 * 16 * 4], to[20005 * 16 * 4],
    c[20005 * 16 * 4], tot = 1;
void line(int x, int y, int z) {
  nxt[++tot] = fir[x], fir[x] = tot, to[tot] = y, c[tot] = z;
  nxt[++tot] = fir[y], fir[y] = tot, to[tot] = x, c[tot] = 0;
}
int dis[20005 * 16];
bool BFS() {
  memset(dis, -1, (sz + 1) << 2);
  static int q[20005 * 16], l, r;
  dis[q[l = r = 1] = T] = 0;
  while (l <= r) {
    int u = q[l++];
    for (int i = fir[u], v; i; i = nxt[i])
      if (c[i ^ 1] && dis[v = to[i]] == -1) dis[q[++r] = v] = dis[u] + 1;
  }
  return ~dis[S];
}
int aug(int u, int augco) {
  if (u == T) return augco;
  int need = augco, dt;
  for (int &i = cur[u]; i; i = nxt[i])
    if (c[i] && dis[u] == dis[to[i]] + 1) {
      dt = aug(to[i], min(c[i], need)), c[i] -= dt, c[i ^ 1] += dt;
      if (!(need -= dt)) return augco;
    }
  return augco - need;
}
vector<int> G[20005], E[20005];
int dep[20005], f[15][20005], id[15][20005], lg[20005];
void dfs(int u, int ff) {
  dep[u] = dep[f[0][u] = ff] + 1;
  for (int i = 0, lim = G[u].size() - 1, v; i <= lim; i++)
    if ((v = G[u][i]) != ff) line(id[0][v] = E[u][i], T, 1), dfs(v, u);
}
int getk(int u, int k) {
  for (int i = 0; k; k >>= 1, i++)
    if (k & 1) u = f[k][u];
  return u;
}
int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  if ((u = getk(u, dep[u] - dep[v])) == v) return u;
  for (int i = 14; i >= 0; i--)
    if (f[i][u] ^ f[i][v]) u = f[i][u], v = f[i][v];
  return f[0][u];
}
void Add(int t, int x, int y) {
  if (x == y) return;
  int k = lg[dep[x] - dep[y]];
  line(t, id[k][x], inf),
      line(t, id[k][getk(x, dep[x] - dep[y] - (1 << k))], inf);
}
int main() {
  scanf("%d%d", &n, &m), sz = n + m, S = ++sz, T = ++sz;
  for (int i = 1, x, y; i < n; i++)
    scanf("%d%d", &x, &y), G[x].push_back(y), G[y].push_back(x),
        E[x].push_back(i), E[y].push_back(i);
  dfs(1, 0);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int j = 1; j <= 14; j++)
    for (int i = 1; i <= n; i++)
      if (f[j][i] = f[j - 1][f[j - 1][i]])
        id[j][i] = ++sz, line(sz, id[j - 1][i], inf),
        line(sz, id[j - 1][f[j - 1][i]], inf);
  for (int k = n + 1, x, y; k <= n + m; k++) {
    scanf("%d%d", &x, &y), line(S, k, 1);
    int z = LCA(x, y);
    Add(k, x, z), Add(k, y, z);
  }
  int flow = 0;
  vector<int> a, b;
  while (BFS()) memcpy(cur, fir, (sz + 1) << 2), flow += aug(S, inf);
  printf("%d\n", flow);
  for (int i = n + 1; i <= n + m; i++)
    if (~dis[i]) a.push_back(i - n);
  for (int i = 1; i < n; i++)
    if (dis[i] == -1) b.push_back(i);
  printf("%d", a.size());
  for (int x : a) printf(" %d", x);
  printf("\n%d", b.size());
  for (int x : b) printf(" %d", x);
}
