#include <bits/stdc++.h>
using namespace std;
const long long mx = 1e6 + 10, m = 1000 * 1000 * 1000 + 7;
long long fact[mx], inv[mx];
long long _pow(long long a, long long b) {
  if (!b) return 1;
  return ((_pow((a * a) % m, b >> 1) * ((b & 1) ? a : 1)) % m);
}
long long choose(long long n, long long k) {
  return ((((fact[n] * inv[k]) % m) * inv[n - k]) % m);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  for (long long i = 1; i <= mx; i++) fact[i] = (fact[i - 1] * i) % m;
  inv[mx] = _pow(fact[mx], m - 2);
  for (long long i = mx - 1; i >= 0; i--) {
    inv[i] = ((inv[i + 1] * (i + 1)) % m);
  }
  long long q, t, x, y, ans;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    ans = 1;
    for (long long i = 2; i * i <= x; i++) {
      t = 0;
      while (!(x % i)) {
        x /= i;
        t++;
      }
      if (t) {
        ans *= choose(y + t - 1, t);
        ans %= m;
      }
    }
    if (x != 1) {
      ans *= y;
      ans %= m;
    }
    ans *= _pow(2, y - 1);
    ans %= m;
    cout << ans << endl;
  }
  return 0;
}
