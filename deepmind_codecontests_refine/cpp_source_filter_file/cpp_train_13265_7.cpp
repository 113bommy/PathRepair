#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
T pow_mod(T a, U b, int mod) {
  T r = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) r = (long long)r * a % mod;
    a = (long long)a * a % mod;
  }
  return r;
}
const int mod = 1e9 + 7, N = 2505;
int fac[N], ifac[N];
void init() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = (long long)fac[i - 1] * i % mod;
    ifac[i] = pow_mod(fac[i], mod - 2, mod);
  }
}
int comb(int n, int k) {
  return (long long)fac[n] * ifac[n - k] % mod * ifac[k] % mod;
}
int starsandbars(int n, int k) { return comb(n + k - 1, k - 1); }
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    for (int j = 2; j * j <= x; ++j)
      if (x % j == 0) {
        int c = 0;
        while (x % j == 0) x /= j, ++c;
        mp[j] += c;
      }
    if (x > 1) ++mp[x];
  }
  init();
  int ans = 1;
  for (auto i : mp) ans = (long long)ans * starsandbars(i.second, n) % mod;
  cout << ans << "\n";
  return 0;
}
