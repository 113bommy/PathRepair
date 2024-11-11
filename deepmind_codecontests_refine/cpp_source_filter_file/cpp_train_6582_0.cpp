#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using ii = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<long long>>;
using vp = vector<pair<long long, long long>>;
long long mod = 1e9 + 7;
long long fact[35];
lli fastexpo(lli x, lli y) {
  lli res = 1;
  while (y > 0) {
    if (y % 2) res = (res * x) % mod;
    x = (x * x) % mod;
    y /= 2;
  }
  return (res % mod);
}
lli inverse(lli x, lli p) { return fastexpo(x, p - 2) % p; }
void facto() {
  fact[0] = 1;
  for (lli i = 1; i < 35; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
}
lli ncr(lli n, lli r) {
  if (r >= n || r < 0) return 0;
  lli a, b;
  a = fact[n] % mod;
  b = ((fact[r] % mod) * ((fact[n - r]) % mod)) % mod;
  return (((fastexpo(b, mod - 2))) * a) % mod;
}
void solve() {
  long long n, m, t;
  cin >> n >> m >> t;
  long long ans = 0;
  for (long long b = 4; b <= n; b++) {
    if (t - b <= 0) continue;
    long long temp = ncr(n, b) * ncr(m, t - b);
    ans += temp;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  facto();
  long long _t = 1;
  for (long long ix = 1; ix <= _t; ix++) solve();
  cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC << "secs" << endl;
}
