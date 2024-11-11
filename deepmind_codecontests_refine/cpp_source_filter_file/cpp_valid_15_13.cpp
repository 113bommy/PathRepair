#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long add(long long a, long long b) { return (a + b) % mod; }
long long sub(long long a, long long b) { return ((a - b) % mod + mod) % mod; }
long long mul(long long a, long long b) { return (a * b) % mod; }
long long power(long long a, long long b) {
  if (b == 0) return 1LL;
  long long tmp = power(a, b / 2);
  tmp = mul(tmp, tmp);
  if (b & 1) tmp = mul(tmp, a);
  return tmp;
}
const int maxn = 105;
long long dp[maxn][maxn], fact[maxn], ifact[maxn], ans;
vector<int> adjlist[maxn];
int n, k, depth[maxn], groupsize[maxn][maxn];
void precalc() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = mul(i, fact[i - 1]);
    ifact[i] = power(fact[i], mod - 2);
  }
}
long long ncr(long long n, long long r) {
  if (r > n) return 0LL;
  return mul(fact[n], mul(ifact[n - r], ifact[r]));
}
void pivot(int p) {
  if (adjlist[p].size() < k) return;
  memset(depth, 0, sizeof(depth));
  memset(dp, 0, sizeof(dp));
  memset(groupsize, 0, sizeof(groupsize));
  depth[p] = 1;
  queue<pair<int, int>> q;
  for (auto u : adjlist[p]) {
    q.push({u, u});
    depth[u] = 2;
  }
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    groupsize[cur.second][depth[cur.first]]++;
    for (auto u : adjlist[cur.first]) {
      if (depth[u] != 0) continue;
      depth[u] = depth[cur.first] + 1;
      q.push({u, cur.second});
    }
  }
  for (int i = 0; i <= adjlist[p].size(); i++) {
    dp[i][0] = 1;
  }
  for (int d = 2; d < maxn; d++) {
    int tot = 0;
    for (auto u : adjlist[p]) {
      tot += min(groupsize[u][d], 1);
    }
    if (tot < k) break;
    for (int i = 0; i < adjlist[p].size(); i++) {
      for (int j = 1; j <= min(i + 1, k); j++) {
        dp[i + 1][j] =
            add(dp[i][j], mul(dp[i][j - 1], groupsize[adjlist[p][i]][d]));
      }
    }
  }
  ans = add(ans, dp[adjlist[p].size()][k]);
}
void solve() {
  ans = 0;
  memset(dp, 0, sizeof(dp));
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    adjlist[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }
  if (k == 2) {
    cout << ncr(n, 2);
    return;
  }
  for (int i = 1; i <= n; i++) {
    pivot(i);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  precalc();
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
