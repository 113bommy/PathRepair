#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int k, n;
int qpow(int a, long long b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return ans;
}
map<long long, int> mp;
map<string, int> qwq;
map<long long, int> dp[3];
map<long long, set<long long> > G;
void dfs(long long u) {
  for (auto v : G[u]) dfs(v);
  for (int c = 0; c < 3; ++c) {
    if (~mp[u] && c ^ mp[u]) continue;
    dp[c][u] = ~mp[u] ? 1 : 2;
    for (auto v : G[u]) {
      dp[c][u] =
          1LL * dp[c][u] * (dp[(c + 1) % 3][v] + dp[(c + 2) % 3][v]) % mod;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> n;
  qwq["white"] = 0;
  qwq["yellow"] = 0;
  qwq["green"] = 1;
  qwq["blue"] = 1;
  qwq["red"] = 2;
  qwq["orange"] = 2;
  for (int i = 1; i <= n; ++i) {
    long long u;
    string s;
    cin >> u >> s;
    mp[u] = qwq[s];
  }
  if (!mp.count(1)) mp[1] = -1;
  auto tmp = mp;
  for (auto [_t, c] : tmp) {
    long long t = _t;
    while (t ^ 1) {
      G[t >> 1].insert(t);
      if (!mp.count(t)) mp[t] = -1;
      t >>= 1;
    }
  }
  dfs(1);
  int ans = 1LL * ((dp[0][1] + dp[1][1]) + dp[2][1]) % mod *
            qpow(4, (1LL << k) - 1 - mp.size()) % mod;
  cout << ans << '\n';
  return 0;
}
