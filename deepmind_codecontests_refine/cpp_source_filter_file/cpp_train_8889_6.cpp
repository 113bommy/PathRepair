#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
const long long mod = 1e9 + 7;
long long n, m, k;
long long pw(long long a, long long k) {
  if (k == 0) return 1;
  long long res = pw(a, k / 2);
  res = (res * res) % mod;
  if (k & 1) res = (res * a) % mod;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  long long x = max(0LL, m - (n - n % k) / k * (k - 1) - n % k);
  long long ans = (pw(2LL, x + 1) + mod - 2) % mod;
  ans = (ans * k) % mod;
  ans += m - x * k;
  ans %= mod;
  ans += mod;
  ans %= mod;
  cout << ans;
  return 0;
}
