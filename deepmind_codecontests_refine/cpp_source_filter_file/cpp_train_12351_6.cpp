#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const int MAXN = 2001;
constexpr ll MOD = 998244353;
ll mul(ll a, ll b) { return (a * b) % MOD; }
ll pw(ll a, ll b = MOD - 2) {
  if (!b) {
    return 1;
  }
  ll v = pw(a, b / 2);
  v = mul(v, v);
  if (b & 1) {
    v = mul(v, a);
  }
  return v;
}
ll f[MAXN][MAXN];
ll same[MAXN];
ll ans[MAXN];
ll winp[MAXN];
ll losep[MAXN];
ll matches(ll n) { return (n * (n - 1)) / 2; }
ll norm(ll x) {
  x %= MOD;
  if (x < 0) {
    x += MOD;
  }
  return x;
}
ll val(ll p, ll q) { return (p * pw(q)) % MOD; }
int main() {
  ios_base::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(20);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int n, a, b;
  cin >> n >> a >> b;
  ll win = mul(a, pw(b));
  ll lose = (1 + MOD - win) % MOD;
  winp[0] = 1;
  losep[0] = 1;
  for (int i = 1; i <= n; ++i) {
    winp[i] = mul(winp[i - 1], win);
    losep[i] = mul(losep[i - 1], lose);
  }
  f[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; i + j < n; ++j) {
      f[i + 1][j] = (f[i + 1][j] + f[i][j] * losep[j]) % MOD;
      f[i][j + 1] = (f[i][j + 1] + f[i][j] * winp[i]) % MOD;
    }
  }
  same[1] = 1;
  ans[1] = 0;
  for (int i = 2; i <= n; ++i) {
    same[i] = 1;
    ll cans = 0;
    for (int j = 1; j < i; ++j) {
      ll cur = mul(f[j][i - j], same[j]);
      same[i] = norm(same[i] - cur);
      cans = norm(cans + cur * (ans[j] + ans[i - j] - matches(i - j)));
    }
    cans = mul(cans, pw(1 - same[i]));
    ll m = matches(i);
    ll ad = mul(m, pw(1 + MOD - same[i]));
    ans[i] = (cans + ad) % MOD;
  }
  cout << ans[n] << "\n";
}
