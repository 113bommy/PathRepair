#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long frac[1000100], rfrac[1000100];
long long pw(long long x, long long y) {
  x = (x % mod + mod) % mod;
  y = (y % (mod - 1) + mod - 1) % (mod - 1);
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
int main() {
  frac[0] = 1;
  for (int i = 1; i <= 1e6; i++) frac[i] = frac[i - 1] * i % mod;
  rfrac[1000000] = pw(frac[1000000], -1);
  for (int i = 1e6; i > 0; i--) rfrac[i - 1] = rfrac[i] * i % mod;
  long long n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long x = frac[n] * rfrac[i] % mod * rfrac[n - i] % mod;
    if (i & 1) x = (mod - x) % mod;
    x = x * (pw(-pw(3, i) + 1, n) - pw(-pw(3, i), n) + mod) % mod;
    ans = (ans - x * 3 % mod +
           2 * frac[n] * rfrac[i + 1] % mod * rfrac[n - i - 1] % mod *
               pw(-1, i) % mod * pw(3, i + 1 + n * (n - i - 1)) % mod +
           mod) %
          mod;
  }
  cout << ans << endl;
  return 0;
}
