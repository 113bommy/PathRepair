#include <bits/stdc++.h>
using namespace std;
struct T {
  long long x, l, r;
} c[400005], d[400005];
long long n, m, k, a[400005], tg[400005], b[400005], Tg[400005];
bool cmp(T x, T y) { return x.x == y.x ? x.l > y.l : x.x < y.x; }
void dn(long long k, long long l, long long r) {
  long long mid = l + r >> 1;
  if (tg[k]) {
    a[k << 1] += tg[k] * (mid - l + 1);
    tg[k << 1] += tg[k];
    a[k << 1 | 1] += tg[k] * (r - mid);
    tg[k << 1 | 1] += tg[k];
    tg[k] = 0;
  }
}
void mdy(long long k, long long l, long long r, long long x, long long y,
         long long p) {
  if (x <= l && r <= y) {
    a[k] += p * (r - l + 1);
    tg[k] += p;
    return;
  }
  long long mid = l + r >> 1;
  dn(k, l, r);
  if (x <= mid) mdy(k << 1, l, mid, x, y, p);
  if (y > mid) mdy(k << 1 | 1, mid + 1, r, x, y, p);
  a[k] = a[k << 1] + a[k << 1 | 1];
}
long long sum(long long k, long long l, long long r, long long x) {
  if (r <= x) return a[k];
  long long mid = l + r >> 1, ans;
  dn(k, l, r);
  ans = sum(k << 1, l, mid, x);
  if (x > mid) ans += sum(k << 1 | 1, mid + 1, r, x);
  return ans;
}
long long kth(long long k, long long l, long long r, long long x) {
  if (l == r) return l;
  long long mid = l + r >> 1;
  dn(k, l, r);
  if (a[k << 1] >= x) return kth(k << 1, l, mid, x);
  return kth(k << 1 | 1, mid + 1, r, x - a[k << 1]);
}
void down(long long k, long long l, long long r) {
  if (Tg[k]) {
    Tg[k << 1] = Tg[k << 1 | 1] = 1;
    b[k << 1] = b[k << 1 | 1] = 0;
    Tg[k] = 0;
  }
}
void add(long long k, long long l, long long r, long long x, long long y) {
  b[k] = (b[k] + y) % 1000000007;
  if (l == r) return;
  long long mid = l + r >> 1;
  down(k, l, r);
  if (x <= mid)
    add(k << 1, l, mid, x, y);
  else
    add(k << 1 | 1, mid + 1, r, x, y);
}
void gg(long long k, long long l, long long r, long long x, long long y) {
  if (x <= l && r <= y) {
    b[k] = 0;
    Tg[k] = 1;
    return;
  }
  long long mid = l + r >> 1;
  down(k, l, r);
  if (x <= mid) gg(k << 1, l, mid, x, y);
  if (y > mid) gg(k << 1 | 1, mid + 1, r, x, y);
  b[k] = (b[k << 1] + b[k << 1 | 1]) % 1000000007;
}
long long qry(long long k, long long l, long long r, long long x, long long y) {
  if (x > y) return 0;
  if (x <= l && r <= y) return b[k];
  long long mid = l + r >> 1, Ans = 0;
  down(k, l, r);
  if (x <= mid) Ans += qry(k << 1, l, mid, x, y);
  if (y > mid) Ans += qry(k << 1 | 1, mid + 1, r, x, y);
  return Ans % 1000000007;
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  for (long long i = 1; i <= k; i++) {
    long long x1, y1, x2, y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    c[i] = (T){x1, y1, y2};
    d[i] = (T){x2, y1, y2};
  }
  sort(c + 1, c + k + 1, cmp);
  sort(d + 1, d + k + 1, cmp);
  long long now = 1, pre = 1, rnow = 1;
  for (long long i = 1; i <= n; i++) {
    if (i == 2) add(1, 1, m, 1, 1);
    while (now <= k && c[now].x == i) {
      long long t = kth(1, 0, m, sum(1, 0, m, c[now].r + 1)) + 1;
      t = qry(1, 1, m, t, c[now].r + 1);
      gg(1, 1, m, c[now].l, c[now].r + 1);
      if (c[now].r < m) add(1, 1, m, c[now].r + 1, t);
      now++;
    }
    while (rnow <= k && d[rnow].x == i - 1) {
      mdy(1, 0, m, d[rnow].l, d[rnow].r, -1);
      rnow++;
    }
    while (pre < now) {
      mdy(1, 0, m, c[pre].l, c[pre].r, 1);
      gg(1, 1, m, c[pre].l, c[pre].r);
      pre++;
    }
  }
  long long t = kth(1, 0, m, sum(1, 0, m, m)) + 1;
  printf("%lld\n", qry(1, 1, m, t, m));
}
