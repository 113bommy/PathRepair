#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, maxm = 3e5 + 5, maxq = 5e5 + 5;
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  x *= f;
}
struct edge {
  int u, v, next;
  edge(int u, int v, int next) : u(u), v(v), next(next) {}
  edge() {}
} e[maxn << 1];
int head[maxn << 1], ecnt;
inline void add(int u, int v) {
  e[ecnt] = edge(u, v, head[u]);
  head[u] = ecnt++;
}
struct Edge {
  int u, v, opt;
  Edge(int u, int v, int opt) : u(u), v(v), opt(opt){};
  Edge() {}
  inline bool operator<(const Edge &T) const { return opt > T.opt; }
} E[maxm];
int n, m, q, a[maxn], tim[maxn << 1];
pair<int, int> ques[maxq];
int qcnt;
int fa[maxn << 1], tot;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
namespace Segment_Tree {
struct node {
  int l, r;
  pair<int, int> Max;
  node(int l, int r, pair<int, int> Max) : l(l), r(r), Max(Max) {}
  node() {}
} tree[maxn << 3];
inline void update(int p) {
  tree[p].Max = max(tree[(p << 1)].Max, tree[(p << 1 | 1)].Max);
}
inline void build(int p, int l, int r) {
  tree[p] = node(l, r, make_pair(0, l));
  if (l == r) return;
  int mid = (l + r) >> 1;
  build((p << 1), l, mid);
  build((p << 1 | 1), mid + 1, r);
}
void modify(int p, int ps, int d) {
  int l = tree[p].l, r = tree[p].r;
  if (l == r) return tree[p].Max.first = d, void();
  int mid = (l + r) >> 1;
  if (ps <= mid)
    modify((p << 1), ps, d);
  else
    modify((p << 1 | 1), ps, d);
  update(p);
}
pair<int, int> query(int p, int L, int R) {
  int l = tree[p].l, r = tree[p].r;
  if (L <= l && r <= R) return tree[p].Max;
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query((p << 1), L, R);
  else if (L > mid)
    return query((p << 1 | 1), L, R);
  else
    return max(query((p << 1), L, R), query((p << 1 | 1), L, R));
}
}  // namespace Segment_Tree
int dfn[maxn << 1], siz[maxn << 1], p[maxn << 1][21], dfs_cnt;
void dfs(int u, int fa) {
  dfn[u] = ++dfs_cnt;
  siz[u] = 1;
  p[u][0] = fa;
  for (int i = 1; i <= 20; ++i) p[u][i] = p[p[u][i - 1]][i - 1];
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].v;
    dfs(v, u);
    siz[u] += siz[v];
  }
  if (u <= n) Segment_Tree::modify(1, dfn[u], a[u]);
}
inline int query(int x, int id) {
  for (int i = 20; i >= 0; --i)
    if (tim[p[x][i]] >= id) x = p[x][i];
  pair<int, int> Max = Segment_Tree::query(1, dfn[x], dfn[x] + siz[x] - 1);
  if (!Max.first) return 0;
  Segment_Tree::modify(1, Max.second, 0);
  return Max.first;
}
int main() {
  read(n), read(m), read(q);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= m; ++i) read(E[i].u), read(E[i].v), E[i].opt = q + 1;
  for (int i = 1, opt, x; i <= q; ++i) {
    read(opt), read(x);
    if (opt == 1)
      ques[++qcnt] = make_pair(x, i);
    else
      E[x].opt = i;
  }
  sort(E + 1, E + m + 1);
  for (int i = 1; i <= n; ++i) {
    ++tot;
    fa[tot] = tot, tim[tot] = q + 1;
  }
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= m; ++i) {
    int u = E[i].u, v = E[i].v;
    int x = find(u), y = find(v);
    if (x == y) continue;
    ++tot;
    tim[tot] = E[i].opt;
    fa[x] = fa[y] = fa[tot] = tot;
    add(tot, x);
    add(tot, y);
  }
  Segment_Tree::build(1, 1, tot);
  for (int i = 1; i <= tot; ++i)
    if (find(i) == i) dfs(i, 0);
  for (int i = 1; i <= qcnt; ++i)
    printf("%d\n", query(ques[i].first, ques[i].second));
  return 0;
}
