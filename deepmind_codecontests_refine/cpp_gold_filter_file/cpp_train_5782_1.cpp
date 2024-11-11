#include <bits/stdc++.h>
using namespace std;
struct Ed {
  int u, v, w;
} E[600010];
int idx[300005], Si = 0, nxt[600010];
int n, m, q, dfn[300005], low[300005], cnt, St[300005], is[300005],
    belong[300005], N, st, A[300005];
int F[300005][20], dis[300005], dep[300005], f[300005];
void tarjan(int u, int fa) {
  is[u] = 1;
  St[++st] = u;
  dfn[u] = low[u] = ++cnt;
  for (int i = idx[u]; i + 1; i = nxt[i])
    if (E[i].v != fa) {
      if (!dfn[E[i].v])
        tarjan(E[i].v, u), low[u] = min(low[u], low[E[i].v]);
      else if (dfn[E[i].v] < dfn[u])
        low[u] = min(low[u], dfn[E[i].v]);
    }
  if (dfn[u] == low[u]) {
    int v = St[st--];
    is[v] = 0;
    belong[v] = ++N;
    for (; st && v != u; v = St[st--], is[v] = 0, belong[v] = N)
      ;
  }
}
void dfs(int u, int fa) {
  int i;
  for (i = 1, F[u][0] = fa; i < 20; i++) F[u][i] = F[F[u][i - 1]][i - 1];
  for (i = idx[u]; i + 1; i = nxt[i])
    if (E[i].v != fa) {
      dep[E[i].v] = dep[u] + 1;
      dis[E[i].v] = dis[u] + A[E[i].v] + E[i].w;
      dfs(E[i].v, u);
    }
}
int lca(int x, int y) {
  if (dep[y] > dep[x]) swap(x, y);
  for (int t = dep[x] - dep[y], i = 0; t; t >>= 1, i++)
    if (t & 1) x = F[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; i--)
    if (F[x][i] - F[y][i]) x = F[x][i], y = F[y][i];
  return F[x][0];
}
int gf(int x) { return x == f[x] ? x : f[x] = gf(f[x]); }
int main() {
  memset(idx, -1, sizeof(idx));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    E[Si] = (Ed){x, y, z};
    nxt[Si] = idx[x];
    idx[x] = Si++, E[Si] = (Ed){y, x, z};
    nxt[Si] = idx[y];
    idx[y] = Si++;
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, -1);
  memset(idx, -1, sizeof(idx));
  Si = 0;
  for (int i = 1; i <= N; i++) f[i] = i;
  for (int i = 0; i < 2 * m; i += 2) {
    int u = belong[E[i].u], v = belong[E[i].v];
    if (u == v)
      A[u] += E[i].w;
    else {
      int a = gf(u), b = gf(v);
      if (a != b) E[Si] = (Ed){u, v, E[i].w};
      nxt[Si] = idx[u];
      idx[u] = Si++, E[Si] = (Ed){v, u, E[i].w};
      nxt[Si] = idx[v];
      idx[v] = Si++, f[a] = b;
    }
  }
  dfs(1, 0);
  q = 1;
  for (; q--;) {
    int s, t;
    scanf("%d%d", &s, &t);
    int w = lca(belong[s], belong[t]);
    if (dis[belong[s]] + dis[belong[t]] - 2 * dis[w] + A[w])
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
