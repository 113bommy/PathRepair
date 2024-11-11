#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, q, t, xjh, color, color2, tot, tot2, top, top2, deep, deep2, mod;
int ru[N], chu[N], vis[N], vis2[N], dfn[N], dfn2[N], low[N], low2[N], col[N],
    col2[N];
int head[N], head2[N], zhan[N], zhan2[N], a[N], b[N], c[N], rt[N], x[N], y[N],
    f[N][20];
struct node {
  int too, Next;
} edge[N * 2], edge2[N * 2];
vector<int> g[N];
inline int read() {
  int ret = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    ret = ret * 10 + c - 48;
    c = getchar();
  }
  if (f) return -ret;
  return ret;
}
void add(int a, int b) {
  edge[++top].too = b;
  edge[top].Next = head[a];
  head[a] = top;
}
void add2(int a, int b) {
  edge2[++top2].too = b;
  edge2[top2].Next = head2[a];
  head2[a] = top2;
}
void tarjan(int u) {
  dfn[u] = low[u] = ++deep;
  zhan[++tot] = u;
  for (int i = head[u]; i; i = edge[i].Next) {
    if (vis[i]) continue;
    vis[i] = vis[i ^ 1] = 1;
    int v = edge[i].too;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    color++;
    col[u] = color;
    while (zhan[tot] != u) {
      col[zhan[tot]] = color;
      tot--;
    }
    tot--;
  }
}
void dfs(int u, int fa) {
  vis[u] = 1;
  f[u][0] = fa;
  ru[u] = ++t;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == fa) continue;
    dfs(v, u);
  }
  chu[u] = ++t;
}
bool pd(int x, int y) {
  if (ru[x] <= ru[y] && chu[x] >= chu[y]) return 1;
  return 0;
}
int LCA(int x, int y) {
  if (pd(x, y)) return x;
  if (pd(y, x)) return y;
  int k = x;
  for (int i = 19; i >= 0; i--)
    if (f[k][i] > 0 && (!pd(f[k][i], y))) k = f[k][i];
  return f[k][0];
}
bool cmp(int x, int y) {
  int k1 = (x > 0) ? ru[x] : chu[-x];
  int k2 = (y > 0) ? ru[y] : chu[-y];
  return k1 < k2;
}
void tarjan2(int u) {
  dfn2[u] = low2[u] = ++deep2;
  zhan2[++tot2] = u;
  for (int i = head2[u]; i; i = edge2[i].Next) {
    if (vis2[i]) continue;
    vis2[i] = vis2[i ^ 1] = 1;
    int v = edge2[i].too;
    if (!dfn2[v]) {
      tarjan2(v);
      low2[u] = min(low2[u], low2[v]);
    } else
      low2[u] = min(low2[u], dfn2[v]);
  }
  if (dfn2[u] == low2[u]) {
    color2++;
    col2[u] = color2;
    while (zhan2[tot2] != u) {
      col2[zhan2[tot2]] = color2;
      tot2--;
    }
    tot2--;
  }
}
int Read() {
  int x = read();
  x = (x + mod) % xjh;
  if (x == 0) x = xjh;
  return x;
}
signed main() {
  top = 1;
  n = xjh = read();
  m = read();
  q = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= n; i++)
    for (int j = head[i]; j; j = edge[j].Next) {
      int v = edge[j].too;
      if (col[i] != col[v]) g[col[i]].push_back(col[v]);
    }
  for (int i = 1; i <= n; i++) vis[i] = 0;
  for (int i = 1; i <= color; i++)
    if (!vis[i]) dfs(i, 0);
  for (int i = 1; i <= 19; i++)
    for (int j = 1; j <= color; j++) f[j][i] = f[f[j][i - 1]][i - 1];
  for (int I = 1; I <= q; I++) {
    top2 = 1;
    color2 = deep = tot = 0;
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) {
      a[i] = col[Read()];
      b[a[i]] = 1;
    }
    int jia = n;
    for (int i = 1; i <= jia; i++) c[i] = a[i];
    for (int i = 1; i <= m; i++) {
      x[i] = col[Read()];
      y[i] = col[Read()];
      if (x[i] == y[i]) continue;
      add2(x[i], y[i]);
      add2(y[i], x[i]);
      if (!b[x[i]]) a[++n] = x[i];
      if (!b[y[i]]) a[++n] = y[i];
      b[x[i]] = 1;
      b[y[i]] = 1;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i < n; i++) {
      int lca = LCA(a[i], a[i + 1]);
      if (!b[lca] && lca > 0) {
        a[++n] = lca;
        b[lca] = 1;
      }
    }
    int nn = n;
    for (int i = 1; i <= nn; i++) a[++n] = -a[i];
    sort(a + 1, a + n + 1, cmp);
    int gs = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] > 0)
        zhan[++tot] = a[i];
      else {
        int u = zhan[tot--];
        if (tot > 0) {
          int fa = zhan[tot];
          add2(fa, u);
          add2(u, fa);
        } else
          rt[++gs] = u;
        b[u] = 0;
      }
    }
    for (int i = 1; i <= gs; i++)
      if (!dfn2[rt[i]]) tarjan2(rt[i]);
    int xu = col2[c[1]];
    bool flag = 0;
    for (int i = 1; i <= jia; i++)
      if (col2[c[i]] != xu) flag = 1;
    if (flag)
      puts("NO");
    else {
      puts("YES");
      mod = (mod + I) % xjh;
    }
    for (int i = 1; i <= n; i++)
      head2[a[i]] = dfn2[a[i]] = low2[a[i]] = col2[a[i]] = 0;
    for (int i = 1; i <= m; i++) {
      head2[x[i]] = dfn2[x[i]] = low2[x[i]] = col2[x[i]] = 0;
      head2[y[i]] = dfn2[y[i]] = low2[y[i]] = col2[y[i]] = 0;
    }
    for (int i = 1; i <= top2; i++) vis2[i] = 0;
  }
  return 0;
}
