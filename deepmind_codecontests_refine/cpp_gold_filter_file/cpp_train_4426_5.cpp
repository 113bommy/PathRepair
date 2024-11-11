#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int r, s = 0, c;
  for (; !isdigit(c = getchar()); s = c)
    ;
  for (r = c ^ 48; isdigit(c = getchar()); (r *= 10) += c ^ 48)
    ;
  return s ^ 45 ? r : -r;
}
const int N = 100010, maxn = N << 6;
int n, m, q;
struct edge {
  int to, next;
} mem[N << 1], mem1[N << 1];
int head[N], cnt = 1, head1[N], cnt1 = 1;
inline void add(int u, int v) {
  mem[++cnt].next = head[u];
  mem[cnt].to = v;
  head[u] = cnt;
}
inline void add1(int u, int v) {
  mem1[++cnt1].next = head1[u];
  mem1[cnt1].to = v;
  head1[u] = cnt1;
}
int rt[N], sz[maxn], ls[maxn], rs[maxn], tot;
void build(int &rt, int l, int r) {
  rt = ++tot;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(ls[rt], l, mid);
  build(rs[rt], mid + 1, r);
}
void modify(int &rt, int o, int l, int r, int x) {
  rt = ++tot;
  ls[rt] = ls[o], rs[rt] = rs[o];
  if (l == r) {
    sz[rt] = sz[o] + 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(ls[rt], ls[o], l, mid, x);
  else
    modify(rs[rt], rs[o], mid + 1, r, x);
  sz[rt] = sz[ls[rt]] + sz[rs[rt]];
}
int fa[N][20];
int dep[N];
void dfs(int u, int father) {
  rt[u] = ++tot;
  ls[tot] = ls[rt[father]], rs[tot] = rs[rt[father]], sz[tot] = sz[rt[father]];
  for (int i = head1[u]; i > 0; i = mem1[i].next) {
    int numm = mem1[i].to;
    modify(rt[u], rt[u], 1, m, numm);
  }
  dep[u] = dep[father] + 1;
  for (int i = 1; (1 << i) <= dep[u]; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = head[u]; i > 0; i = mem[i].next) {
    int to = mem[i].to;
    if (to == father) continue;
    fa[to][0] = u;
    dfs(to, u);
  }
}
int lca(int u, int v) {
  if (u == v) return u;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 18; i >= 0; --i)
    if (dep[v] + (1 << i) <= dep[u]) u = fa[u][i];
  if (u == v) return u;
  for (int i = 18; i >= 0; --i)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
int query(int rt1, int rt2, int rt3, int rt4, int l, int r, int k) {
  if (l == r) return l;
  int sum = sz[ls[rt1]] + sz[ls[rt2]] - sz[ls[rt3]] - sz[ls[rt4]];
  int mid = (l + r) >> 1;
  if (sum >= k)
    return query(ls[rt1], ls[rt2], ls[rt3], ls[rt4], l, mid, k);
  else
    return query(rs[rt1], rs[rt2], rs[rt3], rs[rt4], mid + 1, r, k - sum);
}
int main() {
  n = read(), m = read(), q = read();
  int u, v, k, d, dd, ans;
  for (int i = 1; i < n; ++i) {
    u = read(), v = read();
    add(u, v), add(v, u);
  }
  for (int i = 1; i <= m; i++) {
    u = read();
    add1(u, i);
  }
  build(rt[0], 1, m);
  dfs(1, 0);
  while (q--) {
    u = read(), v = read(), k = read();
    d = lca(u, v), dd = fa[d][0];
    ans = sz[rt[u]] + sz[rt[v]] - sz[rt[d]] - sz[rt[dd]];
    ans = min(ans, k);
    printf("%d ", ans);
    for (int i = 1; i <= ans; i++)
      printf("%d ", query(rt[u], rt[v], rt[d], rt[dd], 1, m, i));
    cout << '\n';
  }
  return 0;
}
