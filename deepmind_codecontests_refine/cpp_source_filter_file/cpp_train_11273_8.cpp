#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long mx = 160000;
vector<long long> fact(mx, 1);
vector<long long> ifact(mx, 1);
vector<long long> invs(mx, 1);
void init() {
  for (long long i = 2; i < mx; i++) {
    invs[i] = mod - (long long)mod / i * invs[mod % i] % mod;
  }
  for (long long i = 1; i < mx; i++) {
    fact[i] = (long long)fact[i - 1] * i % mod;
    ifact[i] = (long long)ifact[i - 1] * invs[i] % mod;
  }
}
long long comb(long long n, long long k) {
  if (k < 0 || k > n) return 0;
  return 1ll * fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}
int main() {
  init();
  long long n;
  cin >> n;
  long long ans = 0;
  vector<long long> v(2 * n, 0);
  for (auto &in : v) cin >> in;
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) ans = (ans - v[i] + mod) % mod;
  for (long long i = n; i < 2 * n; i++) ans = (ans + v[i]) % mod;
  ans = (1ll * ans * comb(2 * n, n)) % mod;
  cout << ans << "\n";
  return 0;
}
