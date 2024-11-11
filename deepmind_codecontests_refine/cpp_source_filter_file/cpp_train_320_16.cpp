#include <bits/stdc++.h>
using namespace std;
const int Imx = 2147483647;
const long long Lbig = 2e18;
const int mod = 1e9 + 7;
struct fastio {
  char s[100000];
  int it, len;
  fastio() { it = len = 0; }
  inline char get() {
    if (it < len) return s[it++];
    it = 0;
    len = fread(s, 1, 100000, stdin);
    if (len == 0)
      return EOF;
    else
      return s[it++];
  }
  bool notend() {
    char c = get();
    while (c == ' ' || c == '\n') c = get();
    if (it > 0) it--;
    return c != EOF;
  }
} _buff;
inline long long getnum() {
  long long r = 0;
  bool ng = 0;
  char c;
  c = _buff.get();
  while (c != '-' && (c < '0' || c > '9')) c = _buff.get();
  if (c == '-') ng = 1, c = _buff.get();
  while (c >= '0' && c <= '9') r = r * 10 + c - '0', c = _buff.get();
  return ng ? -r : r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline char getreal() {
  char c = _buff.get();
  while (c <= 32) c = _buff.get();
  return c;
}
long long qpow(long long x, long long k) {
  return k == 0 ? 1
                : 1ll * qpow(1ll * x * x % mod, k >> 1) * (k & 1 ? x : 1) % mod;
}
const int maxn = 200111;
int n, q;
long long pos[maxn];
struct SGT {
  long long a[maxn << 4], b[maxn << 4];
  void modify(int x, long long v, int l, int r, int p) {
    if (l == r) {
      a[p] = v;
      b[p] = pos[l] * v % mod;
      return;
    }
    int m = l + r >> 1;
    if (x <= m)
      modify(x, v, l, m, p << 1);
    else
      modify(x, v, m + 1, r, p << 1 | 1);
    a[p] = a[p << 1] + a[p << 1 | 1];
    b[p] = (b[p << 1] + b[p << 1 | 1]) % mod;
  }
  long long query(int x, int y, int l, int r, int p) {
    if (x > y) return 0;
    if (x <= l && r <= y) return a[p];
    int m = l + r >> 1;
    long long ret = 0;
    if (x <= m) ret += query(x, y, l, m, p << 1);
    if (m < y) ret += query(x, y, m + 1, r, p << 1 | 1);
    return ret;
  }
  long long queryb(int x, int y, int l, int r, int p) {
    if (x > y) return 0;
    if (x <= l && r <= y) return b[p];
    int m = l + r >> 1;
    long long ret = 0;
    if (x <= m) ret += queryb(x, y, l, m, p << 1);
    if (m < y) ret += queryb(x, y, m + 1, r, p << 1 | 1);
    return ret % mod;
  }
  int querylft(int x, int y, long long &v, int l, int r, int p) {
    if (x <= l && r <= y) {
      if (v > a[p]) {
        v -= a[p];
        return r + 1;
      } else {
        if (l == r) return l;
        int m = l + r >> 1;
        if (v <= a[p << 1])
          return querylft(x, y, v, l, m, p << 1);
        else {
          v -= a[p << 1];
          return querylft(x, y, v, m + 1, r, p << 1 | 1);
        }
      }
    }
    int m = l + r >> 1;
    if (x <= m && m < y) {
      int t = querylft(x, y, v, l, m, p << 1);
      if (t == m + 1)
        return querylft(x, y, v, m + 1, r, p << 1 | 1);
      else
        return t;
    } else if (x <= m)
      return querylft(x, y, v, l, m, p << 1);
    else
      return querylft(x, y, v, m + 1, r, p << 1 | 1);
  }
} sgt;
long long w[maxn], w2[maxn];
long long solve(int l, int r) {
  long long sum = sgt.query(l, r, 1, n, 1);
  long long cur = sum / 2;
  int p = sgt.querylft(l, r, cur, 1, n, 1);
  assert(p >= l && p <= r);
  long long ANS = sgt.queryb(p + 1, r, 1, n, 1) - sgt.queryb(l, p, 1, n, 1);
  long long cnt =
      (-sgt.query(p + 1, r, 1, n, 1) + sgt.query(l, p, 1, n, 1)) % mod;
  return ((ANS + cnt * pos[p] % mod) % mod + mod) % mod;
}
int main() {
  n = getnum(), q = getnum();
  for (int i = 1; i <= n; i++) {
    pos[i] = getnum();
    pos[i] -= i;
  }
  for (int i = 1; i <= n; i++) {
    w[i] = getnum();
    sgt.modify(i, w[i], 1, n, 1);
  }
  for (int i = 1; i <= q; i++) {
    long long x, y;
    x = getnum(), y = getnum();
    if (x > 0) {
      putnum(solve(x, y)), putchar('\n');
    } else {
      x = -x;
      w[x] = y;
      sgt.modify(x, y, 1, n, 1);
    }
  }
  return 0;
}
