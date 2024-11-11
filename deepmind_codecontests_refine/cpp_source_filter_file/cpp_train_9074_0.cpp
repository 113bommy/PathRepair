#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool get_int(T &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-' && t != EOF; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  if (t == EOF) return false;
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
  return true;
}
template <typename T>
void print_int(T x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int inf = 0x3f3f3f3f;
const long long Linf = 1ll << 61;
const double pi = acos(-1.0);
const int maxn = 200111;
int val[maxn];
struct node {
  int l, r, mn, lv, rv, ansv, dlt, all;
  node() { l = r = mn = lv = rv = ansv = dlt = all = 0; }
  void add(int v) {
    mn += v;
    dlt += v;
  }
};
node seg[600111];
void pushdown(int t) {
  if (seg[t].dlt) {
    seg[(t << 1)].add(seg[t].dlt);
    seg[((t << 1) | 1)].add(seg[t].dlt);
    seg[t].dlt = 0;
  }
}
node merge(const node &a, const node &b) {
  node ret;
  ret.l = a.l;
  ret.r = b.r;
  ret.all = max(max(a.all, b.all), val[a.r]);
  if (a.mn < b.mn) {
    ret.mn = a.mn;
    ret.lv = a.lv;
    ret.rv = max(max(a.rv, b.all), val[a.r]);
    ret.ansv = a.ansv;
  } else if (a.mn > b.mn) {
    ret.mn = b.mn;
    ret.lv = max(max(a.all, b.lv), val[a.r]);
    ret.rv = b.rv;
    ret.ansv = b.ansv;
  } else {
    ret.mn = a.mn;
    ret.lv = a.lv;
    ret.rv = b.rv;
    ret.ansv = a.ansv + b.ansv + max(max(a.rv, b.lv), val[a.r]);
  }
  return ret;
}
void build(int tl, int tr, int t) {
  seg[t].l = tl;
  seg[t].r = tr;
  if (tl == tr) return;
  int mid = (tl + tr) >> 1;
  build(tl, mid, (t << 1));
  build(mid + 1, tr, ((t << 1) | 1));
}
void modify(int l, int r, int v, int tl, int tr, int t) {
  if (l <= tl && tr <= r) {
    seg[t].add(v);
    return;
  }
  pushdown(t);
  int mid = (tl + tr) >> 1;
  if (l <= mid) modify(l, r, v, tl, mid, (t << 1));
  if (r > mid) modify(l, r, v, mid + 1, tr, ((t << 1) | 1));
  seg[t] = merge(seg[(t << 1)], seg[((t << 1) | 1)]);
}
set<int> st[maxn];
int n, q, a[maxn];
void update(int v) { modify(v, v + 1, 0, 1, n + 1, 1); }
void reset(int v) {
  if (st[v].empty()) return;
  val[*st[v].begin()] = 0;
  update(*st[v].begin());
  if (st[v].size() > 1)
    modify(*st[v].begin() + 1, *st[v].rbegin(), -1, 1, n + 1, 1);
}
void orzdjq(int v) {
  if (st[v].empty()) return;
  val[*st[v].begin()] = (int)st[v].size();
  update(*st[v].begin());
  if (st[v].size() > 1)
    modify(*st[v].begin() + 1, *st[v].rbegin(), 1, 1, n + 1, 1);
}
int main() {
  (get_int(n) && get_int(q));
  for (int i = 1; i <= n; i++) {
    get_int(a[i]);
    st[a[i]].insert(i);
  }
  build(1, n + 1, 1);
  for (int i = 1; i <= 200000; i++) orzdjq(i);
  printf("%d\n", n - seg[1].ansv);
  for (int i = 1, x, v; i <= q; i++) {
    (get_int(x) && get_int(v));
    reset(a[x]);
    st[a[x]].erase(x);
    orzdjq(a[x]);
    reset(v);
    st[v].insert(x);
    orzdjq(v);
    a[x] = v;
    printf("%d\n", n - seg[1].ansv);
  }
  return 0;
}
