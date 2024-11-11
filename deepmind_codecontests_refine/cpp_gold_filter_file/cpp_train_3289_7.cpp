#include <bits/stdc++.h>
using namespace std;
int n, m, khi = 1;
const int maxn = 3e5 + 10;
vector<int> s[maxn], adj[maxn];
bool mark[maxn];
int color[maxn];
void dfs(int v, int ham) {
  khi = max(khi, (int)s[v].size());
  int ng = 1;
  for (int u : s[v]) {
    mark[color[u]] = true;
  }
  for (int u : s[v]) {
    if (color[u]) {
      continue;
    }
    while (mark[ng]) {
      ng++;
    }
    color[u] = ng;
    ng++;
  }
  for (int u : s[v]) {
    mark[color[u]] = false;
  }
  for (int u : adj[v]) {
    if (u != ham) {
      dfs(u, v);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    while (b--) {
      int x;
      cin >> x;
      s[i].push_back(x);
    }
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  cout << khi << '\n';
  for (int i = 1; i <= m; i++) {
    if (!color[i]) {
      color[i] = 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << color[i] << " ";
  }
}
