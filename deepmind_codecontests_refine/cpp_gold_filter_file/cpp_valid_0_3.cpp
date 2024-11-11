#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class C>
void mini(C& a, C b) {
  a = min(a, b);
}
template <class C>
void maxi(C& a, C b) {
  a = max(a, b);
}
const int mod = 1e9 + 7;
const int INF = 1e9;
const double eps = 0.00000001;
ll powmod(ll a, int exp) {
  if (exp == 0) return 1;
  ll b = powmod(a, exp / 2);
  b *= b;
  b %= mod;
  if (exp % 2) b *= a;
  b %= mod;
  return b;
}
ll calcinv(ll a) { return powmod(a, mod - 2); }
const int N = 3e6;
ll fact[N + 1], invfact[N + 1], inv[N + 1];
void precalc() {
  inv[1] = 1;
  for (int i = 2; i <= N; ++i) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
  fact[0] = 1;
  for (int(i) = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % mod;
  invfact[0] = 1;
  for (int(i) = 1; i <= N; i++) invfact[i] = (invfact[i - 1] * inv[i]) % mod;
}
ll comb(int n, int k) {
  ll res = fact[n];
  res *= invfact[k];
  res %= mod;
  res *= invfact[n - k];
  res %= mod;
  return res;
}
void c() {
  int n, q;
  cin >> n >> q;
  vector<ll> dp(3), dpp(3);
  vector<ll> res(q, 1);
  vector<pair<int, int> > query(q);
  for (int i = 0; i < q; i++) {
    cin >> query[i].first;
    query[i].second = i;
  }
  sort(query.begin(), query.end());
  int i = 0;
  for (int m = 0; m < 3; m++) dp[m] = n;
  for (int(x) = 1; x <= 3 * n - 1; x++) {
    dpp[0] = comb(3 * n, x + 1) - 2 * dp[0] - dp[1];
    dpp[0] %= mod;
    dpp[0] *= inv[3];
    dpp[0] %= mod;
    if (dpp[0] < 0) dpp[0] += mod;
    dpp[1] = (dpp[0] + dp[0]) % mod;
    dpp[2] = (dpp[1] + dp[1]) % mod;
    swap(dp, dpp);
    while (i < q and query[i].first == x) {
      ll resi = dp[0];
      resi += comb(3 * n, x);
      resi %= mod;
      res[query[i].second] = resi;
      i++;
    }
  }
  for (auto x : res) cout << x << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  precalc();
  c();
  return 0;
}
