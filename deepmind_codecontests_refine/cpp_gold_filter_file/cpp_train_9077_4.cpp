#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while ((c < '0' || c > '9') && c ^ '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return x * f;
}
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x < y ? y : x; }
const int N = 1e6 + 10, top = 1e6 + 1;
int n, m, a[N], cx[N];
struct xds {
  int mi[N << 2], cnt[N << 2], lazy[N << 2];
  inline void pushdown(int t) {
    mi[t << 1] += lazy[t];
    mi[t << 1 | 1] += lazy[t];
    lazy[t << 1] += lazy[t];
    lazy[t << 1 | 1] += lazy[t];
    lazy[t] = 0;
  }
  inline void upfather(int t) {
    if (!cnt[t << 1]) {
      mi[t] = mi[t << 1 | 1];
      cnt[t] = cnt[t << 1 | 1];
      return;
    }
    if (!cnt[t << 1 | 1]) {
      mi[t] = mi[t << 1];
      cnt[t] = cnt[t << 1];
      return;
    }
    if (mi[t << 1] == mi[t << 1 | 1]) {
      mi[t] = mi[t << 1];
      cnt[t] = cnt[t << 1] + cnt[t << 1 | 1];
      return;
    }
    if (mi[t << 1] < mi[t << 1 | 1])
      mi[t] = mi[t << 1], cnt[t] = cnt[t << 1];
    else
      mi[t] = mi[t << 1 | 1], cnt[t] = cnt[t << 1 | 1];
  }
  void gai(int t, int l, int r, int ql, int qr, int zhi) {
    if (l > qr || r < ql) return;
    if (ql <= l && qr >= r) {
      mi[t] += zhi;
      lazy[t] += zhi;
      return;
    }
    if (lazy[t]) pushdown(t);
    int mid = (l + r) >> 1;
    gai(t << 1, l, mid, ql, qr, zhi);
    gai(t << 1 | 1, mid + 1, r, ql, qr, zhi);
    upfather(t);
  }
  void gai_cnt(int t, int l, int r, int wz, int der) {
    if (l == r) {
      cnt[t] = der;
      return;
    }
    if (lazy[t]) pushdown(t);
    int mid = (l + r) >> 1;
    if (wz <= mid)
      gai_cnt(t << 1, l, mid, wz, der);
    else
      gai_cnt(t << 1 | 1, mid + 1, r, wz, der);
    upfather(t);
  }
  void build(int t, int l, int r) {
    if (l == r) {
      cnt[t] = cx[l];
      mi[t] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    build(t << 1, l, mid);
    build(t << 1 | 1, mid + 1, r);
    upfather(t);
  }
  void xiu(int x, int y, int zhi) {
    if (x > y) swap(x, y);
    gai(1, 0, top, x, y - 1, zhi);
  }
} T;
int main() {
  n = read();
  m = read();
  a[0] = top;
  for (int i = 1; i <= n; i++) cx[a[i] = read()]++;
  T.build(1, 0, top);
  for (int i = 0; i <= n; i++) T.xiu(a[i], a[i + 1], 1);
  for (int i = 1, x, y; i <= m; i++) {
    x = read();
    y = read();
    T.xiu(a[x], a[x - 1], -1);
    T.xiu(a[x], a[x + 1], -1);
    T.gai_cnt(1, 0, top, a[x], 0);
    a[x] = y;
    T.xiu(a[x], a[x - 1], 1);
    T.xiu(a[x], a[x + 1], 1);
    T.gai_cnt(1, 0, top, a[x], 1);
    cout << T.cnt[1] << "\n";
  }
  return 0;
}
