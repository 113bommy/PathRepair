#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
ll f(ll x) { return x * (x + 1) / 2; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (ll &x : a) cin >> x;
  for (ll &x : b) cin >> x;
  for (int i = 0; i < n; i++) {
    a[i] *= (f(n) - f(i) - f(n - i - 1));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<ll>());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    (ans += (a[i] * b[i] % MOD)) %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
