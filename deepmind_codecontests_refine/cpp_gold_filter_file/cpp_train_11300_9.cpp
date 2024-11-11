#include <bits/stdc++.h>
const int MAX = 1e5 + 10;
;
using namespace std;
vector<long long int> adj[MAX];
long long int dp[MAX];
long long int ans = INT_MIN;
void dfs(long long int src, long long int par) {
  dp[src] = 1;
  for (auto &child : adj[src]) {
    if (child != par) {
      dfs(child, src);
      ans = max(ans, dp[child] + dp[src]);
      dp[src] = max(dp[src], dp[child] + 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 0; i < m; ++i) {
    long long int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1);
  cout << ans - 1 << "\n";
  return 0;
}
