#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MX = 505, MOD = 998244353;
inline ll pw(ll base, ll exp) {
  ll res = 1;
  while (exp) {
    if (exp & 1) (res *= base) %= MOD;
    exp >>= 1, (base *= base) %= MOD;
  }
  return res;
}
inline ll inv(ll x) { return pw(x, MOD - 2); }
ll fact[MX] = {1}, ifact[MX] = {1};
inline ll nCr(int n, int k) {
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}
ll DP[MX][MX];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 1; i < MX; ++i)
    fact[i] = i * fact[i - 1] % MOD, ifact[i] = inv(fact[i]);
  int n, x;
  cin >> n >> x;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      DP[i][j] = (pw(j, i) - pw(j - 1, i) + MOD) % MOD;
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= x; ++j) {
      for (int k = 0; i + k <= n && j + i + k - 1 <= x; ++k) {
        (DP[i + k][j + i + k - 1] +=
         nCr(i + k, i) * pw(k + 1, k) % MOD * DP[i][j] % MOD) %= MOD;
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= x; ++i) (ans += DP[n][i]) %= MOD;
  cout << ans;
}
