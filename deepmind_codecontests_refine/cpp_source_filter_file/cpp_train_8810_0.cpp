#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long n, q, op, root = 1;
long long a[maxn];
long long head[maxn], to[maxn << 1], nxt[maxn << 1], cnt;
inline void add(long long u, long long v) {
  nxt[++cnt] = head[u];
  to[cnt] = v;
  head[u] = cnt;
}
namespace Tree_chain_partition {
long long fa[maxn], son[maxn], size[maxn], dep[maxn], top[maxn];
void dfs1(long long u, long long f) {
  size[u] = 1;
  fa[u] = f;
  dep[u] = dep[f] + 1;
  for (register long long i = head[u]; i; i = nxt[i]) {
    long long v = to[i];
    if (v == f) continue;
    dfs1(v, u);
    size[u] += size[v];
    if (size[v] > size[son[u]]) son[u] = v;
  }
}
long long id[maxn], w[maxn], tot;
void dfs2(long long u, long long topf) {
  id[u] = ++tot;
  w[tot] = a[u];
  top[u] = topf;
  if (!son[u]) return;
  dfs2(son[u], topf);
  for (register long long i = head[u]; i; i = nxt[i]) {
    long long v = to[i];
    if (v == son[u] || v == fa[u]) continue;
    dfs2(v, v);
  }
}
inline long long lca(long long x, long long y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
long long find(long long x, long long y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    if (fa[top[x]] == y) return top[x];
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? son[x] : son[y];
}
inline long long LCA(long long x, long long y) {
  if (dep[x] > dep[y]) swap(x, y);
  if (lca(x, y) == x) {
    if (id[y] <= id[root] && id[root] <= id[y] + size[y] - 1) {
      return y;
    }
    if (lca(x, root) == x) return lca(root, y);
    return x;
  }
  if (id[root] >= id[x] && id[root] <= id[x] + size[x] - 1) return x;
  if (id[root] >= id[y] && id[root] <= id[y] + size[y] - 1) return y;
  if ((lca(x, root) == root && lca(x, y) == lca(root, y)) ||
      (lca(y, root) == root && lca(x, y) == lca(root, x))) {
    return root;
  }
  if (lca(x, root) == lca(y, root)) return lca(x, y);
  if (lca(x, y) != lca(x, root)) return lca(x, root);
  return lca(y, root);
}
}  // namespace Tree_chain_partition
using namespace Tree_chain_partition;
namespace SegmentTree {
struct SegmentTree {
  long long v, tag;
} st[maxn << 2];
inline void push_up(long long rt) {
  st[rt].v = st[rt << 1].v + st[rt << 1 | 1].v;
}
void build(long long rt, long long l, long long r) {
  st[rt].tag = 0;
  if (l == r) {
    st[rt].v = w[l];
    return;
  }
  long long mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  push_up(rt);
}
inline void push_down(long long rt, long long l, long long r) {
  long long mid = (l + r) >> 1;
  st[rt << 1].v += st[rt].tag * (mid - l + 1);
  st[rt << 1 | 1].v += st[rt].tag * (r - mid);
  st[rt << 1].tag += st[rt].tag;
  st[rt << 1 | 1].tag += st[rt].tag;
  st[rt].tag = 0;
}
void modify(long long rt, long long l, long long r, long long ql, long long qr,
            long long val) {
  if (ql > r || qr < l) return;
  if (ql <= l && qr >= r) {
    st[rt].v += (r - l + 1) * val;
    st[rt].tag += val;
    return;
  }
  push_down(rt, l, r);
  long long mid = (l + r) >> 1;
  modify(rt << 1, l, mid, ql, qr, val);
  modify(rt << 1 | 1, mid + 1, r, ql, qr, val);
  push_up(rt);
}
long long query(long long rt, long long l, long long r, long long ql,
                long long qr) {
  if (ql > r || qr < l) return 0;
  if (ql <= l && qr >= r) return st[rt].v;
  push_down(rt, l, r);
  long long mid = (l + r) >> 1;
  return query(rt << 1, l, mid, ql, qr) +
         query(rt << 1 | 1, mid + 1, r, ql, qr);
}
void update(long long pos, long long val) {
  if (root == pos) {
    modify(1, 1, n, 1, n, val);
    return;
  }
  long long tmp = lca(root, pos);
  if (tmp != pos) {
    modify(1, 1, n, id[pos], id[pos] + size[pos] - 1, val);
  } else {
    long long loc = find(root, pos);
    modify(1, 1, n, 1, n, val);
    modify(1, 1, n, id[loc], id[loc] + size[loc] - 1, -val);
  }
}
long long ask(long long pos) {
  if (pos == root) return query(1, 1, n, 1, n);
  long long tmp = lca(pos, root);
  if (tmp != pos) {
    return query(1, 1, n, id[pos], id[pos] + size[pos] - 1);
  }
  long long loc = find(root, pos);
  return query(1, 1, n, 1, n) -
         query(1, 1, n, id[loc], id[loc] + size[loc] - 1);
}
}  // namespace SegmentTree
using namespace SegmentTree;
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  x *= f;
}
signed main() {
  read(n);
  read(q);
  for (register long long i = 1; i <= n; i++) {
    read(a[i]);
  }
  for (register long long i = 1, u, v; i < n; i++) {
    read(u), read(v);
    add(u, v);
    add(v, u);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  build(1, 1, n);
  while (q--) {
    read(op);
    if (op == 1) read(root);
    if (op == 2) {
      long long x, y, val;
      read(x), read(y), read(val);
      update(LCA(x, y), val);
    }
    if (op == 3) {
      long long x;
      read(x);
      printf("%d\n", ask(x));
    }
  }
  return 0;
}
