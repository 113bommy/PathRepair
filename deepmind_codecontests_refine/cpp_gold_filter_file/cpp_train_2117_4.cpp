#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-10;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, cnt, cnt2, an, ap;
unordered_map<int, int> ma;
int pos[maxn * 4], ans[maxn], tt[maxn * 2];
struct bus {
  int s, f, t, id;
  bool operator<(const bus& b) const { return f > b.f; }
} sp[maxn];
struct people {
  int l, r, b, id;
  bool operator<(const people& p) const { return r > p.r; }
} pp[maxn];
struct node {
  int l, r, v;
};
struct SegTree {
  node t[maxn << 2];
  void build(int o, int l, int r) {
    t[o].l = l;
    t[o].r = r;
    t[o].v = INF;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
  }
  void pushup(int o) { t[o].v = min(t[o << 1].v, t[o << 1 | 1].v); }
  void upd(int o, int p, int v) {
    if (t[o].l == t[o].r) {
      t[o].v = min(t[o].v, v);
      return;
    }
    int m = (t[o].l + t[o].r) >> 1;
    if (p <= m)
      upd(o << 1, p, v);
    else
      upd(o << 1 | 1, p, v);
    pushup(o);
  }
  void qry(int o, int ql, int qr, int v) {
    if (ql <= t[o].l && t[o].r <= qr) {
      if (t[o].v <= v) {
        if (t[o].l < an) {
          ap = o;
          an = min(an, t[o].l);
        }
      }
      return;
    }
    int m = (t[o].l + t[o].r) >> 1;
    if (ql <= m) qry(o << 1, ql, qr, v);
    if (qr > m) qry(o << 1 | 1, ql, qr, v);
  }
  int qry2(int o, int v) {
    if (t[o].l == t[o].r) {
      return t[o].l;
    }
    int m = (t[o].l + t[o].r) >> 1;
    int lson = t[o << 1].v, rson = t[o << 1 | 1].v;
    if (lson <= v) {
      return qry2(o << 1, v);
    } else {
      return qry2(o << 1 | 1, v);
    }
  }
} ST;
int main(void) {
  scanf("%d%d", &n, &m);
  cnt = cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &sp[i].s, &sp[i].f, &sp[i].t);
    sp[i].id = i;
    pos[++cnt] = sp[i].s;
    pos[++cnt] = sp[i].f;
    tt[++cnt2] = sp[i].t;
    ma[sp[i].t] = i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &pp[i].l, &pp[i].r, &pp[i].b);
    pp[i].id = i;
    pos[++cnt] = pp[i].l;
    pos[++cnt] = pp[i].r;
    tt[++cnt2] = pp[i].b;
  }
  sort(pos + 1, pos + cnt + 1);
  int sz = unique(pos + 1, pos + cnt + 1) - pos - 1;
  sort(tt + 1, tt + cnt2 + 1);
  int sz2 = unique(tt + 1, tt + cnt2 + 1) - tt - 1;
  for (int i = 1; i <= n; i++) {
    sp[i].s = lower_bound(pos + 1, pos + sz + 1, sp[i].s) - pos;
    sp[i].f = lower_bound(pos + 1, pos + sz + 1, sp[i].f) - pos;
    sp[i].t = lower_bound(tt + 1, tt + sz2 + 1, sp[i].t) - tt;
  }
  for (int i = 1; i <= m; i++) {
    pp[i].l = lower_bound(pos + 1, pos + sz + 1, pp[i].l) - pos;
    pp[i].r = lower_bound(pos + 1, pos + sz + 1, pp[i].r) - pos;
    pp[i].b = lower_bound(tt + 1, tt + sz2 + 1, pp[i].b) - tt;
  }
  sort(sp + 1, sp + n + 1);
  sort(pp + 1, pp + m + 1);
  ST.build(1, 1, sz2);
  int tp = 1;
  for (int i = 1; i <= m; i++) {
    while (tp <= n && sp[tp].f >= pp[i].r) {
      ST.upd(1, sp[tp].t, sp[tp].s);
      ++tp;
    }
    an = INF;
    ST.qry(1, pp[i].b, sz2, pp[i].l);
    if (an == INF)
      ans[pp[i].id] = -1;
    else {
      int res = ST.qry2(ap, pp[i].l);
      ans[pp[i].id] = ma[tt[res]];
    }
  }
  for (int i = 1; i <= m; i++) printf("%d%c", ans[i], (i == m) ? '\n' : ' ');
  return 0;
}
