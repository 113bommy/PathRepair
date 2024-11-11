#include <bits/stdc++.h>
using namespace std;
vector<long long> graph[300001];
long long A[300001], dp[300001][3];
long long cst = 0;
void dfs(long long u, long long pr) {
  for (long long v : graph[u]) {
    if (v != pr) {
      dfs(v, u);
      dp[u][0] = max(dp[u][0], dp[v][0]);
      dp[u][1] = max(dp[u][1], dp[v][1]);
    }
  }
  long long p = A[u] - dp[u][0] + dp[u][1];
  if (p < 0)
    dp[u][0] -= p;
  else
    dp[u][1] += p;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) cin >> A[i];
  dfs(1, -1);
  cout << dp[1][0] + dp[1][1] << endl;
}
