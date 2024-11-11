#include <bits/stdc++.h>
const long long mod = 998244353;
using namespace std;
long long a[5000005], f[5000005];
long long gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long ret = gcd(b, a % b, x, y);
    long long tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ret;
  }
}
long long inv(long long a) {
  long long x, y;
  gcd(a, mod, x, y);
  return (x % mod + mod) % mod;
}
void solve() {
  f[0] = f[1] = 1;
  for (long long i = 2; i < 5000005; i++) {
    f[i] = i * f[i - 1] % mod;
  }
  long long n, m, k, x = 0, y = 0, c = 0, q, ans = 0;
  cin >> n;
  x += f[n];
  for (long long i = 1; i < n; ++i) {
    x += f[n] - f[n] * inv(f[i]);
    x %= mod;
  }
  x = (x + mod) % mod;
  cout << x << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
