#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int res = 0;
  register char c = getchar(), f = 1;
  while (c < 48 || c > 57) {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= 48 && c <= 57)
    res = (res << 3) + (res << 1) + (c & 15), c = getchar();
  return f ? res : -res;
}
const int N = 200010, M = 400010;
int tot = 1, c[M][26], fa[M], len[M], pos[N], lst = 1;
inline void insert(int ch, int id) {
  int p = lst, np = lst = ++tot;
  len[np] = len[p] + 1, pos[id] = np;
  for (; p && !c[p][ch]; p = fa[p]) c[p][ch] = np;
  if (!p) {
    fa[np] = 1;
    return;
  }
  int q = c[p][ch];
  if (len[q] == len[p] + 1) {
    fa[np] = q;
    return;
  }
  int nq = ++tot;
  memcpy(c[nq], c[q], sizeof(c[q]));
  fa[nq] = fa[q], fa[q] = fa[np] = nq;
  len[nq] = len[p] + 1;
  for (; c[p][ch] == q; p = fa[p]) c[p][ch] = nq;
}
int n, m, dfn[M * 2], id = 0;
int ff[M][19], dep[M];
char a[N];
vector<int> e[M];
inline void adde(int x, int y) { e[x].push_back(y); }
void dfs(int u) {
  dfn[u] = ++id;
  for (int i = 0; ff[u][i]; ++i) ff[u][i + 1] = ff[ff[u][i]][i];
  for (int v : e[u]) ff[v][0] = u, dep[v] = dep[u] + 1, dfs(v);
  dfn[u + tot] = ++id;
}
inline int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int t = dep[x] - dep[y];
  for (int i = 0; t; ++i, t >>= 1) x = t & 1 ? ff[x][i] : x;
  if (x == y) return x;
  for (int i = 18; ~i; --i)
    if (ff[x][i] != ff[y][i]) x = ff[x][i], y = ff[y][i];
  return ff[x][0];
}
int nc, nd, it[M * 2], sta[M];
inline bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
bool vis[M];
long long f[M][2], ans;
int main() {
  n = read(), m = read();
  scanf("%s", a + 1);
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) insert(a[i] - 97, i);
  for (int i = 2; i <= tot; ++i) adde(fa[i], i);
  dep[1] = 1, dfs(1);
  while (m--) {
    nc = read(), nd = read();
    int x, k, top = 0;
    for (int i = 1; i <= nc; ++i) {
      x = pos[n - read() + 1], it[++top] = x;
      f[x][0] = 1, vis[x] = 1;
    }
    for (int i = 1; i <= nd; ++i) {
      x = pos[n - read() + 1], vis[x] ? 0 : it[++top] = x;
      f[x][1] = 1, vis[x] = 1;
    }
    sort(it + 1, it + top + 1, cmp);
    k = top, it[++top] = it[1] + tot;
    for (int i = 2; i <= k; ++i) {
      it[++top] = it[i] + tot;
      int f = lca(it[i], it[i - 1]);
      if (!vis[f]) it[++top] = f, it[++top] = f + tot, vis[f] = 1;
    }
    sort(it + 1, it + top + 1, cmp);
    k = top, ans = 0;
    for (int i = 1, top = 0; i <= k; ++i) {
      if (it[i] <= tot)
        sta[++top] = it[i], ans += len[it[i]] * f[it[i]][0] * f[it[i]][1];
      else {
        int v = sta[top--];
        if (top) {
          int u = sta[top];
          ans += len[u] * (f[u][0] * f[v][1] + f[u][1] * f[v][0]);
          f[u][0] += f[v][0], f[u][1] += f[v][1];
        }
        f[v][0] = f[v][1] = 0;
      }
    }
    printf("%I64d\n", ans);
    for (int i = 1; i <= k; ++i) vis[i] = 0;
  }
}
