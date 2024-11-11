#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 50;
long long del = 1e9 + 7;
int mark[maxn];
vector<int> adj[maxn];
long long dp[maxn];
int p[maxn];
void dfs(int u) {
  mark[u] = 1;
  dp[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (mark[v] == 0) {
      dfs(v);
      dp[u] += dp[v];
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 2; i <= n; i++) {
      dp[i] = (dp[i] * (n - dp[i]));
    }
    sort(dp + 2, dp + n + 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> p[i];
    }
    sort(p, p + m);
    long long ans = 0;
    if (m > n - 1) {
      long long o = 1;
      int s = m - n + 2;
      for (int i = m - 1; i >= m - s; i--) {
        o = (o * p[i]) % del;
      }
      o = (o * dp[n]) % del;
      ans += o;
      s = m - s - 1;
      for (int i = n - 1; i >= 2; i--) {
        long long f = (dp[i] * p[s]) % del;
        ans = (ans + f) % del;
        s--;
      }
      cout << ans << endl;
    } else {
      int j = n;
      for (int i = m - 1; i >= 0; i--) {
        long long o = (dp[j] * p[i]) % del;
        ans = (ans + o) % del;
        j--;
      }
      for (int i = j; i >= 2; i--) {
        ans = (ans + dp[i]) % del;
      }
      cout << ans << endl;
    }
    for (int i = 1; i <= n; i++) {
      mark[i] = 0;
      adj[i].clear();
      dp[i] = 0;
    }
  }
}
