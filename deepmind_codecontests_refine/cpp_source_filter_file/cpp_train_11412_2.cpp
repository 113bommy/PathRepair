#include <bits/stdc++.h>
using namespace std;
void Freopen() {
  freopen(
      "title"
      ".in",
      "r", stdin);
  freopen(
      "title"
      ".out",
      "w", stdout);
}
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
const int N = 1e5 + 5;
const int INF = 1e9;
struct Seg {
  int tag[N << 2], mx[N << 2], cx[N << 2], size[N << 2], ok[N << 2];
  long long su[N << 2];
  void updata(int v, int w) {
    su[v] -= 1ll * ok[v] * size[v] * mx[v];
    tag[v] = min(tag[v], w);
    mx[v] = min(mx[v], w);
    su[v] += 1ll * (ok[v] = 1) * size[v] * mx[v];
  }
  void down(int v) {
    if (!(tag[v] ^ INF)) return void();
    updata(v << 1, tag[v]), updata(v << 1 | 1, tag[v]), tag[v] = INF;
  }
  void up(int v) {
    ok[v] = ok[v << 1] & ok[v << 1 | 1];
    su[v] = su[v << 1] + su[v << 1 | 1];
    mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    cx[v] = max(cx[v << 1], cx[v << 1 | 1]);
    if (mx[v << 1] > mx[v << 1 | 1]) cx[v] = max(cx[v], mx[v << 1 | 1]);
    if (mx[v << 1] < mx[v << 1 | 1]) cx[v] = max(cx[v], mx[v << 1]);
    size[v] = size[v << 1] * (mx[v << 1] == mx[v]) +
              size[v << 1 | 1] * (mx[v << 1 | 1] == mx[v]);
  }
  void build(int v, int l, int r) {
    mx[v] = INF, size[v] = r - l + 1, tag[v] = INF, cx[v] = -INF;
    if (l == r) return void();
    int mid = l + r >> 1;
    build(v << 1, l, mid), build(v << 1 | 1, mid + 1, r);
  }
  void change(int v, int l, int r, int ql, int qr, int w) {
    if (ql <= l && r <= qr) {
      if (mx[v] <= w)
        return void();
      else if (w >= cx[v])
        return updata(v, w), void();
    }
    int mid = l + r >> 1;
    down(v);
    if (ql <= mid) change(v << 1, l, mid, ql, qr, w);
    if (qr > mid) change(v << 1 | 1, mid + 1, r, ql, qr, w);
    up(v);
  }
} seg[2];
long long query(int v, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    if (seg[0].ok[v] && seg[1].ok[v])
      return seg[0].su[v] + seg[1].su[v];
    else if (l == r || !seg[0].su[v] || !seg[1].su[v])
      return 0;
  }
  int mid = l + r >> 1;
  seg[0].down(v), seg[1].down(v);
  if (qr <= mid) return query(v << 1, l, mid, ql, qr);
  if (ql > mid) return query(v << 1 | 1, mid + 1, r, ql, qr);
  return query(v << 1, l, mid, ql, qr) + query(v << 1 | 1, mid + 1, r, ql, qr);
}
signed main() {
  int n = 1e5;
  seg[0].build(1, 1, n), seg[1].build(1, 1, n);
  for (int T = read(); T--;) {
    int opt = read(), l = read(), r = read() - 1, x;
    if (opt == 1)
      x = read(), seg[x > 0].change(1, 1, n, l, r, abs(x));
    else
      cout << query(1, 1, n, l, r) << '\n';
  }
  return signed();
}
