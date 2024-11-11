#include <bits/stdc++.h>
using namespace std;
inline int qpow(int b, int e, int m = 998244353) {
  int a = 1;
  for (; e; e >>= 1, b = (long long)b * b % m)
    if (e & 1) a = (long long)a * b % m;
  return a;
}
int vis[1001];
int cc[1001];
void dfs(int u, vector<vector<int>> &adj) {
  vis[u] = 1;
  cc[u] = 1;
  for (int j = 0; j < adj[u].size(); j++) {
    int v = adj[u][j];
    if (vis[v] == 0) {
      dfs(v, adj);
    }
  }
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(vis, 0, sizeof vis);
  int ans = 0;
  int m;
  cin >> m;
  vector<vector<bool>> dislike(n + 1, vector<bool>(n + 1));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    dislike[u][v] = 1;
    dislike[v][u] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      memset(cc, 0, sizeof cc);
      dfs(i, adj);
      int cnt = 0;
      int test = 0;
      for (int j = 1; j <= n; j++) {
        if (cc[j] == 1) {
          for (int k = 1; k <= n; k++) {
            if (dislike[j][k] && cc[k]) {
              test = 1;
              goto out;
            }
          }
          cnt++;
        }
      }
      int c;
    out:
      if (test == 0) {
        ans = max(cnt, ans);
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
  return 0;
}
