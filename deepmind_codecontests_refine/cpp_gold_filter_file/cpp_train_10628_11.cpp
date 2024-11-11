#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long MOD = 1e9 + 7;
long long n, m, ctr = 0;
long long s[N], t[N], dp[N], pre[N];
map<long long, long long> comp;
vector<long long> g[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> s[i] >> t[i];
    comp[s[i]];
    comp[t[i]];
  }
  comp[0];
  comp[n];
  for (auto &it : comp) it.second = ++ctr;
  for (long long i = 1; i <= m; i++) {
    s[i] = comp[s[i]], t[i] = comp[t[i]];
    g[t[i]].push_back(s[i]);
  }
  dp[1] = 1;
  pre[1] = 1;
  for (long long i = 2; i <= ctr; i++) {
    long long ans = 0;
    for (auto &it : g[i]) {
      dp[i] += (pre[i - 1] - pre[it - 1] + MOD);
      dp[i] %= MOD;
    }
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    pre[i] = dp[i] + pre[i - 1];
    dp[i] %= MOD;
    pre[i] %= MOD;
  }
  long long ans = dp[ctr];
  ans %= MOD;
  cout << ans;
  return 0;
}
