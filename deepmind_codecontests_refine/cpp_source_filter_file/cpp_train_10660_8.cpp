#include <bits/stdc++.h>
#pragma GCC optimize(2)
const long long P = 998244353;
using namespace std;
inline void ckmax(long long &a, long long b) { a = max(a, b); }
inline void ckmin(long long &a, long long b) { a = min(a, b); }
inline void mul(long long &a, long long b) { a = 1ll * a * b % P; }
inline void addmod(long long &a, long long b) {
  long long t = a + b;
  a = (t >= P ? t - P : t);
}
inline long long ksm(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = 1ll * ans * a % P;
    a = 1ll * a * a % P;
  }
  return ans;
}
inline long long inv(long long a) { return ksm(a, P - 2); }
inline void printarray(long long *a, long long n) {
  for (register long long i = (1); i <= (n); i++) fprintf(stderr, "%d ", a[i]);
  fprintf(stderr, "\n");
}
namespace FastIO {
const long long SIZE = 1 << 16;
char buf[SIZE], obuf[SIZE], str[64];
long long bi = SIZE, bn = SIZE, opt;
long long read(char *s) {
  while (bn) {
    for (; bi < bn && buf[bi] <= ' '; bi++)
      ;
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  long long sn = 0;
  while (bn) {
    for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  s[sn] = 0;
  return sn;
}
bool read(long long &x) {
  if (x) x = 0;
  long long bf = 0, n = read(str);
  if (!n) return 0;
  long long i = 0;
  if (str[i] == '-') bf = 1, i = 1;
  for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
  if (bf) x = -x;
  return 1;
}
void write(long long x) {
  if (!x)
    obuf[opt++] = '0';
  else {
    if (x < 0) obuf[opt++] = '-', x = -x;
    long long sn = 0;
    while (x) str[sn++] = x % 10 + '0', x /= 10;
    for (long long i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
  }
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void write(char x) {
  obuf[opt++] = x;
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void Fflush() {
  if (opt) fwrite(obuf, 1, opt, stdout);
  opt = 0;
}
};  // namespace FastIO
const long long MAXN = 2e5 + 5;
long long n, m, h, a[MAXN], b[MAXN];
struct Segment_tree {
  static const long long N = MAXN << 2;
  long long mn[N], tag[N];
  void build(long long k, long long l, long long r) {
    if (l == r) return mn[k] = -l, tag[k] = 0, void();
    build((k << 1), l, ((l + r) >> 1)),
        build((k << 1 | 1), ((l + r) >> 1) + 1, r);
    mn[k] = min(mn[(k << 1)], mn[(k << 1 | 1)]);
  }
  inline void pushr(long long k, long long v) { mn[k] += v, tag[k] += v; }
  void update(long long k, long long l, long long r, long long ql, long long qr,
              long long v) {
    if (l == ql && r == qr) return pushr(k, v), void();
    if (tag[k])
      pushr((k << 1), tag[k]), pushr((k << 1 | 1), tag[k]), tag[k] = 0;
    if (qr <= ((l + r) >> 1))
      update((k << 1), l, ((l + r) >> 1), ql, qr, v);
    else if (((l + r) >> 1) < ql)
      update((k << 1 | 1), ((l + r) >> 1) + 1, r, ql, qr, v);
    else
      update((k << 1), l, ((l + r) >> 1), ql, ((l + r) >> 1), v),
          update((k << 1 | 1), ((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, qr,
                 v);
    mn[k] = min(mn[(k << 1)], mn[(k << 1 | 1)]);
  }
} tr;
void modify(long long x, long long v) {
  long long p = lower_bound(b + 1, b + 1 + m, x) - b;
  if (p <= m) tr.update(1, 1, m, p, m, v);
}
signed main() {
  FastIO::read(n);
  FastIO::read(m);
  FastIO::read(h);
  for (register long long i = (1); i <= (m); i++) FastIO::read(b[i]);
  sort(b + 1, b + 1 + m);
  tr.build(1, 1, m);
  for (register long long i = (1); i <= (n); i++)
    FastIO::read(a[i]), a[i] = h - a[i];
  for (register long long i = (1); i <= (m); i++) modify(a[i], 1);
  long long ans = (tr.mn[1] >= 0);
  for (register long long i = (2); i <= (n - m); i++) {
    modify(a[i - 1], -1), modify(a[i + m - 1], 1);
    ans += (tr.mn[1] >= 0);
  }
  cout << ans << endl;
  return FastIO::Fflush(), 0;
}
