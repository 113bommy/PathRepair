#include <bits/stdc++.h>
using namespace std;
vector<int> adj[51];
bool vis[51];
int b[51];
long long p[51];
void dfs(int x, int y) {
  if (vis[x] != 0) {
    return;
  }
  vis[x] = 1;
  ++b[y];
  for (int i = 0; i < adj[x].size(); ++i) {
    dfs(adj[x][i], y);
  }
}
int main() {
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == 0) {
      dfs(i, i);
    }
  }
  p[0] = 1;
  for (int i = 1; i <= 50; i++) {
    p[i] = p[i - 1] * (long long)2;
  }
  long long c = 1;
  for (int i = 1; i <= 50; ++i) {
    if (b[i] > 0) {
      c *= p[b[i] - 1];
    }
  }
  cout << c << endl;
  return 0;
}
