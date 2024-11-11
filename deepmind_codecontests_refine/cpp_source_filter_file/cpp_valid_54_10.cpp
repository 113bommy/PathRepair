#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int mod_pow(int b, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) {
      ans = (1ll * ans * b) % mod;
      p--;
    }
    b = (1ll * b * b) % mod;
    p /= 2;
  }
  return ans;
}
const int N = (2e5 + 5);
int fac[N], inv_fac[N];
void calc_fac() {
  fac[0] = 1;
  inv_fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv_fac[i] = mod_pow(fac[i], mod - 2);
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 1;
    cout << '\n';
    return;
  }
  int e = 0;
  for (int i = 0; i < n; i += 2) {
    e = (e + 1ll * fac[n] * inv_fac[n - i] % mod * inv_fac[i] % mod) % mod;
  }
  if (n & 1) e = (e + 1) % mod;
  if (n & 1) {
    int ans = mod_pow(e, k);
    cout << ans;
    cout << '\n';
    return;
  }
  int p = mod_pow(2, n);
  int pp = mod_pow(p, k);
  int ans = 0;
  int left = 1;
  int right = pp;
  for (int i = 0; i < k; i++) {
    right = 1ll * right * mod_pow(p, mod - 2) % mod;
    ans = (ans + 1ll * left * right) % mod;
    left = (1ll * left * e) % mod;
  }
  ans = (ans + 1ll * left) % mod;
  cout << ans;
  cout << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  calc_fac();
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
