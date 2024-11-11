#include <bits/stdc++.h>
using namespace std;
long long int n, k;
vector<vector<long long int> > adjList(201);
vector<long long int> vals(201);
bool vis[201][201];
long long int dp[201][201] = {0};
void dfs(long long int cur, long long int P) {
  for (long long int child : adjList[cur])
    if (child != P) dfs(child, cur);
  for (long long int child : adjList[cur]) {
    if (child == P) continue;
    dp[cur][0] += dp[child][k - 1];
  }
  dp[cur][0] += vals[cur];
  for (long long int i = 1; i <= k - 1; i++) {
    long long int mn = INT_MIN;
    long long int tot = 0;
    for (long long int child : adjList[cur]) {
      if (child == P) continue;
      tot += dp[child][max(k - i - 1, i - 1)];
      mn = max(mn, dp[child][i - 1] - dp[child][max(k - i - 1, i - 1)]);
    }
    dp[cur][i] = tot + mn;
  }
  for (long long int i = (long long int)k - 1; i >= 1; i--) {
    dp[cur][i - 1] = max(dp[cur][i - 1], dp[cur][i]);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  k++;
  for (long long int i = 0; i < (long long int)(n); i++) {
    cin >> vals[i];
  }
  for (long long int i = 0; i < (long long int)(n - 1); i++) {
    long long int a, b;
    cin >> a >> b;
    a--;
    b--;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  dfs(0, -1);
  cout << dp[0][0] << endl;
}
