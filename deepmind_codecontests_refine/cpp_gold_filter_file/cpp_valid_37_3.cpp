#include <bits/stdc++.h>
using namespace std;
int recur_depth = 0;
const long long sz = 1e5 + 10, mod = 998244353;
vector<long long> g[sz];
long long ans[sz], dp[sz];
void dfs(long long u, long long p, long long k) {
  for (long long& v : g[u]) {
    if (v == p) continue;
    dfs(v, u, k);
    if (dp[v] % k != 0)
      dp[v]++;
    else
      dp[u]++;
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i <= n - 1; ++i) {
      long long u, v;
      scanf("%lld", &u), scanf("%lld", &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    long long m = n - 1;
    ans[1] = 1;
    for (long long i = 1; i <= m; ++i) ans[1] = (ans[1] * 2) % mod;
    for (long long i = 2; i <= m; i++) {
      if (m % i == 0) {
        for (long long j = 1; j <= n; ++j) dp[j] = 0;
        dfs(1, -1, i);
        bool ok = 1;
        for (long long j = 1; j <= n; ++j) ok &= (dp[j] % i == 0);
        ans[i] = ok;
      }
    }
    for (long long i = n; i >= 1; --i)
      for (long long j = i + i; j <= n; j += i) ans[i] -= ans[j];
    for (long long i = 1; i <= n; ++i) {
      if (ans[i] < 0) ans[i] += mod;
      printf("%lld ", ans[i]);
    }
    printf("\n");
    for (long long i = 1; i <= n; ++i) g[i].clear(), ans[i] = 0;
  }
  return 0;
}
