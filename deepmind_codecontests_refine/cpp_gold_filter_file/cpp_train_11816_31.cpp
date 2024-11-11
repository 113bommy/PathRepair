#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, INF = 1e18;
long long power(long long u, long long v) {
  long long res = 1;
  while (v) {
    if (v & 1) res = (res * u) % mod;
    u = (u * u) % mod;
    v >>= 1;
  }
  return res;
}
long long modInv(long long u) { return power(u, mod - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    vector<long long> fac(200010), facInv(200010);
    fac[0] = facInv[0] = 1;
    for (long long i = 1; i <= 200000; i++) {
      fac[i] = (i * fac[i - 1]) % mod;
      facInv[i] = modInv(fac[i]);
    }
    long long h, w, n;
    cin >> h >> w >> n;
    vector<pair<long long, long long> > a(n);
    for (int i = 0; i < n; i++) {
      long long u, v;
      cin >> u >> v;
      a[i] = {u, v};
    }
    a.push_back({h, w});
    sort(a.begin(), a.end());
    vector<long long> dp(n + 1);
    auto nCr = [=](long long u, long long v) {
      long long res = fac[u + v];
      res = (res * facInv[u]) % mod;
      res = (res * facInv[v]) % mod;
      return res;
    };
    for (int i = 0; i <= n; i++) {
      dp[i] = nCr(a[i].first - 1, a[i].second - 1);
      for (int j = 0; j < i; j++) {
        if (a[j].second <= a[i].second)
          dp[i] = dp[i] - (dp[j] * nCr(a[i].first - a[j].first,
                                       a[i].second - a[j].second)) %
                              mod;
        dp[i] = (dp[i] + mod) % mod;
      }
    }
    cout << dp[n] << "\n";
  }
  return 0;
}
