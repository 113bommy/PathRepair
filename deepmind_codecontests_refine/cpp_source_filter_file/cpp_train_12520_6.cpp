#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000 + 7;
const long long N = 100005;
const long long M = 6 * 10005;
long long k[M];
long long dp[N];
vector<long long> graph[N];
vector<long long> ePaths;
void dfs(long long v, long long p) {
  dp[v] = 1;
  for (auto u : graph[v]) {
    if (u != p) {
      dfs(u, v);
      dp[v] += dp[u];
    }
  }
}
void dfs2(long long v, long long p) {
  for (auto u : graph[v]) {
    if (p == u) continue;
    ePaths.push_back((dp[1] - dp[u]) * dp[u]);
    dfs2(u, v);
  }
}
void prEpa() {
  cout << "\nepa: ";
  for (auto x : ePaths) {
    cout << x << " ";
  }
  cout << "\n";
}
void solve() {
  for (long long i = 0; i < N; ++i) {
    graph[i].clear();
    dp[i] = 0;
  }
  ePaths.clear();
  for (long long i = 0; i < M; ++i) {
    k[i] = 0;
  }
  long long n;
  cin >> n;
  for (long long i = 0; i < n - 1; ++i) {
    long long x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  long long m;
  cin >> m;
  for (long long i = 0; i < m; ++i) {
    cin >> k[i];
  }
  dfs(1, -1);
  dfs2(1, -1);
  sort(ePaths.begin(), ePaths.end());
  reverse(ePaths.begin(), ePaths.end());
  sort(k, k + m);
  reverse(k, k + m);
  long long res = 0;
  if ((long long)ePaths.size() >= m) {
    for (long long i = 0; i < (long long)ePaths.size(); ++i) {
      if (i < m) {
        res = (res + (k[i] * ePaths[i]) % MOD) % MOD;
      } else {
        res = (res + (ePaths[i]) % MOD) % MOD;
      }
    }
  } else {
    long long fEls = m - ePaths.size();
    long long fRes = 0;
    for (long long i = 0; i <= fEls; ++i) {
      fRes = (fRes * k[i]) % MOD;
    }
    res += (ePaths[0] * fRes) % MOD;
    long long j = 1;
    for (long long i = fEls + 1; i < m; ++i, ++j) {
      res = (res + (ePaths[j] * k[i]) % MOD) % MOD;
    }
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
