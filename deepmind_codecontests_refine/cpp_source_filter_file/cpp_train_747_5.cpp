#include <bits/stdc++.h>
using namespace std;
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline long long read() {
  bool sign = 0;
  char ch = nc();
  long long x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return 0;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (sign) x = -x;
  return x;
}
};  // namespace fastIO
using namespace fastIO;
long long qpow(long long n, long long k) {
  long long ans = 1;
  while (k) {
    if (k & 1) ans *= n, ans %= 998244353;
    n *= n, n %= 998244353;
    k >>= 1;
  }
  return ans;
}
char s[1000010];
long long fac[1000010], ifac[1000010], l[1000010], r[1000010], x[1000010],
    y[1000010];
long long c(long long x, long long y) {
  return fac[x] * ifac[x - y] % 998244353 * ifac[y] % 998244353;
}
signed main() {
  cin >> s + 1;
  long long n = strlen(s + 1);
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % 998244353;
  }
  ifac[n] = qpow(fac[n], 998244353 - 2);
  for (long long i = n - 1; i >= 0; i--)
    ifac[i] = ifac[i + 1] * (i + 1) % 998244353;
  for (long long i = 1; i <= n; i++) {
    l[i] = l[i - 1] + (s[i] == '(');
    x[i] = x[i - 1] + (s[i] == '?');
  }
  for (long long i = n; i >= 1; i--) {
    r[i] = r[i + 1] + (s[i] == ')');
    y[i] = y[i + 1] + (s[i] == '?');
  }
  long long ans = 0;
  for (long long i = 1; i <= n - 1; i++) {
    ans += l[i] * c(x[i] + y[i + 1], y[i + 1] - l[i] + r[i + 1]) +
           x[i] * c(x[i] + y[i + 1] - 1, y[i + 1] - l[i] + r[i + 1] - 1),
        ans %= 998244353;
  }
  cout << ans;
  return 0;
}
