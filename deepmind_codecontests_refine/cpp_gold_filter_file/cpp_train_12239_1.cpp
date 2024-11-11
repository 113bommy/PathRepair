#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, oo = inf;
inline long long read() {
  register long long x = 0, f = 1;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return x * f;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void write(long long x, char c) {
  write(x);
  putchar(c);
}
void writeln(long long x) {
  write(x);
  puts("");
}
const int maxn = 300005;
vector<int> edge[maxn];
void Addedge(int a, int b) { edge[a].push_back(b); }
int son[maxn], fa[maxn], deep[maxn], size[maxn], pos[maxn], Ipos[maxn],
    top[maxn];
struct Query {
  int x, t, id;
  bool operator<(const Query &w) const { return t != w.t ? t < w.t : x < w.x; }
} q[maxn];
void dfs(int u) {
  size[u] = 1;
  for (auto v : edge[u]) {
    deep[v] = deep[u] + 1;
    dfs(v);
    size[u] += size[v];
    if (size[son[u]] < size[v]) son[u] = v;
  }
}
int dfsclk;
void divide(int u, int chain) {
  pos[u] = ++dfsclk;
  Ipos[dfsclk] = u;
  top[u] = chain;
  if (son[u]) divide(son[u], chain);
  for (auto v : edge[u]) {
    if (v == son[u]) continue;
    divide(v, v);
  }
}
struct treenode {
  int cov, max;
} tree[2000000];
inline void pushdown(int o, int l, int r) {
  if (tree[o].cov > -inf) {
    tree[o].max = tree[o].cov + 2 * (r - l);
    tree[(o << 1)].cov = tree[o].cov;
    tree[(o << 1 | 1)].cov = tree[o].cov + 2 * (((l + r) >> 1) - l + 1);
    tree[o].cov = -inf;
  }
  return;
}
inline void pushup(int o, int l, int r) {
  pushdown((o << 1), l, ((l + r) >> 1));
  pushdown((o << 1 | 1), ((l + r) >> 1) + 1, r);
  tree[o].max = max(tree[(o << 1)].max, tree[(o << 1 | 1)].max);
  return;
}
inline void Insert(int o, int l, int r, int x, int y, int z) {
  pushdown(o, l, r);
  if (l == x && r == y) {
    tree[o].cov = z;
    return;
  }
  if (y <= ((l + r) >> 1))
    Insert((o << 1), l, ((l + r) >> 1), x, y, z);
  else if (((l + r) >> 1) + 1 <= x)
    Insert((o << 1 | 1), ((l + r) >> 1) + 1, r, x, y, z);
  else
    Insert((o << 1), l, ((l + r) >> 1), x, ((l + r) >> 1), z),
        Insert((o << 1 | 1), ((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, y,
               z + 2 * (((l + r) >> 1) - x + 1));
  pushup(o, l, r);
  return;
}
inline int query(int o, int l, int r, int x, int y, int v) {
  pushdown(o, l, r);
  if (tree[o].max <= v) return 0;
  if (l == r) return l;
  if (y <= ((l + r) >> 1))
    return query((o << 1), l, ((l + r) >> 1), x, y, v);
  else if (((l + r) >> 1) + 1 <= x)
    return query((o << 1 | 1), ((l + r) >> 1) + 1, r, x, y, v);
  int tmp =
      query((o << 1 | 1), ((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, y, v);
  if (tmp) return tmp;
  return query((o << 1), l, ((l + r) >> 1), x, ((l + r) >> 1), v);
}
int n, m;
inline int ask(int x, int y) {
  int u = x, t, tt, res, z;
  for (;;) {
    tt = query(1, 1, n, pos[top[u]], pos[u], y + deep[x]);
    if (tt)
      t = Ipos[tt];
    else
      t = 0;
    if (t) break;
    u = fa[top[u]];
  }
  res = y + 2 * (deep[x] - deep[t]);
  z = y + deep[x] - 2 * deep[t];
  for (;;) {
    if (pos[top[x]] <= pos[t]) {
      if (pos[t] < pos[x])
        Insert(1, 1, n, pos[t] + 1, pos[x], z + 2 * deep[t] + 2);
      break;
    } else {
      Insert(1, 1, n, pos[top[x]], pos[x], z + 2 * deep[top[x]]);
      x = fa[top[x]];
    }
  }
  return res;
}
int ans[maxn];
int main() {
  n = read(), m = read();
  n++;
  for (register int i = (1); i < (n); ++i) {
    fa[i + 1] = read() + 1;
    Addedge(fa[i + 1], i + 1);
  }
  dfs(1);
  dfsclk = 0;
  divide(1, 1);
  for (register int i = (1); i <= (m); ++i) {
    q[i].x = read() + 1;
    q[i].t = read() + deep[q[i].x];
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m);
  Insert(1, 1, n, 1, n, 1 - inf);
  Insert(1, 1, n, 1, 1, inf + inf);
  for (register int i = (1); i <= (m); ++i) {
    ans[q[i].id] = ask(q[i].x, q[i].t - deep[q[i].x]);
  }
  for (register int i = (1); i <= (m); ++i) printf("%d ", ans[i]);
  return 0;
}
