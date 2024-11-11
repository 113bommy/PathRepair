#include <bits/stdc++.h>
using namespace std;
const long long maxl = 2e5 + 7;
const long long mod = 998244353;
vector<long long> v[2];
long long dp[2][maxl];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    vector<long long> nana(n + 10);
    for (long long i = 1; i <= n; i++) cin >> nana[i];
    for (long long i = n; i >= 1; i--) {
      long long k = i & 1;
      v[k].push_back(nana[i]);
      dp[k][nana[i]] = 1;
      long long las = nana[i];
      for (auto& x : v[k ^ 1]) {
        long long chuxiancishu = dp[k ^ 1][x];
        long long fenkuai = (nana[i] + x - 1) / x;
        long long newx = nana[i] / fenkuai;
        ans += chuxiancishu * i % mod * (fenkuai - 1) % mod;
        dp[k][newx] += chuxiancishu;
        if (las != newx) v[k].push_back(newx), las = newx;
      }
      for (auto& x : v[k ^ 1]) dp[k ^ 1][x] = 0;
      v[k ^ 1].clear();
      ans %= mod;
    }
    cout << ans << '\n';
    for (auto& x : v[0]) dp[0][x] = 0;
    for (auto& x : v[1]) dp[1][x] = 0;
    v[0].clear(), v[1].clear();
  }
}
