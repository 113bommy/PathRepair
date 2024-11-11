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
const long long N = 2e5 + 5;
long long n, L, m, a[N];
inline void Add(long long &x, long long y) {
  x += y;
  if (x >= mod) x %= mod;
}
struct Node {
  long long a[105];
  Node() { memset(a, 0, sizeof(a)); }
  inline Node friend operator*(Node &s, Node &t) {
    Node c;
    for (long long i = (0); i <= (m - 1); i++)
      for (long long j = (0); j <= (m - 1); j++)
        Add(c.a[(i + j) % m], s.a[i] * t.a[j] % mod);
    return c;
  }
};
Node A, B, C;
inline Node ksm(Node a, long long y) {
  Node ans;
  ans = a;
  y--;
  while (y) {
    if (y & 1) ans = ans * a;
    a = a * a;
    y >>= 1ll;
  }
  return ans;
}
signed main() {
  io.read(n), io.read(L), io.read(m);
  for (long long i = (1); i <= (n); i++) {
    long long x;
    io.read(x);
    A.a[x % m]++;
  }
  for (long long i = (1); i <= (n); i++) {
    long long x;
    io.read(x);
    a[i] = x;
    B.a[x % m]++;
  }
  for (long long i = (1); i <= (n); i++) {
    long long x;
    io.read(x);
    C.a[(x + a[i]) % m]++;
  }
  Node ans;
  if (L > 2) {
    ans = ksm(B, L - 2);
    ans = ans * A;
    ans = ans * C;
  } else
    ans = A * C;
  long long Ans = 0;
  for (long long i = (0); i <= (100); i++)
    if (!(i % m)) Add(Ans, ans.a[i]);
  io.write(Ans);
  return 0;
}
