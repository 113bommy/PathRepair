#include <bits/stdc++.h>
using namespace std;
namespace fastIO1 {
inline char read() {
  static const int IN_LEN = 1000000;
  static char buf[IN_LEN], *s, *t;
  return (s == t               ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin),
          (s == t ? -1 : *s++) : *s++);
}
template <class T>
inline void read(T &x) {
  static bool iosig;
  static char c;
  for (iosig = false, c = read(); !isdigit(c); c = read()) {
    if (c == '-') iosig = true;
    if (c == -1) return;
  }
  for (x = 0; isdigit(c); c = read()) x = ((x + (x << 2)) << 1) + (c ^ '0');
  if (iosig) x = -x;
}
inline char readc(char &c) {
  for (c = read(); !isalpha(c) && !isdigit(c); c = read())
    if (c == -1) return 0;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh = obuf;
inline void print(char c) {
  if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
  *ooh++ = c;
}
template <class T>
inline void print(T x) {
  static int buf[30], cnt;
  if (x == 0)
    print('0');
  else {
    if (x < 0) print('-'), x = -x;
    for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
    while (cnt) print((char)buf[cnt--]);
  }
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
}  // namespace fastIO1
namespace fastIO2 {
template <class T>
inline void read(T &x) {
  static bool iosig;
  static char c;
  for (iosig = false, c = getchar(); !isdigit(c); c = getchar()) {
    if (c == '-') iosig = true;
    if (c == -1) return;
  }
  for (x = 0; isdigit(c); c = getchar()) x = ((x + (x << 2)) << 1) + (c ^ '0');
  if (iosig) x = -x;
}
}  // namespace fastIO2
using namespace fastIO1;
long long w[(1100010)], ans, mi[(1100010)], iv[(1100010)];
int n, S, mx, Lim, rev[(1100010)];
long long ksm(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = (res * a) % (998244353);
    a = (a * a) % (998244353), p >>= 1;
  }
  return res;
}
void NTT(vector<long long> &a, int tp) {
  for (int i = 0; i < Lim; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int pos = 1, s = 1; pos < Lim; pos <<= 1, s++) {
    long long w = mi[s];
    if (tp == -1) w = iv[s];
    for (int R = pos << 1, j = 0; j < Lim; j += R) {
      long long p = 1;
      for (int k = j; k < j + pos; k++, p = (p * w) % (998244353)) {
        long long x = a[k], y = (p * a[k + pos]) % (998244353);
        a[k] = (x + y) % (998244353),
        a[k + pos] = (x - y + (998244353)) % (998244353);
      }
    }
  }
  if (tp == -1) {
    long long inv = ksm(Lim, (998244353) - 2) % (998244353);
    for (int i = 0; i < Lim; i++) a[i] = (a[i] * inv) % (998244353);
  }
}
struct Poly {
  vector<long long> a;
  int mx;
} a[(1100010)];
Poly work(int l, int r) {
  if (l == r) return a[l];
  int len = 0, mid = (l + r) >> 1;
  Poly a = work(l, mid);
  Poly b = work(mid + 1, r);
  int sum = a.mx + b.mx;
  rev[0] = 0;
  for (Lim = 1; Lim <= sum; Lim <<= 1) len++;
  for (int i = 0; i < Lim; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
  a.a.resize(Lim), b.a.resize(Lim);
  NTT(a.a, 1), NTT(b.a, 1);
  for (int i = 0; i < Lim; i++) a.a[i] = (a.a[i] * b.a[i]) % (998244353);
  NTT(a.a, -1), a.mx = sum;
  return a;
}
int A, B;
int C(int n, int m) {
  int jc = 1, ans = 1;
  for (int i = 1; i <= n; i++) {
    jc = 1ll * jc * i % (998244353);
    if (i == m) ans = 1ll * ans * ksm(jc, (998244353) - 2) % (998244353);
    if (i == n - m) ans = 1ll * ans * ksm(jc, (998244353) - 2) % (998244353);
    if (i == n) ans = 1ll * ans * jc % (998244353);
  }
  return ans;
}
int main() {
  read(n), read(A), read(B);
  if (!A || !B || A + B >= n) puts("0"), exit(0);
  if (n == 1) {
    if (A == 1 && B == 1)
      puts("1");
    else
      puts("0");
    return 0;
  }
  for (int i = 1; i <= n - 1; i++) {
    a[i].a.resize(2), a[i].mx = 1, a[i].a[1] = 1, a[i].a[0] = i - 1;
  }
  for (int i = 1; (1 << i) <= (998244353); i++)
    mi[i] = ksm(3ll, ((998244353) - 1) / (1 << i)) % (998244353),
    iv[i] = ksm(mi[i], (998244353) - 2) % (998244353);
  Poly f = work(1, n - 1);
  printf("%lld\n", 1ll * f.a[A + B - 2] * C(A + B - 2, A - 1) % (998244353));
}
