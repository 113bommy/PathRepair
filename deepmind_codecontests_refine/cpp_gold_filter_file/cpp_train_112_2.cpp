#include <bits/stdc++.h>
using namespace std;
long long n, p, dp[1000005], deep[1000005], leaf[1000005], k;
vector<long long> a[1000005];
void dfs(long long u) {
  if (a[u].size() == 0) {
    deep[u] = 0;
    leaf[u] = 1;
    dp[u] = 1;
    return;
  }
  deep[u] = 1e9;
  for (long long j = (0); j <= (a[u].size() - 1); ++j) {
    long long v = a[u][j];
    dfs(v);
    if (deep[v] < k) leaf[u] += leaf[v];
    deep[u] = min(deep[u], deep[v] + 1);
  }
  for (long long j = (0); j <= (a[u].size() - 1); ++j) {
    long long v = a[u][j], tmp = dp[v];
    if (deep[v] < k) tmp -= leaf[v];
    dp[u] = max(dp[u], tmp + leaf[u]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = (2); i <= (n); ++i) {
    cin >> p;
    a[p].push_back(i);
  }
  dfs(1);
  cout << dp[1];
}
