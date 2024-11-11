#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 7;
const long long mod = 1000000007;
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
void out(long long x) {
  int stackk[40];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int top = 0;
  while (x) stackk[++top] = x % 10, x /= 10;
  while (top) putchar(stackk[top--] + '0');
}
long long n, q, p[maxn], now, val;
struct node {
  long long ma, mi, s, l, r, lz;
} a[maxn * 4];
void push_up(int st) {
  a[st].s = a[st * 2].s + a[st * 2 + 1].s;
  a[st].ma = max(a[st * 2 + 1].ma, a[st * 2].ma);
  a[st].mi = min(a[st * 2 + 1].mi, a[st * 2].mi);
}
void push_down(int st) {
  if (a[st].lz == -1) return;
  a[st * 2 + 1].lz = a[st].lz, a[st * 2].lz = a[st].lz;
  a[st * 2].ma = a[st * 2].mi = a[st].lz;
  a[st * 2 + 1].ma = a[st * 2 + 1].mi = a[st].lz;
  a[st * 2 + 1].s = (a[st * 2 + 1].r - a[st * 2 + 1].l + 1) * a[st].lz;
  a[st * 2].s = (a[st * 2].r - a[st * 2].l + 1) * a[st].lz;
  a[st].lz = -1;
}
void build(int st, int l, int r) {
  a[st].l = l, a[st].r = r, a[st].lz = -1;
  if (l == r) {
    a[st].ma = a[st].mi = a[st].s = p[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(st * 2, l, mid), build(st * 2 + 1, mid + 1, r);
  push_up(st);
}
void update(int st, int l, int r, int ql, int qr, int num) {
  if (num <= a[st].mi) return;
  if (ql <= l && qr >= r) {
    if (num >= a[st].ma) {
      a[st].s = (r - l + 1) * num;
      a[st].lz = num;
      a[st].mi = a[st].ma = num;
      return;
    }
  }
  push_down(st);
  int mid = (l + r) >> 1;
  if (ql <= mid) update(st * 2, l, mid, ql, qr, num);
  if (qr > mid) update(st * 2 + 1, mid + 1, r, ql, qr, num);
  push_up(st);
}
void query(int st, int l, int r, int ql, int qr) {
  if (val == 0) return;
  if (val < a[st].mi) return;
  if (ql <= l && qr >= r) {
    if (val >= a[st].s) {
      val -= a[st].s;
      now += r - l + 1;
      return;
    }
  }
  push_down(st);
  int mid = (l + r) >> 1;
  if (ql <= mid) query(st * 2, l, mid, ql, qr);
  if (qr > mid) query(st * 2 + 1, mid + 1, r, ql, qr);
  push_up(st);
}
int main() {
  n = read(), q = read();
  for (int i = (1); i <= (n); ++i) p[i] = read();
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    long long op, x, y;
    op = read(), x = read(), y = read();
    if (op == 1)
      update(1, 1, n, 1, x, y);
    else {
      val = y, now = 0;
      query(1, 1, n, x, n);
      printf("%lld\n", now);
    }
  }
  return 0;
}
