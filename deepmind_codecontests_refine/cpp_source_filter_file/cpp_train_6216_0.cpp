#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long find_max(long long x, long long y, long long mod) {
  long long ans = 0;
  while (y) {
    if (y & 1) {
      ans = (ans + x);
      if (ans > mod) ans -= mod;
    }
    x = 2 * x;
    if (x > mod) x -= mod;
    y >>= 1;
  }
  return ans;
}
long long check(long long x, long long y, long long mod) {
  long long sol = 1;
  while (y) {
    if (y & 1) sol = find_max(sol, x, mod);
    x = find_max(x, x, mod);
    y >>= 1;
  }
  return sol;
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long T;
  cin >> T;
  while (T--) {
    long long p, q, b;
    cin >> p >> q >> b;
    long long mod = gcd(p, q);
    p /= mod, q /= mod;
    b %= q;
    if (check(b, 64, q) == 0)
      cout << "Finite\n";
    else
      cout << "Infinite\n";
  }
}
