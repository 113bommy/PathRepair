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
const int mod = 1e9 + 7;
const int mo = 998244353;
const int N = 1e5 + 5;
const int M = 505;
int n, m;
double f[2][M];
int main() {
  io.read(n), io.read(m);
  double P = 1.0 / (1.0 * m);
  for (int i = (1); i <= (n); i++) {
    memset(f[i & 1], 0, sizeof(f[i & 1]));
    for (int j = (1); j <= (min(500, n)); j++) {
      double gs1 = (f[(i - 1) & 1][j + 1] + j) * P;
      gs1 = gs1 / (1.0 * (j + 1));
      double gs2 = (f[(i - 1) & 1][j] + (j + 1) / 2.0) * P;
      gs2 = gs2 * j / (1.0 * (j + 1));
      double gs3 = (f[(i - 1) & 1][j]) * (m - 1) / (1.0 * m);
      f[i & 1][j] += gs1 + gs2 + gs3;
    }
  }
  printf("%.10lf\n", f[n & 1][1] * m);
  return 0;
}
