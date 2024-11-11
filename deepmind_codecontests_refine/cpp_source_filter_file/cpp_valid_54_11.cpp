#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const int mx = 2e5 + 5;
vector<int> fact(mx, 1), inv(mx, 1);
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void precompute() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < mx; i++) {
    fact[i] *= fact[i - 1] % mod;
    inv[i] = binpow(i, mod - 2, mod);
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  int flag = 0;
  if (n % 2 == 1) flag = 1;
  long long eq = 1, ans = 0;
  for (int i = 1; i <= k; i++) {
    if (flag == 1) {
      eq *= binpow(2, n - 1, mod) + 1;
      eq %= mod;
    } else {
      long long gr;
      if (i == k)
        gr = 1;
      else
        gr = binpow(binpow(2, n - 1, mod) % mod, k - i, mod);
      gr %= mod;
      gr *= eq;
      gr %= mod;
      ans += gr;
      eq *= binpow(2, n - 1, mod) - 1;
      eq += mod;
      eq %= mod;
    }
  }
  ans += eq;
  ans %= mod;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  precompute();
  while (t--) solve();
}
