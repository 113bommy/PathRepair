#include <bits/stdc++.h>
using namespace std;
inline void rd(int &x) {
  x = 0;
  char o;
  while (o = getchar(), o < 48)
    ;
  do x = (x << 3) + (x << 1) + (o ^ 48);
  while (o = getchar(), o > 47);
}
void pf(int x) {
  if (x == 0) return;
  pf(x / 10);
  putchar(x % 10 ^ 48);
}
inline void pt(int x) {
  pf(x);
  if (x == 0) putchar('0');
  putchar(' ');
}
int head[100005], to[100005 << 1], nxt[100005 << 1], tot;
inline void add(int a, int b) {
  to[++tot] = b;
  nxt[tot] = head[a];
  head[a] = tot;
}
int n, m, q, a, b, c, tp, ans[100005], st[100005 << 2][12], area[100005][12];
int id[100005], reid[100005], dfsid, sz[100005], son[100005], fa[100005],
    top[100005], deep[100005];
void dfs(int x, int f) {
  fa[x] = f;
  deep[x] = deep[f] + 1;
  sz[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa[x]) continue;
    dfs(y, x);
    sz[x] += sz[y];
    if (sz[y] > sz[son[x]]) son[x] = y;
  }
}
void chain(int x, int f) {
  top[x] = f;
  reid[id[x] = ++dfsid] = x;
  if (son[x]) chain(son[x], f);
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa[x] || y == son[x]) continue;
    chain(y, y);
  }
}
void build(int p = 1, int l = 1, int r = n) {
  if (l == r) {
    for (int i = 1; i <= area[reid[l]][0]; i++)
      st[p][++st[p][0]] = area[reid[l]][i];
    return;
  }
  int mid = l + r >> 1, x = 0, y = 0;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  while (st[p][0] < 10 && x < st[p << 1][0] && y < st[p << 1 | 1][0]) {
    if (st[p << 1][x + 1] < st[p << 1 | 1][y + 1])
      st[p][++st[p][0]] = st[p << 1][++x];
    else
      st[p][++st[p][0]] = st[p << 1 | 1][++y];
  }
  while (st[p][0] < 10 && x < st[p << 1][0])
    st[p][++st[p][0]] = st[p << 1][++x];
  while (st[p][0] < 10 && y < st[p << 1 | 1][0])
    st[p][++st[p][0]] = st[p << 1 | 1][++y];
}
void query(int a, int b, int p = 1, int l = 1, int r = n) {
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    for (int i = 1; i <= min(st[p][0], c); i++) ans[++ans[0]] = st[p][i];
    return;
  }
  int mid = l + r >> 1;
  query(a, b, p << 1, l, mid);
  query(a, b, p << 1 | 1, mid + 1, r);
}
int main() {
  rd(n), rd(m), rd(q);
  for (int i = 1; i < n; i++) rd(a), rd(b), add(a, b), add(b, a);
  dfs(1, 0), chain(1, 1);
  for (int i = 1; i <= m; i++) {
    rd(a);
    if (area[a][0] < 10) area[a][++area[a][0]] = i;
  }
  build();
  while (q--) {
    ans[0] = 0;
    rd(a), rd(b), rd(c);
    while (top[a] != top[b]) {
      if (deep[top[a]] < deep[top[b]]) swap(a, b);
      query(id[top[a]], id[a]);
      a = fa[top[a]];
    }
    if (deep[a] > deep[b]) swap(a, b);
    query(id[a], id[b]);
    sort(ans + 1, ans + 1 + ans[0]);
    pt(min(c, ans[0]));
    for (int i = 1; i <= min(c, ans[0]); i++) pt(ans[i]);
    puts("");
  }
  return 0;
}
