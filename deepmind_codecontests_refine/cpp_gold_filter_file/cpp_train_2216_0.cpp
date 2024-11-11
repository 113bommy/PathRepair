#include <bits/stdc++.h>
int n;
int hd[105], _hd = 1;
struct edge {
  int v, nxt;
} e[105 << 1];
inline void addedge(int u, int v) {
  e[++_hd] = (edge){v, hd[u]};
  hd[u] = _hd;
}
int w[105];
bool del[105];
__int128_t f[105], g[105];
std::vector<int> son[105];
inline bool chk(int u, __int128_t x, int tp = 0) {
  for (auto v : son[u]) g[v] = 0;
  for (int i = n; i; i--)
    if (x & (__int128_t(1) << i)) {
      int o = -1;
      for (auto v : son[u])
        if (o == -1 || f[v] - g[v] > f[o] - g[o]) o = v;
      g[o] += __int128_t(1) << i;
    }
  if (tp)
    for (auto v : son[u]) f[v] = g[v];
  for (auto v : son[u])
    if (f[v] >= g[v]) return 0;
  return 1;
}
inline void dfs(int u, int fa) {
  for (int i = hd[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa) continue;
    son[u].push_back(v);
    dfs(v, u);
  }
  for (int i = 1; i <= n; i++) f[u] |= __int128_t(1) << i;
  for (int i = n; i; i--) {
    f[u] ^= __int128_t(1) << i;
    if (!chk(u, f[u])) f[u] ^= __int128_t(1) << i;
  }
  chk(u, f[u], 1);
  for (int i = hd[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa) continue;
    for (int j = 1; j <= n; j++)
      if (f[v] & (__int128_t(1) << j)) {
        w[i >> 1] = j;
        break;
      }
  }
}
int cur;
inline void qry(int u, int fa) {
  for (int i = hd[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa || del[i >> 1]) continue;
    if (cur == -1 || w[i >> 1] > w[cur]) cur = (i >> 1);
    qry(v, u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  dfs(1, 0);
  int u = 1;
  while (1) {
    cur = -1;
    qry(u, 0);
    if (cur == -1) break;
    del[cur] = 1;
    printf("? %d %d\n", e[cur << 1].v, e[cur << 1 | 1].v);
    fflush(stdout);
    scanf("%d", &u);
  }
  printf("! %d\n", u);
}
