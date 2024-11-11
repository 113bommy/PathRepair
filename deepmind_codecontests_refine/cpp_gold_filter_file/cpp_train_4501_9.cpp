#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353LL;
vector<long long int> fact(200005), inv_fact(200005);
long long int bin_exp(long long int a, long long int b) {
  a = a % mod;
  long long int ans = 1;
  while (b > 0) {
    if (b & 1 == 1) ans = (a * ans) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return ans;
}
long long int mod_inv(long long int n) {
  long long int a = bin_exp(n, mod - 2);
  return a;
}
void calc() {
  fact[0] = 1;
  inv_fact[0] = 1;
  for (long long int i = 1; i < 200005; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv_fact[i] = (inv_fact[i - 1] * mod_inv(i)) % mod;
  }
}
long long int nCr(long long int n, long long int r) {
  long long int ans = (fact[n] * ((inv_fact[n - r] * inv_fact[r]) % mod)) % mod;
  return ans;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  if (n == 2) {
    cout << 0 << "\n";
    return;
  }
  long long int d = nCr(m, n - 1);
  long long int ans = (d * (n - 2)) % mod;
  (ans *= bin_exp(2, n - 3)) %= mod;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  calc();
  for (long long int i = 0; i < t; i++) {
    solve();
  }
}
