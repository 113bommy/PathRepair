#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  char c;
  int num = 0, flg = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flg = -1;
  while (c >= '0' && c <= '9') {
    num = num * 10 + c - 48;
    c = getchar();
  }
  return num * flg;
}
int fir[100005], to[2 * 100005], nxt[2 * 100005], cnt;
int fa[100005], son[100005], siz[100005], top[100005], dep[100005], dfn[100005],
    dc;
int b[100005], bct, all, stk[100005], TP;
int f[100005], g[100005];
bool vis[100005];
const int INF = 0x3f3f3f3f;
void adde(int a, int b) {
  to[++cnt] = b;
  nxt[cnt] = fir[a];
  fir[a] = cnt;
}
void dfs(int u) {
  dfn[u] = ++dc;
  siz[u] = 1;
  dep[u] = dep[fa[u]] + 1;
  for (int v, p = fir[u]; p; p = nxt[p])
    if ((v = to[p]) != fa[u]) {
      fa[v] = u;
      dfs(v);
      siz[u] += siz[v];
      if (siz[son[u]] < siz[v]) son[u] = v;
    }
}
void pdfs(int u) {
  if (son[u]) top[son[u]] = top[u], pdfs(son[u]);
  for (int v, p = fir[u]; p; p = nxt[p])
    if ((v = to[p]) != fa[u] && v != son[u]) top[v] = v, pdfs(v);
}
int LCA(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
void DP(int u) {
  for (int v, p = fir[u]; p; p = nxt[p]) {
    v = to[p];
    DP(v);
    if (vis[u])
      f[u] += f[v] + g[v];
    else
      f[u] += f[v], g[u] += g[v];
  }
  if (vis[u])
    g[u] = 1;
  else {
    if (g[u] > 1) f[u]++;
    g[u] = 0;
  }
}
int main() {
  int n, m, i, u, v, k;
  n = gi();
  for (i = 1; i < n; i++) {
    u = gi();
    v = gi();
    adde(u, v);
    adde(v, u);
  }
  dfs(1);
  top[1] = 1;
  pdfs(1);
  memset(fir, 0, sizeof(fir));
  cnt = 0;
  m = gi();
  while (m--) {
    k = gi();
    bool flg = 0;
    for (i = 1; i <= k; i++) {
      b[i] = gi();
      vis[b[i]] = 1;
      if (b[i] == 1) flg = 1;
    }
    if (!flg) b[++k] = 1;
    bct = k;
    flg = 0;
    for (i = 1; i <= k; i++)
      if (vis[b[i]] && vis[fa[b[i]]]) {
        flg = 1;
        break;
      }
    if (flg) {
      printf("-1\n");
      for (i = 1; i <= bct; i++) vis[b[i]] = 0;
      continue;
    }
    sort(b + 1, b + k + 1, cmp);
    TP = 0;
    stk[++TP] = b[1];
    for (i = 2; i <= k; i++) {
      int lca = LCA(b[i], stk[TP]);
      if (lca == stk[TP]) {
        stk[++TP] = b[i];
        continue;
      }
      while (TP > 1 && dep[stk[TP - 1]] >= dep[lca]) {
        adde(stk[TP - 1], stk[TP]);
        TP--;
      }
      if (lca != stk[TP]) {
        adde(lca, stk[TP]);
        stk[TP] = lca;
        b[++bct] = lca;
      }
      stk[++TP] = b[i];
    }
    while (TP > 1) adde(stk[TP - 1], stk[TP]), TP--;
    DP(1);
    printf("%d\n", f[1]);
    cnt = 0;
    for (i = 1; i <= bct; i++) {
      fir[b[i]] = vis[b[i]] = g[b[i]] = f[b[i]] = 0;
    }
  }
}
