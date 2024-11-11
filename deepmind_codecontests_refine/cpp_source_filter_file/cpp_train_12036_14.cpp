#include <bits/stdc++.h>
using namespace std;
const int m = 256;
int n, Q, sl, fh, ans, rt_num, fa[50010], dep[50010], vis[50010], lst[50010],
    val[50010], f[50010][m], mx[50010][m];
int t, h[50010];
struct Tre {
  int to, nxt;
} e[50010 << 1];
struct Trie {
  int sn[2];
} tre[1 << 10];
int rd() {
  sl = 0;
  fh = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') sl = sl * 10 + ch - '0', ch = getchar();
  return sl * fh;
}
void add(int u, int v) {
  e[++t] = (Tre){v, h[u]};
  h[u] = t;
  e[++t] = (Tre){u, h[v]};
  h[v] = t;
}
void ins(int x) {
  int rt = 0;
  for (int i = 7; ~i; --i) {
    if (!tre[rt].sn[(x >> i) & 1]) {
      tre[rt].sn[(x >> i) & 1] = ++rt_num;
      tre[rt_num] = (Trie){{0, 0}};
    }
    rt = tre[rt].sn[(x >> i) & 1];
  }
}
int query(int x, int u) {
  int d, v = 0, rt = 0, ret = 0;
  for (int i = 7; ~i; --i) {
    d = ((x >> i) & 1) ^ 1;
    if (tre[rt].sn[d])
      rt = tre[rt].sn[d], ret |= 1 << i;
    else
      rt = tre[rt].sn[d ^ 1];
    v |= d << i;
  }
  return ret << 8 | mx[u][v];
}
void upd(int &x, int y) {
  if (y > x) x = y;
}
void dfs(int u) {
  int v, i;
  if (dep[u] >= m) {
    rt_num = 0;
    tre[0] = (Trie){{0, 0}};
    for (i = u; dep[u] - dep[i] < m; i = fa[i]) {
      upd(mx[u][val[i] >> 8], (dep[u] - dep[i] ^ val[i]) & 255);
      if (vis[val[i] >> 8] != u) ins(val[i] >> 8), vis[val[i] >> 8] = u;
    }
    lst[u] = i;
    for (i = 0; i < m; ++i) f[u][i] = query(i, u);
  }
  for (i = h[u]; i; i = e[i].nxt)
    if ((v = e[i].to) != fa[u]) {
      fa[v] = u;
      dep[v] = dep[u] + 1;
      dfs(v);
    }
}
int main() {
  n = rd();
  Q = rd();
  int x, y, dis;
  for (int i = 1; i <= n; ++i) val[i] = rd();
  for (int i = 1; i < n; ++i) x = rd(), y = rd(), add(x, y);
  dep[1] = 1;
  dfs(1);
  while (Q--) {
    x = rd();
    y = rd();
    dis = ans = 0;
    for (; dep[y] - dep[x] >= m; y = lst[y], dis++) ans = max(ans, f[y][dis]);
    for (dis <<= 8; y != fa[x]; y = fa[y], dis++) ans = max(ans, val[y] ^ dis);
    printf("%d\n", ans);
  }
}
