#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005, MAXM = 1000005 * 2;
int n, m, q;
int dfn[MAXN], low[MAXN], dcnt;
int st[MAXN], nm;
int f[MAXN][20];
struct edge {
  int v, c, nxt;
  edge() {}
  edge(int vv, int cc, int nn) { v = vv, c = cc, nxt = nn; }
};
struct Graph {
  edge E[MAXM];
  int head[MAXN], ecnt;
  void Init() {
    ecnt = 0;
    memset(head, 0, sizeof(head));
  }
  void addedge(int u, int v, int c = 0) {
    E[++ecnt] = edge(v, c, head[u]);
    head[u] = ecnt;
  }
} G1, G2;
bool vis[MAXN];
void TJ(int u, int fa) {
  dfn[u] = low[u] = ++dcnt;
  st[++st[0]] = u;
  for (int i = G1.head[u]; i; i = G1.E[i].nxt) {
    int v = G1.E[i].v;
    if (!dfn[v]) {
      TJ(v, u);
      low[u] = min(low[u], low[v]);
      if (dfn[u] <= low[v]) {
        nm++;
        int x;
        do {
          x = st[st[0]];
          G2.addedge(nm, x, 1);
          G2.addedge(x, nm, 1);
          st[0]--;
        } while (x != v);
        G2.addedge(nm, u, 1);
        G2.addedge(u, nm, 1);
      }
    } else
      low[u] = min(low[u], dfn[v]);
  }
}
int d[MAXN];
void dfs(int u, int fa) {
  f[u][0] = fa;
  d[u] = d[fa] + 1;
  for (int i = G2.head[u]; i; i = G2.E[i].nxt) {
    int v = G2.E[i].v;
    if (v != fa) dfs(v, u);
  }
}
void LCAInit() {
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= nm; j++) f[j][i] = f[f[j][i - 1]][i - 1];
}
int LCA(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  for (int i = 19; i >= 0; i--)
    if (d[f[x][i]] >= d[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; i--)
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  return f[x][0];
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G1.addedge(u, v);
    G1.addedge(v, u);
  }
  nm = n;
  TJ(1, 0);
  dfs(1, 0);
  LCAInit();
  for (int i = 1; i <= q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (d[a] + d[b]) / 2 - d[LCA(a, b)]);
  }
}
