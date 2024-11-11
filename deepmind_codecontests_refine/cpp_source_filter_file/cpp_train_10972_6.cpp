#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = LONG_MAX;
const long long inf64 = LLONG_MAX;
const long double pi = 3.1415926535897932384626433832795;
long long mod = 1000000009;
long long bpow(long long a, long long b) {
  if (b == 0) return 1;
  return (bpow(a * a, b / 2) * (b % 2 == 0 ? 1 : a)) % mod;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int g = n - m;
  int gg = n / k - g;
  if (gg < 0) gg = 0;
  long long ans = (k * 1ll * (bpow(2, gg + 1) + mod - 2)) % mod;
  ans = (ans + (n - gg * k) - g) % mod;
  cout << ans;
  return 0;
}
