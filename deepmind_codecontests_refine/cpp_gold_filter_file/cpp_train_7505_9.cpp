#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
inline int read() {
  int s = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return s;
}
int n, q;
vector<int> G[N];
map<int, int> mp[N];
int dfn[N], low[N], dfn_t;
int dep[N], fa[N][20];
void dfs(int u, int f) {
  dep[u] = dep[f] + 1;
  fa[u][0] = f;
  dfn[u] = ++dfn_t;
  for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : G[u]) {
    if (v != f) dfs(v, u);
  }
  low[u] = dfn_t;
}
int tag[N << 3], sum[N << 3];
inline void up(int rt, int l, int r) {
  if (tag[rt])
    sum[rt] = r - l + 1;
  else
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
inline void update(int rt, int l, int r, int L, int R, int v) {
  if (L > R || L < 1 || R > n) return;
  if (L <= l && r <= R) {
    tag[rt] += v;
    up(rt, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) update(rt << 1, l, mid, L, R, v);
  if (R > mid) update(rt << 1 | 1, mid + 1, r, L, R, v);
  up(rt, l, r);
}
int main() {
  n = read(), q = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0);
  while (q--) {
    int x = read(), y = read(), w;
    if (dfn[x] > dfn[y]) swap(x, y);
    if (!mp[x][y])
      mp[x][y] = 1, w = 1;
    else
      mp[x][y] = 0, w = -1;
    if (low[x] >= low[y]) {
      int z = y;
      for (int j = 19; j >= 0; j--)
        if (dep[fa[z][j]] > dep[x]) z = fa[z][j];
      update(1, 1, n, dfn[z], dfn[y] - 1, w);
      update(1, 1, n, low[y] + 1, low[z], w);
    } else {
      update(1, 1, n, 1, dfn[x] - 1, w);
      update(1, 1, n, low[x] + 1, dfn[y] - 1, w);
      update(1, 1, n, low[y] + 1, n, w);
    }
    printf("%d\n", n - sum[1]);
  }
  return 0;
}
