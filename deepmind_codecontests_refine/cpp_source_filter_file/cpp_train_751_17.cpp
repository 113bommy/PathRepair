#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ld = long double;
const ld EPS = 1e-9;
const ld PI = 3.141592653589793;
const int maxn = 300001;
const ll MOD = 998244353;
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
ll mul(ll a, ll b) { return a * b % MOD; }
ll add(ll a, ll b) { return (a + b) % MOD; }
ll pw(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
  }
  return res;
}
ll inv(ll val) { return pw(val, MOD - 2); }
ll dv(ll a, ll b) { return mul(a, inv(b)); }
signed main() {
  function<void()> solve = [] {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &el : a) {
      cin >> el;
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    vector<int> f(sum);
    f[0] = n - 1;
    for (int i = 1; i < f.size(); ++i) {
      ll xx = dv(sum - i, sum) * dv(n - 2, n - 1) % MOD;
      ll znam = add(add(1, MOD - dv(i, sum)), MOD - xx);
      f[i] = dv(1 + f[i - 1] * dv(i, sum) % MOD, znam);
    }
    f.push_back(0);
    42;
    vector<ll> suff_sum(f.size());
    suff_sum.back() = 0;
    for (int i = static_cast<int>(suff_sum.size()) - 2; i >= 0; --i) {
      suff_sum[i] = suff_sum[i + 1] + f[i];
    }
    ll E_shtrix = 0;
    ll C = suff_sum[0];
    for (int i = 0; i < n; ++i) {
      E_shtrix = add(suff_sum[a[i]], E_shtrix);
    }
    ll ans = dv(add(E_shtrix, MOD - mul(n - 1, C)), n);
    cout << ans << "\n";
  };
  fast_io();
  cout.precision(6);
  cout << fixed;
  auto start = chrono::steady_clock::now();
  solve();
  auto end = chrono::steady_clock::now();
  42;
}
