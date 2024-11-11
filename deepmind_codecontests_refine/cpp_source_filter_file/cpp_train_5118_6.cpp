#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  register long long res = 0, lab = 1;
  register char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != EOF) {
    if (ch == '-') lab = -lab;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    res = (res << 3) + (res << 1) + (ch & 15), ch = getchar();
  return res * lab;
}
inline double rdf() {
  double res = 0, g = 1;
  int lab = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != EOF)
    lab = lab ^ (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9') res = res * 10 + (ch & 15), ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch >= '0' && ch <= '9')
      g *= 0.1, res += g * (ch & 15), ch = getchar();
  }
  return lab ? res : -res;
}
inline void prt(long long x, char t = '\n') {
  static char ch[70];
  int tp = 0;
  if (!x) {
    fputs("0", stdout);
    if (t) putchar(t);
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  while (x) ch[++tp] = (x % 10) ^ 48, x /= 10;
  while (tp) putchar(ch[tp--]);
  if (t) putchar(t);
}
inline long long tomax(long long& a, long long b) {
  return a > b ? a : (a = b);
}
inline long long tomin(long long& a, long long b) {
  return a < b ? a : (a = b);
}
inline long long umax(long long a, long long b) { return a > b ? a : b; }
inline long long umin(long long a, long long b) { return a < b ? a : b; }
inline long long uabs(long long x) { return x > 0 ? x : -x; }
inline long long sqr(long long x) { return x * x; }
inline long long qpow(long long n, long long e = 1000000007 - 2,
                      long long p = 1000000007) {
  n %= p;
  register long long res = 1;
  while (e) {
    if (e & 1) res = res * n % p;
    n = n * n % p;
    e >>= 1;
  }
  return res;
}
const long long ir = 1000000007 - 1;
struct cpx {
  int r, i;
  cpx(long long a = 0, long long b = 0)
      : r(a % 1000000007), i(b % 1000000007) {}
  cpx operator+(const cpx& _) const { return cpx(r + _.r, i + _.i); }
  cpx operator-(const cpx& _) const {
    return cpx(r - _.r + 1000000007, i - _.i + 1000000007);
  }
  cpx operator*(const cpx& _) const {
    return cpx((1ll * r * _.r + ir * i * _.i) % 1000000007,
               (1ll * r * _.i + 1ll * i * _.r) % 1000000007);
  }
};
inline cpx qpow(cpx n, long long e) {
  register cpx res(1);
  while (e) {
    if (e & 1) res = res * n;
    n = n * n;
    e >>= 1;
  }
  return res;
}
long long n, m;
bitset<10005> b[50];
int main() {
  m = rd();
  n = rd();
  for (int i = 1; i <= m; ++i) {
    long long x = rd();
    while (x--) b[i][rd()] = 1;
  }
  for (int i = 1; i <= m; ++i)
    for (int j = i + 1; j <= m; ++j)
      if (!((b[i] & b[j]).count())) return puts("impossible"), 0;
  puts("possible");
  return 0;
}
