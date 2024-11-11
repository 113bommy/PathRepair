#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const long long N = 3e5 + 7;
const long long MOD = 1e9 + 7;
long long pw(long long b, long long p) {
  b %= MOD;
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = res * b % MOD;
    b = b * b % MOD;
    p >>= 1;
  }
  return res;
}
long long n, m, cur;
vector<vector<pair<long long, char>>> g(107);
bool vis[107][107][26], dp[107][107][26];
bool dfs(long long u, long long v, char ch) {
  if (vis[u][v][ch - 'a']) return dp[u][v][ch - 'a'];
  for (auto i : g[u]) {
    if (i.second >= ch && !dfs(v, i.first, i.second)) dp[u][v][ch - 'a'] = 1;
  }
  vis[u][v][ch - 'a'] = 1;
  return dp[u][v][ch - 'a'];
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  long long u, v;
  char ch;
  for (long long i = 1; i < m + 1; i++) {
    cin >> u >> v >> ch;
    g[u].emplace_back(v, ch);
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < n + 1; j++) {
      if (dfs(i, j, 'a'))
        cout << 'A';
      else
        cout << 'B';
    }
    cout << '\n';
  }
  return 0;
}
