#include <bits/stdc++.h>
using namespace std;
const long long N = 1111;
long long fact[N], invfact[N];
long long n, m, k;
long long powmod(long long x, long long n, long long m = 1000000007) {
  long long ans = 1;
  while (n) {
    if (n & 1) {
      ans = ans * x % m;
    }
    x = x * x % m;
    n >>= 1;
  }
  return ans;
}
inline long long invmod(long long x, long long m = 1000000007) {
  return powmod(x, m - 2);
}
inline long long ncr(long long n, long long r) {
  if (r < 0 || r > n) return 0;
  return fact[n] * invfact[r] % 1000000007 * invfact[n - r] % 1000000007;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  fact[0] = 1;
  invfact[0] = 1;
  for (long long i = (1); i <= (n); i++) {
    fact[i] = fact[i - 1] * i % 1000000007;
    invfact[i] = invmod(fact[i]);
  }
  long long ans = ncr(n - 1, 2 * k) * ncr(m - 1, 2 * k) % 1000000007;
  cout << ans << "\n";
  return 0;
}
