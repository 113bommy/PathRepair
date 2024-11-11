#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 998244353;
const long long maxn = 2e5 + 10, maxm = 260, mlg = (1 << 18) + 10;
long long t[maxn], h[maxn];
vector<long long> nei[maxn];
long long dp[2][maxn], in[maxn], out[maxn], ans, n, mark[maxn];
bool cmp(long long u, long long v) {
  return dp[0][u] - dp[1][u] > dp[0][v] - dp[1][v];
}
void dfs(long long u, long long p) {
  vector<long long> ve;
  long long sum = 0;
  mark[u] = 1;
  for (auto v : nei[u]) {
    if (!mark[v]) {
      dfs(v, u);
      ve.push_back(v);
      sum += dp[1][v];
    }
  }
  sort(ve.begin(), ve.end(), cmp);
  long long tmp = ve.size();
  if (p == u) {
    dp[0][u] = max(dp[0][u], min(in[u], (long long)out[u] + tmp) * t[u] + sum);
    for (int i = 0; i < ve.size(); i++) {
      sum += dp[0][ve[i]] - dp[1][ve[i]];
      dp[0][u] =
          max(dp[0][u],
              min(in[u] + i + 1, (long long)out[u] + tmp - i - 1) * t[u] + sum);
    }
  } else {
    dp[0][u] =
        max(dp[0][u], min(in[u], (long long)out[u] + 1 + tmp) * t[u] + sum);
    dp[1][u] =
        max(dp[1][u], min(in[u] + 1, (long long)out[u] + tmp) * t[u] + sum);
    for (int i = 0; i < ve.size(); i++) {
      sum += dp[0][ve[i]] - dp[1][ve[i]];
      dp[0][u] = max(
          dp[0][u],
          min(in[u] + i + 1, (long long)out[u] + 1 + tmp - i - 1) * t[u] + sum);
      dp[1][u] = max(
          dp[1][u],
          min(in[u] + i + 1 + 1, (long long)out[u] + tmp - i - 1) * t[u] + sum);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    ans += t[u] + t[v];
    if (h[u] != h[v]) {
      if (h[v] > h[u]) {
        in[v]++;
        out[u]++;
      } else {
        in[u]++;
        out[v]++;
      }
    } else {
      nei[u].push_back(v);
      nei[v].push_back(u);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) {
      dfs(i, i);
      ans -= dp[0][i];
    }
  }
  cout << ans << endl;
}
