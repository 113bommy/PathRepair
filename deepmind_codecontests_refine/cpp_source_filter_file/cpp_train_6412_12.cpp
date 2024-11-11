#include <bits/stdc++.h>
int n, k, a[500010], b[500010];
struct node {
  struct path {
    int x, y;
    path() : x(), y() {}
    path(int const &a, int const &b) : x(a), y(b) {}
    path operator+(path const &k) const {
      return a[x] + b[y] < a[k.x] + b[k.y] ? *this : k;
    }
  } va, vb, vc;
  int aa, ab, ba, bb, vm, tag;
  node() : va(), vb(), vc(), aa(), ab(), ba(), bb(), vm(), tag() {}
  friend node operator+(node const &l, node const &r) {
    node x;
    x.va = l.va + r.va + path(l.aa, r.ab);
    x.vc = l.vc + r.vc + path(r.aa, l.ab);
    x.aa = a[l.aa] < a[r.aa] ? l.aa : r.aa;
    x.ab = b[l.ab] < b[r.ab] ? l.ab : r.ab;
    x.vm = l.vm > r.vm ? r.vm : l.vm;
    if (l.vm < r.vm) {
      x.vb = l.vb + r.vb + r.vc + path(r.aa, l.bb);
      x.ba = l.ba;
      x.bb = b[r.ab] < b[l.bb] ? r.ab : l.bb;
    } else if (l.vm > r.vm) {
      x.vb = l.vb + r.vb + l.vc + path(r.ba, l.ab);
      x.ba = a[r.ba] < a[l.aa] ? r.ba : l.aa;
      x.bb = l.bb;
    } else {
      x.vb = l.vb + r.vb + path(r.ba, l.bb);
      x.ba = l.ba;
      x.bb = l.bb;
    }
    return x;
  }
} tr[2000010];
inline void add(int const &x, int const &p) { tr[x].tag += p, tr[x].vm += p; }
inline void pushdown(int const &x) {
  if (tr[x].tag)
    add(x << 1, tr[x].tag), add(x << 1 | 1, tr[x].tag), tr[x].tag = 0;
}
void build(int const &x = 1, int const &l = 0, int const &r = n) {
  if (l == r)
    return tr[x].va = tr[x].vc = node::path(l, l),
           tr[x].aa = tr[x].ab = tr[x].ba = l, void();
  int mid = (l + r) >> 1;
  build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
  tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
void update(int const &pl, int const &pr, int const &v, int const &x = 1,
            int const &l = 0, int const &r = n) {
  if (l == pl && r == pr) return add(x, v);
  pushdown(x);
  int mid = (l + r) >> 1;
  if (pr <= mid)
    update(pl, pr, v, x << 1, l, mid);
  else if (pl > mid)
    update(pl, pr, v, x << 1 | 1, mid + 1, r);
  else
    update(pl, mid, v, x << 1, l, mid),
        update(mid + 1, pr, v, x << 1 | 1, mid + 1, r);
  tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
void upd(int const &p, int const &x = 1, int const &l = 0, int const &r = n) {
  if (l == r) return;
  pushdown(x);
  int mid = (l + r) >> 1;
  if (p <= mid)
    upd(p, x << 1, l, mid);
  else
    upd(p, x << 1 | 1, mid + 1, r);
  tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  a[0] = b[0] = 0x3f3f3f3f;
  build();
  long long ans = 0;
  while (k--) {
    node::path t = tr[1].va + tr[1].vb;
    int i = t.x, j = t.y;
    ans += a[i] + b[j];
    if (i < j) update(i, j - 1, 1);
    if (i > j) update(j, i - 1, -1);
    a[i] = 0x3f3f3f3f, upd(i);
    b[j] = 0x3f3f3f3f, upd(j);
  }
  printf("%lld\n", ans);
  return 0;
}
