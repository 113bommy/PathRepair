#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res % p;
}
long long raichu(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = ((res) * (x));
    y = y >> 1;
    x = ((x) * (x));
  }
  return res;
}
bool isprime(long long n) {
  if (n < 2)
    return false;
  else if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;
  else {
    long long z = sqrt(n);
    for (int i = 0; i < z - 1; i++)
      if (n % (i + 2) == 0) return false;
    return true;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tests = 1, Tests;
  Tests = tests;
  while (tests--) {
    int n;
    cin >> n;
    vector<double> v(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> v[i];
    int x = 0;
    double S = 0;
    double T = 0;
    for (int i = 0; i < 2 * n; i++) T += v[i];
    for (int i = 0; i < 2 * n; i++) {
      int z = (int)v[i];
      S += z;
      if (z == v[i]) {
        x++;
      }
    }
    double ans = 1e15;
    for (int i = 0; i < min(n, x) + 1; i++) {
      int left = n - i;
      ans = min(ans, abs(S + left - T));
    }
    cout << fixed << setprecision(10) << ans;
  }
  return 0;
}
