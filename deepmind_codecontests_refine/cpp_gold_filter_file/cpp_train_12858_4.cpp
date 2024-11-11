#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long inv2, n, m, ans;
long long inline qpow(long long a, long long p) {
  long long res = 1;
  for (; p; p >>= 1) {
    p & 1 && (res = res * a % mod);
    a = a * a % mod;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  inv2 = qpow(2, mod - 2);
  cin >> n >> m;
  for (long long d = 1, l, r;;) {
    l = min(m, n / (d + 1)) + 1, r = min(m, n / d);
    ans += d % mod * ((l + r) % mod) % mod * ((r - l + 1) % mod) % mod * inv2 %
           mod;
    ans %= mod;
    if (d == n) break;
    d = n / (n / (d + 1));
  }
  ans = ((n % mod * (m % mod) % mod - ans) + mod) % mod;
  cout << ans << '\n';
}
