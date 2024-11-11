#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll mxn = 1e6;
ll fact[mxn + 1];
ll a, b;
bool dsum(ll n) {
  while (n > 0) {
    ll cur = n % 10;
    if (cur != a && cur != b) return false;
    n /= 10;
  }
  return true;
}
ll binpow(ll a, ll b) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
    ans %= mod;
    a %= mod;
  }
  return ans;
}
ll modinverse(ll n) { return binpow(n, mod - 2); }
ll binom(ll n, ll k) {
  if (k == 0) return 1;
  ll ans = fact[n];
  ans *= modinverse(fact[k]);
  ans %= mod;
  ans *= modinverse(fact[n - k]);
  ans %= mod;
  return ans;
}
int main() {
  fact[0] = 1;
  for (ll i = 1; i < mxn; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  ll n;
  cin >> a >> b >> n;
  ll ans = 0;
  for (ll i = 0; i <= n; i++) {
    ll sum = a * i + b * (n - i);
    if (dsum(sum)) ans += binom(n, i);
    ans %= mod;
  }
  cout << ans << endl;
}
