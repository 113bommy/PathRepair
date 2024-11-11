#include <bits/stdc++.h>
using namespace std;
const unsigned mod = 998244353;
const unsigned _mod = 1e9 + 7;
const long long infi = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
long long ksm(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x % mod;
    y >>= 1ll;
    x = x * x % mod;
  }
  return ret;
}
long long qpow(long long x, long long y, long long m) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x % m;
    y >>= 1ll;
    x = x * x % m;
  }
  return ret;
}
long long _gcd(long long x, long long y) { return y ? _gcd(y, x % y) : x; }
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
string a;
long long fac[1000010], inv[1000010], l, r, x, y, ans;
long long C(long long n, long long m) {
  if (m > n || m < 0) return 0;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
  cin >> a;
  fac[0] = inv[0] = 1;
  for (register int i = 1; i <= 1000000; ++i) fac[i] = fac[i - 1] * i % mod;
  for (register int i = 1; i <= 1000000; ++i) inv[i] = ksm(fac[i], mod - 2);
  for (register int i = 0; i < a.size(); ++i)
    y += (a[i] == '?'), r += (a[i] == ')');
  for (register int i = 0; i < a.size(); ++i) {
    l += (a[i] == '('), r -= (a[i] == ')');
    if (a[i] == '?') x++, y--;
    ans =
        (ans + l * C(x + y, y + r - l) + x * C(x + y - 1, y - l + r - 1)) % mod;
  }
  cout << ans << '\n';
  return 0;
}
