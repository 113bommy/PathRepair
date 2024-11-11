#include <bits/stdc++.h>
using namespace std;
struct IO {
  char buf[(1 << 20)], *p1, *p2;
  char pbuf[(1 << 20)], *pp;
  IO() : p1(buf), p2(buf), pp(pbuf) {}
  inline char gc() {
    return getchar();
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, (1 << 20), stdin);
    return p1 == p2 ? ' ' : *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template <class T>
  inline void read(T &x) {
    register double tmp = 1;
    register bool sign = 0;
    x = 0;
    register char ch = gc();
    for (; !(ch >= '0' && ch <= '9'); ch = gc())
      if (ch == '-') sign = 1;
    for (; (ch >= '0' && ch <= '9'); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); (ch >= '0' && ch <= '9'); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }
  inline void read(char *s) {
    register char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }
  inline void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }
  template <class t>
  inline void write(t x) {
    if (x < 0)
      putchar('-'), write(-x);
    else {
      if (x > 9) write(x / 10);
      putchar('0' + x % 10);
    }
  }
} io;
const long long mod = 1e9 + 7;
const long long mo = 998244353;
const long long N = 505;
long long na, nb, nc, fac[25][N], v[N], V, n, B, ans;
inline void dfsb(long long x, long long b, long long a) {
  if ((double)b * b * a > V) return;
  if (x > n) {
    B = max(B, b);
    return;
  }
  for (long long j = (v[x]); j >= (0); j--) dfsb(x + 1, b * fac[x][j], a);
}
inline void dfsa(long long x, long long a) {
  if ((double)a * a * a > V) return;
  if (x > n) {
    long long tmp = V / a;
    long long S = 4ll * a * sqrt(tmp) + 2ll * tmp;
    if (S > ans) return;
    B = 0;
    dfsb(1, 1, a);
    long long c = V / a / B;
    long long now = (a * B + B * c + c * a) * 2ll;
    if (now < ans) ans = now, na = a, nb = B, nc = c;
    return;
  }
  for (long long j = (v[x]); j >= (0); j--) {
    v[x] -= j;
    dfsa(x + 1, a * fac[x][j]);
    v[x] += j;
  }
}
signed main() {
  long long Q;
  io.read(Q);
  for (; Q--;) {
    io.read(n);
    V = 1ll;
    for (long long i = (1); i <= (n); i++) {
      long long x, y;
      io.read(x);
      io.read(y);
      v[i] = y;
      fac[i][0] = 1;
      for (long long j = (1); j <= (y); j++) fac[i][j] = fac[i][j - 1] * x;
      V *= fac[i][y];
    }
    ans = 1ll << 62;
    dfsa(1, 1);
    printf("%lld %lld %lld %lld\n", ans, na, nb, nc);
  }
  return 0;
}
