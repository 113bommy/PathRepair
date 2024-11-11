#include <bits/stdc++.h>
inline long long read() {
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  long long k = 1, kk = 0;
  if (c == '-') c = getchar(), k = -1;
  while (c >= '0' && c <= '9') kk = kk * 10 + c - '0', c = getchar();
  return kk * k;
}
using namespace std;
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x / 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(long long x) {
  write(x);
  puts("");
}
const long long N = 1000010, M = 1000010;
long long n, m, a[N], f[N], x[M], link[M], ff[M], mind, kk, kkk, d, dd, minw;
long long lazy[N * 4], mi1[N * 4], mi2[N * 4], wz1[N * 4], wz2[N * 4];
void pushdown(long long d) {
  lazy[d * 2] += lazy[d];
  lazy[d * 2 + 1] += lazy[d];
  mi1[d * 2] += lazy[d];
  mi1[d * 2 + 1] += lazy[d];
  lazy[d] = 0;
}
void build(long long l, long long r, long long d) {
  if (l == r) {
    mi1[d] = f[l];
    mi2[d] = a[l];
    wz1[d] = wz2[d] = l;
    return;
  }
  long long m = (l + r) >> 1;
  build(l, m, d * 2);
  build(m + 1, r, d * 2 + 1);
  mi1[d * 2] <= mi1[d * 2 + 1] ? wz1[d] = wz1[d * 2] : wz1[d] = wz1[d * 2 + 1];
  mi2[d * 2] <= mi2[d * 2 + 1] ? wz2[d] = wz2[d * 2] : wz2[d] = wz2[d * 2 + 1];
  mi1[d] = min(mi1[d * 2], mi1[d * 2 + 1]);
  mi2[d] = min(mi2[d * 2], mi2[d * 2 + 1]);
}
void putit1(long long x, long long y, long long z, long long l, long long r,
            long long d) {
  if (x <= l && y >= r) {
    mi1[d] += z;
    lazy[d] += z;
    return;
  }
  if (lazy[d]) pushdown(d);
  long long m = (l + r) >> 1;
  if (x <= m) putit1(x, y, z, l, m, d * 2);
  if (y > m) putit1(x, y, z, m + 1, r, d * 2 + 1);
  mi1[d * 2] <= mi1[d * 2 + 1] ? wz1[d] = wz1[d * 2] : wz1[d] = wz1[d * 2 + 1];
  mi1[d] = min(mi1[d * 2], mi1[d * 2 + 1]);
}
void putit2(long long x, long long l, long long r, long long d) {
  if (l == r) {
    mi2[d] = 0;
    return;
  }
  long long m = (l + r) >> 1;
  if (x <= m)
    putit2(x, l, m, d * 2);
  else
    putit2(x, m + 1, r, d * 2 + 1);
  mi2[d * 2] <= mi2[d * 2 + 1] ? wz2[d] = wz2[d * 2] : wz2[d] = wz2[d * 2 + 1];
  mi2[d] = min(mi2[d * 2], mi2[d * 2 + 1]);
}
long long findit(long long x, long long y, long long l, long long r,
                 long long d) {
  if (l == r) return mind - min(a[l], x) >= y ? l : -1;
  if (lazy[d]) pushdown(d);
  long long m = (l + r) >> 1;
  long long xx = min(mi2[-d * 2], x), yy = min(y, mi1[d * 2]);
  long long xxx = min(xx, a[m + 1]);
  if (mind - xxx >= yy) {
    long long kk = findit(x, y, l, m, d * 2);
    return kk == -1 ? m + 1 : kk;
  } else
    return findit(xx, yy, m + 1, r, d * 2 + 1);
}
long long find1(long long x, long long l, long long r, long long d) {
  if (x == 0) return 1e18;
  if (r <= x) return mi1[d];
  if (lazy[d]) pushdown(d);
  long long m = (l + r) >> 1;
  if (x <= m)
    return find1(x, l, m, d * 2);
  else
    return min(find1(x, m + 1, r, d * 2 + 1), mi1[d * 2]);
}
long long find2(long long x, long long l, long long r, long long d) {
  if (r <= x) return mi2[d];
  long long m = (l + r) >> 1;
  if (x <= m)
    return find2(x, l, m, d * 2);
  else
    return min(find2(x, m + 1, r, d * 2 + 1), mi2[d * 2]);
}
long long find3(long long x, long long l, long long r, long long d) {
  if (r <= x) return wz2[d];
  long long m = (l + r) >> 1;
  if (x <= m)
    return find3(x, l, m, d * 2);
  else {
    long long k = find3(x, m + 1, r, d * 2 + 1);
    return a[k] >= mi2[d * 2] ? wz2[d * 2] : k;
  }
}
void check(long long x) {
  if (x < 1 || x > n) return;
  long long xx = find1(x - 1, 1, n, 1), yy = mind - find2(x, 1, n, 1);
  if (!kk)
    kk = x, kkk = min(xx, yy);
  else if (min(xx, yy) > kkk)
    kkk = min(xx, yy), kk = x;
}
bool pd(long long a, long long b) { return x[a] > x[b]; }
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) a[i] = read(), f[i] = f[i - 1] + a[i];
  for (long long i = 1; i <= m; i++) x[i] = read(), link[i] = i;
  sort(link + 1, link + 1 + m, pd);
  build(1, n, 1);
  d = 1;
  mind = -mi1[1];
  while (x[link[d]] >= mind && d <= m) d++;
  for (long long i = 1; i <= n && d <= m; i++) {
    mind = mi1[1];
    minw = wz1[1];
    dd = findit(1e18, 1e18, 1, n, 1);
    if (dd == -1) dd = n;
    dd = min(dd, minw);
    kk = 0;
    check(dd);
    check(dd - 1);
    check(dd + 1);
    kk = find3(kk, 1, n, 1);
    putit1(kk, n, -a[kk], 1, n, 1);
    putit2(kk, 1, n, 1);
    a[kk] = 0;
    mind = -mi1[1];
    while (x[link[d]] >= mind && d <= m) ff[link[d]] = i, d++;
    if (d > m) break;
  }
  for (long long i = 1; i <= m; i++) writeln(ff[i]);
}
