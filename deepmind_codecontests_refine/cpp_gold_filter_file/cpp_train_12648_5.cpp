#include <bits/stdc++.h>
using i64 = long long;
const int N = 100000 + 7;
const i64 INF = 1ll << 60;
int n;
i64 a[N];
struct SplayTree {
  int ct, rt;
  int fa[N], kid[N][2], siz[N];
  i64 val[N], tag[N], del[N];
  SplayTree() {
    rt = 1, ct = 2;
    kid[1][1] = 2, siz[1] = 2;
    fa[2] = 1, siz[2] = 1;
  }
  void pushup(int p) { siz[p] = siz[kid[p][0]] + siz[kid[p][1]] + 1; }
  void pushdown(int p) {
    if (tag[p]) {
      if (kid[p][0]) tag[kid[p][0]] += tag[p], val[kid[p][0]] += tag[p];
      if (kid[p][1]) tag[kid[p][1]] += tag[p], val[kid[p][1]] += tag[p];
      tag[p] = 0;
    }
    if (del[p]) {
      if (kid[p][0])
        del[kid[p][0]] += del[p],
            val[kid[p][0]] += del[p] * siz[kid[kid[p][0]][0]];
      if (kid[p][1])
        del[kid[p][1]] += del[p],
            val[kid[p][1]] += del[p] * siz[kid[kid[p][1]][0]];
      if (kid[p][1])
        del[p] *= siz[kid[p][0]] + 1, tag[kid[p][1]] += del[p],
            val[kid[p][1]] += del[p];
      del[p] = 0;
    }
  }
  int son(int p) { return kid[fa[p]][1] == p; }
  void connect(int f, int p, int d) { kid[f][d] = p, fa[p] = f; }
  void spin(int p) {
    int t = fa[p], d = son(p);
    connect(fa[t], p, son(t));
    connect(t, kid[p][d ^ 1], d);
    connect(p, t, d ^ 1);
    pushup(t), pushup(p);
  }
  void splay(int p, int f = 0) {
    for (int k; fa[p] != f; spin(p))
      if (fa[fa[p]] != f) spin(son(p) ^ son(fa[p]) ? p : fa[p]);
    if (!fa[p]) rt = p;
  }
  void find(int k, int f = 0) {
    for (int p = rt; p;) {
      pushdown(p);
      if (siz[kid[p][0]] + 1 == k) return void(splay(p, f));
      if (siz[kid[p][0]] >= k)
        p = kid[p][0];
      else
        k -= siz[kid[p][0]] + 1, p = kid[p][1];
    }
  }
  void insert(int k, i64 x) {
    find(k), pushdown(rt);
    if (!kid[rt][1])
      fa[kid[rt][1] = ++ct] = rt, siz[ct] = 1, val[ct] = x;
    else {
      int p;
      for (p = kid[rt][1]; kid[p][0]; p = kid[p][0]) pushdown(p);
      fa[kid[p][0] = ++ct] = p, siz[ct] = 1, val[ct] = x;
    }
  }
  i64 at(int p) { return find(++p), val[rt]; }
  void update(int l, int r, i64 x, i64 y) {
    if (l > r) return;
    find(l), find(r + 2, rt);
    int p = kid[kid[rt][1]][0];
    val[p] += x + y * siz[kid[p][0]];
    tag[p] += x, del[p] += y;
  }
} tr;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%I64d", a + i);
  tr.insert(1, 0);
  tr.insert(2, a[1]);
  for (int i = 2; i <= n; ++i) {
    int l = 1, r = i, m;
    for (; l < r;) {
      m = l + r >> 1;
      i64 x = tr.at(m), y = tr.at(m + 1);
      if (x + m * a[i] > y)
        r = m;
      else
        l = m + 1;
    }
    tr.insert(r + 1, tr.at(r)), tr.update(r + 1, i + 1, a[i] * r, a[i]);
  }
  i64 ans = 0;
  for (int i = 1; i <= n; ++i) ans = std::max(ans, tr.at(i + 1));
  return printf("%I64d", ans), 0;
}
