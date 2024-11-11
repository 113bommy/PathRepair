#include <bits/stdc++.h>
using namespace std;
const int maxN = 1 << 17;
int dp[maxN];
vector<int> g[maxN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  long long ans = -1ll;
  for (int v = 1; v <= n; v++) {
    dp[v] = 1;
    for (int c = 0; c < g[v].size(); c++) {
      int u = g[v][c];
      if (u < v) {
        dp[v] = max(dp[v], dp[u] + 1);
      }
    }
    ans = max(ans, dp[v] * (long long)g[v].size());
  }
  cout << ans << endl;
  return 0;
}
