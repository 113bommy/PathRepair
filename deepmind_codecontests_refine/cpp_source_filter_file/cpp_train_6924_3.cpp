#include <bits/stdc++.h>
using namespace std;
long long dp[100010] = {0}, deg[100010] = {0};
int main() {
  long long n, m, maxm = 0, i;
  vector<long long> adj[100010];
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  for (i = 1; i <= n; i++) dp[i] = 1;
  for (i = 1; i <= n; i++) {
    long long sz = adj[i].size();
    for (int j = 0; j < sz; j++) {
      if (adj[i][j] < i && dp[i] > 1 + dp[adj[i][j]]) dp[i] = 1 + dp[adj[i][j]];
    }
  }
  for (i = 1; i <= n; i++) {
    maxm = (maxm > deg[i] * dp[i] ? maxm : deg[i] * dp[i]);
  }
  cout << maxm;
  return 0;
}
