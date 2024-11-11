#include <bits/stdc++.h>
const long long mxn = 1e6 + 7;
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 9;
using namespace std;
long long n, f[mxn], c[mxn], a, b, ans = 0;
long long check(long long x) {
  while (x > 0) {
    if (x % 10 != a && x % 10 != b) {
      return 0;
    }
    x /= 10;
  }
  return 1;
}
long long bin_pow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    long long b = bin_pow(a, n / 2) % mod;
    return b * b;
  } else {
    return bin_pow(a, n - 1) % mod * a % mod;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cout.tie(0);
  cin.tie(0);
  cin >> a >> b >> n;
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }
  for (int i = 1; i <= n; i++) {
    long long sum = a * i + b * (n - i);
    if (check(sum)) {
      ans += f[n] * bin_pow(f[i] * f[n - i] % mod, mod - 2) % mod;
      ans %= mod;
    }
  }
  cout << ans;
  return 0;
}
