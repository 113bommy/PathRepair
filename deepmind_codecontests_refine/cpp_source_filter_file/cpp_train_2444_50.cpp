#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[1000];
vector<bool> vis(1000, false);
char a[100][100];
bool f = false;
void dfs(long long int node, long long int len = 0, long long int par = -1) {
  vis[node] = true;
  for (auto child : adj[node]) {
    if (!vis[child]) {
      dfs(child, len + 1, node);
    } else {
      if (len >= 3 && par != child) f = true;
    }
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 0; i < n + 2; i++) {
    for (long long int j = 0; j < m + 2; j++) a[i][j] = '1';
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  long long int v[n + 1][m + 1];
  long long int c = 0;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      v[i][j] = ++c;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      if (a[i][j] == a[i - 1][j]) {
        adj[v[i][j]].push_back(v[i - 1][j]);
      }
      if (a[i][j] == a[i][j + 1]) {
        adj[v[i][j]].push_back(v[i][j + 1]);
      }
      if (a[i][j] == a[i + 1][j]) {
        adj[v[i][j]].push_back(v[i + 1][j]);
      }
      if (a[i][j] == a[i][j - 1]) {
        adj[v[i][j]].push_back(v[i][j - 1]);
      }
    }
  }
  for (long long int i = 1; i <= n * m; i++) {
    if (!vis[i]) dfs(i);
  }
  if (f)
    cout << "YES";
  else
    cout << "NO";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int test_cases = 1;
  while (test_cases--) {
    solve();
  }
  return 0;
}
