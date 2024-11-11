#include <bits/stdc++.h>
using namespace std;
inline char gc(void) {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <class T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  static char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -f;
  for (; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}
inline void readstr(char *s) {
  do *s = gc();
  while ((*s == ' ') || (*s == '\n') || (*s == '\r'));
  do *(++s) = gc();
  while ((~*s) && (*s != ' ') && (*s != '\n') && (*s != '\r'));
  *s = 0;
  return;
}
inline void readch(char &x) {
  while (isspace(x = gc()))
    ;
}
char pf[100000], *o1 = pf, *o2 = pf + 100000;
template <class T>
inline void writeln(T x, char c = '\n') {
  if (x < 0)
    (o1 == o2 ? fwrite(pf, 1, 100000, stdout), *(o1 = pf)++ = 45 : *o1++ = 45),
        x = -x;
  static char s[15], *b;
  b = s;
  if (!x) *b++ = 48;
  for (; x; *b++ = x % 10 + 48, x /= 10)
    ;
  for (; b-- != s; (o1 == o2          ? fwrite(pf, 1, 100000, stdout),
                    *(o1 = pf)++ = *b : *o1++ = *b))
    ;
  (o1 == o2 ? fwrite(pf, 1, 100000, stdout), *(o1 = pf)++ = c : *o1++ = c);
}
const int MOD = 998244353, N = 5010;
inline int add(int &x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
inline int ksm(int x, int y) {
  int k = 1;
  while (y) {
    if (y & 1) k = 1LL * k * x % MOD;
    x = 1LL * x * x % MOD;
    y >>= 1;
  }
  return k;
}
int f[N], s[N], fac[N], inv[N], a[N], lim[N];
int main() {
  int n;
  read(n);
  fac[0] = 1;
  for (register int i = (1); i <= (n); i++) fac[i] = 1LL * i * fac[i - 1] % MOD;
  inv[n] = ksm(fac[n], MOD - 2);
  for (register int i = (n - 1); i >= (0); i--)
    inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
  for (register int i = (1); i <= (n); i++) read(a[i]);
  sort(a + 1, a + n + 1);
  int l = 0, r = 1;
  while (r <= n) {
    while (a[l + 1] * 2 <= a[r]) l++;
    lim[r] = l;
    r++;
  }
  f[0] = 1;
  lim[0] = -1;
  s[0] = f[0] * fac[n - lim[0] - 2];
  for (register int i = (1); i <= (n); i++) {
    f[i] = 1LL * s[lim[i]] * inv[n - lim[i] - 1] % MOD;
    s[i] = add(s[i - 1], 1LL * f[i] * fac[n - lim[i] - 2] % MOD);
  }
  if (lim[n] == n - 1)
    writeln(f[n]);
  else
    puts("0");
  fwrite(pf, 1, o1 - pf, stdout);
  return 0;
}
