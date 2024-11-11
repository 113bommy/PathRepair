#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const long long mod = 1e9 + 7;
void speed() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n, k, used[maxn];
long long dp[maxn][maxn];
vector<int> g[maxn];
void bfs(int v) {
  queue<int> q;
  for (int i = 1; i <= n; i++) used[i] = -1;
  used[v] = 0;
  q.push(v);
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); i++) {
      int u = g[v][i];
      if (used[u] == -1) {
        used[u] = used[v] + 1;
        q.push(u);
      }
    }
  }
}
long long dfs(int v, int par, int dis) {
  if (used[v] == dis) return 1;
  long long sum = 0;
  for (int j = 0; j < g[v].size(); j++) {
    int u = g[v][j];
    if (u == par) continue;
    sum = sum + dfs(u, v, dis);
  }
  return sum;
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  if (k > 2) {
    long long ans = 0;
    for (int dis = 2; dis <= n; dis += 2) {
      for (int i = 1; i <= n; i++) {
        bfs(i);
        dp[0][0] = 1;
        int id = 1;
        for (int j = 0; j < g[i].size(); j++) {
          long long sum = dfs(g[i][j], i, dis / 2);
          dp[id][0] = 1;
          for (int p = 1; p <= k; p++)
            dp[id][p] = (dp[id - 1][p] + dp[id - 1][p - 1] * sum) % mod;
          id++;
        }
        ans = ans + dp[id - 1][k];
      }
    }
    cout << ans << '\n';
  } else {
    long long ans = 0;
    for (int dis = 1; dis <= n; dis++) {
      for (int i = 1; i <= n; i++) {
        bfs(i);
        for (int j = 1; j <= n; j++)
          if (used[j] == dis) ans++;
      }
    }
    cout << ans / 2 << '\n';
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
