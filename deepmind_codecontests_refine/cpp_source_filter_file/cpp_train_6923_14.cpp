#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
const unsigned long long p1 = 19260817, p2 = 1e9 + 7, B = 211;
template <class T>
inline bool read(T& x) {
  x = 0;
  bool f = 0;
  char ch;
  for (ch = getchar(); !isdigit(ch); ch = getchar()) {
    if (ch == EOF) return 0;
    f |= ch == '-';
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  if (f) x = -x;
  return 1;
}
template <class T>
void write(T x) {
  if (x < 0) {
    putchar('-'), write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar((x % 10) | 48);
}
template <class T>
inline void writeln(T x) {
  write(x), putchar('\n');
}
template <class T>
inline void writespace(T x) {
  write(x), putchar(' ');
}
long long n, m, valx;
long long h[200010], ver[400010], edge[400010], nxt[400010], tot, val[200010],
    pnt[400010];
long long fa[200010], son[200010], siz[200010], dep[200010];
long long top[200010], pos[200010], c, tree_val[200010];
struct node {
  long long l, r;
  long long sum;
} tree[200010 << 2];
inline void add(long long u, long long v, long long cnt) {
  edge[++tot] = cnt;
  ver[tot] = v;
  nxt[tot] = h[u];
  h[u] = tot;
}
void dfs1(long long u, long long f) {
  fa[u] = f;
  siz[u] = 1, dep[u] = dep[f] + 1;
  for (register long long i = h[u]; i; i = nxt[i]) {
    long long v = ver[i];
    if (v == f) continue;
    dfs1(v, u);
    siz[u] += siz[v];
    val[v] = edge[i], pnt[i] = v;
    if (siz[son[u]] < siz[v]) son[u] = v;
  }
}
void dfs2(long long u, long long topf) {
  top[u] = topf;
  pos[u] = ++c;
  tree_val[pos[u]] = val[u];
  if (!son[u]) return;
  dfs2(son[u], topf);
  for (register long long i = h[u]; i; i = nxt[i]) {
    long long v = ver[i];
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}
void biuld(long long id, long long l, long long r) {
  tree[id].l = l;
  tree[id].r = r;
  if (l == r) {
    tree[id].sum = tree_val[l];
    return;
  }
  long long mid = l + r >> 1;
  biuld(id << 1, l, mid);
  biuld(id << 1 | 1, mid + 1, r);
  long long l1 = tree[id << 1].sum, r1 = tree[id << 1 | 1].sum;
  if (l1 == 0 || r1 == 0) {
    tree[id].sum = l1 + r1;
    return;
  }
  if ((long double)(tree[id << 1].sum * 1.0 * tree[id << 1 | 1].sum * 1.0) >
      1e18)
    tree[id].sum = 1e18 + 5000;
  else
    tree[id].sum = tree[id << 1].sum * tree[id << 1 | 1].sum;
}
void query(long long id, long long l, long long r) {
  if (valx == 0) return;
  if (tree[id].l >= l && tree[id].r <= r) {
    valx /= tree[id].sum;
    return;
  }
  if (tree[id << 1].r >= l) query(id << 1, l, r);
  if (tree[id << 1 | 1].l <= r) query(id << 1 | 1, l, r);
}
void update(long long id, long long x, long long t) {
  if (tree[id].l == tree[id].r && tree[id].l == x) {
    tree[id].sum = t;
    return;
  }
  if (tree[id << 1].r >= x)
    update(id << 1, x, t);
  else
    update(id << 1 | 1, x, t);
  long long l1 = tree[id << 1].sum, r1 = tree[id << 1 | 1].sum;
  if (l1 == 0 || r1 == 0) {
    tree[id].sum = l1 + r1;
    return;
  }
  if ((long double)(tree[id << 1].sum * 1.0 * tree[id << 1 | 1].sum * 1.0) >
      1e18)
    tree[id].sum = 1e18 + 5000;
  else
    tree[id].sum = tree[id << 1].sum * tree[id << 1 | 1].sum;
}
void ask(long long x, long long y) {
  while (top[x] != top[y]) {
    if (dep[fa[top[x]]] < dep[fa[top[y]]]) swap(x, y);
    query(1, pos[top[x]], pos[x]);
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  query(1, pos[x], pos[y]);
}
signed main() {
  srand(20050210);
  read(n);
  read(m);
  for (register long long i = 1; i < n; ++i) {
    long long u, v, cnt;
    read(u);
    read(v);
    read(cnt);
    add(u, v, cnt);
    add(v, u, cnt);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  tree_val[1] = 1;
  biuld(1, 1, n);
  while (m--) {
    long long op;
    read(op);
    if (op == 1) {
      long long x, y;
      read(x);
      read(y);
      read(valx);
      if (x == y)
        writeln(valx);
      else {
        ask(x, y);
        writeln(valx);
      }
    } else {
      long long x, t;
      read(x);
      read(t);
      update(1, pos[max(pnt[x << 1], pnt[x * 2 - 1])], t);
    }
  }
  return 0;
}
