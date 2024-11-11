#include <bits/stdc++.h>
using namespace std;
int read() {
  int g = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    g = g * 10 + ch - '0';
    ch = getchar();
  }
  return g * f;
}
const int N = 2e5 + 5;
const double INF = 1e9;
int n, L, cnt;
double e[N << 1];
struct node {
  int id, len;
  double v;
  bool operator<(const node& oth) const { return v < oth.v; }
} a[N << 1];
struct Seg {
  double tag[N << 3], mn[N << 3];
  void updata(int v, double w) { tag[v] += w, mn[v] += w; }
  void down(int v) {
    if (tag[v]) updata(v << 1, tag[v]), updata(v << 1 | 1, tag[v]), tag[v] = 0;
  }
  void up(int v) { mn[v] = min(mn[v << 1], mn[v << 1 | 1]); }
  void change(int v, int l, int r, int ql, int qr, double w) {
    if (ql <= l && r <= qr) return updata(v, w), void();
    int mid = l + r >> 1;
    down(v);
    if (ql <= mid) change(v << 1, l, mid, ql, qr, w);
    if (qr > mid) change(v << 1 | 1, mid + 1, r, ql, qr, w);
    up(v);
  }
  double query(int v, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return mn[v];
    int mid = l + r >> 1;
    down(v);
    if (qr <= mid) return query(v << 1, l, mid, ql, qr);
    if (ql > mid) return query(v << 1 | 1, mid + 1, r, ql, qr);
    return min(query(v << 1, l, mid, ql, qr),
               query(v << 1 | 1, mid + 1, r, ql, qr));
  }
} seg;
signed main() {
  n = read(), L = read();
  int las = 0;
  for (int i = (1); i <= (n); i++) {
    int x = read(), y = read();
    double s;
    scanf("%lf", &s);
    cnt++, a[cnt].id = cnt, a[cnt].v = 0, a[cnt].len = x - las;
    las = y;
    cnt++, a[cnt].id = cnt, a[cnt].v = s, a[cnt].len = y - x;
  }
  cnt++, a[cnt].id = cnt, a[cnt].v = 0, a[cnt].len = L - las;
  sort(a + 1, a + cnt + 1);
  for (int i = (1); i <= (cnt); i++) {
    if (a[i].v)
      seg.change(1, 1, cnt, a[i].id, cnt, e[i] = 1. * a[i].len / a[i].v);
    else
      seg.change(1, 1, cnt, a[i].id, cnt, e[i] = INF);
  }
  for (int i = (1); i <= (cnt); i++) {
    double x = e[i] - (-1. * a[i].len / (a[i].v + 2)),
           y = seg.query(1, 1, cnt, a[i].id, cnt), z = min(x, y);
    seg.change(1, 1, cnt, a[i].id, cnt, -z);
    e[i] -= z;
  }
  double Ans = 0;
  for (int i = (1); i <= (cnt); i++) {
    Ans += 1. * (e[i] + a[i].len) / (a[i].v + 1);
  }
  cout << fixed << setprecision(10) << Ans;
  return signed();
}
