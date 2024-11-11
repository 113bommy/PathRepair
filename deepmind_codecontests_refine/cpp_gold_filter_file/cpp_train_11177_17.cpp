#include <bits/stdc++.h>
template <class T>
inline void chkmax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class T>
inline void chkmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <class T>
inline void read(T &x) {
  char c;
  int f = 1;
  x = 0;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    f = -1;
  else
    x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
static int outn;
static char out[(int)2e7];
template <class T>
inline void write(T x) {
  if (x < 0) out[outn++] = '-', x = -x;
  if (x) {
    static int tmpn;
    static char tmp[20];
    tmpn = 0;
    while (x) tmp[tmpn++] = x % 10 + '0', x /= 10;
    while (tmpn) out[outn++] = tmp[--tmpn];
  } else
    out[outn++] = '0';
}
const int N = 1000;
const int S = (N + 1) * (N + 1);
const int INF = 2e9;
int n, vx, vy, s;
int h[N + 9][N + 9];
int d[N + 9][N + 9];
int v[S + 9], vn;
long long ans;
struct node {
  int a, at, b, min;
  node() {}
  node(int _a, int _at, int _b) : a(_a), at(_at), b(_b) {}
} tr[S * 4 + 9];
int tag[S * 4 + 9];
void build(int x, int l, int r) {
  tag[x] = -1;
  tr[x] = node(0, r - l + 1, INF);
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
}
inline void pushup(int x) {
  node &p = tr[x], &u = tr[x << 1], &v = tr[x << 1 | 1];
  p.a = std::min(u.a, v.a), p.at = 0, p.b = INF;
  if (p.a == u.a)
    p.at += u.at, chkmin(p.b, u.b);
  else
    chkmin(p.b, u.a);
  if (p.a == v.a)
    p.at += v.at, chkmin(p.b, v.b);
  else
    chkmin(p.b, v.a);
}
inline void pushdown(int, int, int);
inline void upd(int, int, int, int);
inline void upd(int x, int l, int r, int v) {
  if (tr[x].a >= v)
    return;
  else if (tr[x].b > v) {
    tr[x].a = v;
    tag[x] = v;
    return;
  } else {
    pushdown(x, l, r);
    int mid = (l + r) >> 1;
    upd(x << 1, l, mid, v);
    upd(x << 1 | 1, mid + 1, r, v);
    pushup(x);
  }
}
inline void pushdown(int x, int l, int r) {
  if (tag[x] != -1) {
    int mid = (l + r) >> 1;
    upd(x << 1, l, mid, tag[x]);
    upd(x << 1 | 1, mid + 1, r, tag[x]);
    tag[x] = -1;
  }
}
int qry(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return tr[x].a;
  pushdown(x, l, r);
  int mid = (l + r) >> 1, ret = INF;
  if (ql <= mid) chkmin(ret, qry(x << 1, l, mid, ql, qr));
  if (qr > mid) chkmin(ret, qry(x << 1 | 1, mid + 1, r, ql, qr));
  return ret;
}
void mdf(int x, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) {
    upd(x, l, r, v);
    return;
  }
  pushdown(x, l, r);
  int mid = (l + r) >> 1;
  if (ql <= mid) mdf(x << 1, l, mid, ql, qr, v);
  if (qr > mid) mdf(x << 1 | 1, mid + 1, r, ql, qr, v);
  pushup(x);
}
int main() {
  read(n), read(vx), read(vy);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) read(h[i][j]);
  if (vy < 0) {
    for (int i = 1; i <= n; ++i) std::reverse(h[i] + 1, h[i] + n + 1);
    vy = -vy;
  }
  if (vx < 0) {
    for (int j = 1; j <= n; ++j)
      for (int i = n >> 1; i >= 1; --i) std::swap(h[i][j], h[n - i + 1][j]);
    vx = -vx;
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) d[i][j] = vx * j - i * vy, v[++vn] = d[i][j];
  std::sort(v + 1, v + vn + 1);
  vn = std::unique(v + 1, v + vn + 1) - v - 1;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      d[i][j] = std::lower_bound(v + 1, v + vn + 1, d[i][j]) - v;
  build(1, 1, vn);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int x = qry(1, 1, vn, d[i][j - 1], d[i - 1][j] - 1);
      if (x < h[i][j]) {
        ans += h[i][j] - x;
        mdf(1, 1, vn, d[i][j - 1], d[i - 1][j] - 1, h[i][j]);
      }
    }
  std::cout << ans << std::endl;
  return 0;
}
