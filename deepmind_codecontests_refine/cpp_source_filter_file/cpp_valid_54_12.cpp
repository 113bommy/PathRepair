#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int tt;
int n, k;
ll der[maxn];
ll f[maxn], dp[maxn], inv[maxn];
ll bigmod(ll a, ll b) {
  if (b == 0) return 1ll;
  ll g = bigmod(a, b / 2);
  if (b % 2) return (((g * g) % mod) * a) % mod;
  return (g * g) % mod;
}
ll C(ll a, ll b) { return (((f[a] * inv[a - b]) % mod) * inv[b]) % mod; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  f[0] = inv[0] = 1;
  for (int i = 1; i <= 2e5; i++) f[i] = (f[i - 1] * i) % mod;
  for (int i = 1; i <= 2e5; i++) inv[i] = bigmod(f[i], mod - 2);
  der[0] = 1;
  for (int i = 1; i <= 2e5; i++) der[i] = (der[i - 1] * 2) % (mod - 1);
  cin >> tt;
  while (tt--) {
    cin >> n >> k;
    for (int i = 0; i <= n; i += 2) {
      dp[i] = C(n, i);
      if (i) dp[i] = (dp[i] + dp[i - 2]) % mod;
    }
    if (n % 2) {
      ll ans = 0;
      for (int i = 0; i <= k; i++) {
        ll nw = (C(k, i) * bigmod(dp[n - 1], k - i)) % mod;
        ans = (ans + nw) % mod;
      }
      cout << ans << '\n';
    } else {
      ll ans = bigmod(dp[n - 2], k);
      for (int i = k - 1; i >= 0; i--) {
        ll nw = bigmod(dp[n - 2], k - i - 1);
        nw = (nw * bigmod(der[n], i)) % mod;
        ans = (ans + nw) % mod;
      }
      cout << ans << '\n';
    }
  }
}
