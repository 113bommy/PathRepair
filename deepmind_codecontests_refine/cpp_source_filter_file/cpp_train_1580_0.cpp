#include <bits/stdc++.h>
namespace ringo {
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) f ^= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
template <class T>
inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar('0' + x % 10);
}
template <class T>
inline void print(T x, char c) {
  print(x), putchar(c);
}
template <class T>
inline void print(T a, int l, int r, std::string s = "") {
  if (s != "") std::cout << s << ": ";
  for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}
const int N = 1e6 + 10, mod = 998244353;
int n, m, ans, cnt, used;
int a[N], b[N], mrk[N], inv[N], fac[N], ifac[N];
inline int dec(int a, int b) {
  a -= b;
  return a < 0 ? a + mod : a;
}
inline int inc(int a, int b) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline int mul(int a, int b) {
  return (long long)a * b - (long long)a * b / mod * mod;
}
inline int binom(int n, int m) {
  return n < m ? 0 : mul(fac[n], mul(ifac[m], ifac[n - m]));
}
void init_fac(int n) {
  fac[0] = fac[1] = inv[0] = inv[1] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  for (int i = 2; i <= n; i++) inv[i] = mul(mod - mod / i, inv[mod % i]);
  for (int i = 2; i <= n; i++) ifac[i] = mul(ifac[i - 1], inv[i]);
}
int calc(int s, int m) {
  return dec(binom(s + n - 1, n - 1), binom(s + m - 1, n - 1));
}
void main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    m += a[i], b[i] = a[i];
  }
  init_fac(n + m);
  ans = 1;
  for (int i = 1; i <= m; i++) {
    for (int i = 1; i <= n; i++) {
      --b[i];
      if (b[i] < 0) {
        ++used, b[i] += n;
        if (!mrk[i]) ++cnt, mrk[i] = 1;
      }
    }
    if (used > i || cnt == n) break;
    ans = (ans + calc(i - used, cnt));
  }
  print(ans, '\n');
}
}  // namespace ringo
signed main() { return ringo::main(), 0; }
