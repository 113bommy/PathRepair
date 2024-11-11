#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  if (n == 1) return a % mod;
  long long int q = power(a, n >> 1);
  q = q * q % mod;
  if (n & 1) q = q * a % mod;
  return q;
}
int main(int argc, char **argv) {
  int n;
  cin >> n;
  vector<long long int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  vector<pair<long long int, long long int> > c(n);
  c[n - 1].first = 1;
  long long int inv = power(100, mod - 2);
  c[n - 1].second = (100 - p[n - 1]) * inv % mod;
  for (int i = n - 2; i >= 0; i--) {
    c[i].first = (100 + (c[i + 1].first * p[i] % mod)) * inv % mod;
    c[i].second =
        1ll * (100 - p[i] + (p[i] * c[i + 1].second) % mod) * inv % mod;
    if (c[i].second < 0) c[i].second += mod;
  }
  long long int ans = c[0].first * power(1 - c[0].second + mod, mod - 2) % mod;
  cout << ans << "\n";
  return 0;
}
