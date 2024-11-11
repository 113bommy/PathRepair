#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long mx, cmx, mx2, tg, tg2, s;
  int c;
  inline void ladd(long long t) {
    s += t * c;
    tg += t;
    mx += t;
    mx2 += t;
  }
  inline void ladd2(long long t) {
    mx += t;
    s += cmx * t;
    tg2 += t;
  }
} a[150500 << 2];
int n;
inline void up(int u) {
  int l = u << 1, r = u << 1 | 1;
  a[u].s = a[l].s + a[r].s;
  a[u].c = a[l].c + a[r].c;
  if (a[l].mx == a[r].mx) {
    a[u].mx = a[l].mx;
    a[u].cmx = a[l].cmx + a[r].cmx;
    a[u].mx2 = max(a[l].mx2, a[r].mx2);
  } else {
    if (a[l].mx > a[r].mx) swap(l, r);
    a[u].mx = a[r].mx;
    a[u].cmx = a[r].cmx;
    a[u].mx2 = max(a[l].mx, a[r].mx2);
  }
}
void build(int l = 1, int r = n, int u = 1) {
  a[u].c = a[u].tg = a[u].tg2 = 0;
  a[u].s = a[u].mx = 0;
  a[u].cmx = r - l + 1;
  a[u].mx2 = 0;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, u << 1);
  build(mid + 1, r, u << 1 | 1);
}
void ladd(int u) {
  if (a[u].tg2) {
    int l = u << 1, r = u << 1 | 1, mx = max(a[l].mx, a[r].mx);
    if (a[l].mx == mx) a[l].ladd2(a[u].tg2);
    if (a[r].mx == mx) a[r].ladd2(a[u].tg2);
    a[u].tg2 = 0;
  }
  if (a[u].tg) {
    a[u << 1].ladd(a[u].tg);
    a[u << 1 | 1].ladd(a[u].tg);
    a[u].tg = 0;
  }
}
int wfl, wfr, wfc;
void add(int l = 1, int r = n, int u = 1) {
  if (wfl <= l && r <= wfr) {
    a[u].ladd(wfc);
    return;
  }
  int mid = (l + r) >> 1;
  ladd(u);
  if (wfl <= mid) add(l, mid, u << 1);
  if (mid < wfr) add(mid + 1, r, u << 1 | 1);
  up(u);
}
void chg(int l = 1, int r = n, int u = 1) {
  if (wfc >= a[u].mx) return;
  if (wfl <= l && r <= wfr && wfc > a[u].mx2) {
    a[u].ladd2(wfc - a[u].mx);
    return;
  }
  int mid = (l + r) >> 1;
  ladd(u);
  if (wfl <= mid) chg(l, mid, u << 1);
  if (mid < wfr) chg(mid + 1, r, u << 1 | 1);
  up(u);
}
int to;
void cre(int l = 1, int r = n, int u = 1) {
  if (l == r) {
    a[u].mx = a[u].s = wfc;
    a[u].c = 1;
    return;
  }
  int mid = (l + r) >> 1;
  ladd(u);
  if (to <= mid)
    cre(l, mid, u << 1);
  else
    cre(mid + 1, r, u << 1 | 1);
  up(u);
}
int qryc(int l = 1, int r = n, int u = 1) {
  if (wfl <= l && r <= wfr) return a[u].c;
  int mid = (l + r) >> 1, ret = 0;
  if (wfl <= mid) ret = qryc(l, mid, u << 1);
  if (mid < wfr) ret += qryc(mid + 1, r, u << 1 | 1);
  return ret;
}
int x[150500], p[150500];
long long ans[150500];
bool cmp(const int &A, const int &B) { return x[A] < x[B]; }
void calc() {
  for (int i = 1; i <= n; i++) p[i] = i;
  sort(p + 1, p + n + 1, cmp);
  build();
  for (int i = 1; i <= n; i++) {
    wfl = 1;
    wfr = p[i] - 1;
    if (wfl <= wfr) {
      wfc = qryc() + 1;
      chg();
    }
    wfl = p[i] + 1;
    wfr = n;
    wfc = 1;
    add();
    to = p[i];
    wfc = i + 1;
    cre();
    ans[i] += a[1].s;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  calc();
  reverse(x + 1, x + n + 1);
  calc();
  for (int i = 1; i <= n; i++) printf("%lld\n", ans[i] - 1ll * i * (i + 2));
  return 0;
}
