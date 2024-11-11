#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
int N;
long long dp[MN][2], good[MN];
vector<long long> pref[MN], suf[MN];
vector<int> g[MN];
void solve(int u) {
  good[u] = 1;
  if (g[u].empty()) {
    dp[u][0] = 1;
    return;
  }
  long long p2 = 1;
  pref[u].push_back(1);
  for (int v : g[u]) {
    solve(v);
    pref[u].push_back(pref[u].back() * good[v] % 998244353);
  }
  suf[u].push_back(1);
  for (int i = (int)g[u].size() - 1; i >= 0; i--)
    suf[u].push_back(suf[u].back() * good[g[u][i]] % 998244353);
  reverse(suf[u].begin(), suf[u].end());
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    good[u] = good[u] * good[v] % 998244353;
    long long t = pref[u][i] * suf[u][i + 1] % 998244353 *
                  (dp[v][0] + dp[v][1]) % 998244353;
    dp[u][1] = (dp[u][1] + t) % 998244353;
    long long val = dp[u][0] * (dp[v][0] + dp[v][1]) % 998244353;
    val = (val + dp[u][0] * dp[v][0]) % 998244353;
    val = (val + p2 * (dp[v][0] + dp[v][1])) % 998244353;
    dp[u][0] = val;
    p2 = p2 * good[v] % 998244353;
  }
  dp[u][0] = (dp[u][0] - dp[u][1] + 998244353) % 998244353;
  good[u] = (good[u] + dp[u][0]) % 998244353;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 2; i <= N; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  solve(1);
  cout << good[1] << '\n';
}
