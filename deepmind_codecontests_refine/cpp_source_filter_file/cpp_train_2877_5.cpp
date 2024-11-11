#include <bits/stdc++.h>
using namespace std;
const int num = 200001;
vector<int> adj[num];
int a[num], p[num], c[num], vis[num], steps;
void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int cur = adj[u][i];
    if (!vis[cur]) {
      if (p[cur] != c[u]) steps++, c[cur] = p[cur];
      dfs(cur);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) cin >> a[i];
  for (int i = 1; i < n + 1; i++) cin >> p[i];
  for (int i = 1; i < n; i++)
    adj[i + 1].push_back(a[i]), adj[a[i]].push_back(i + 1);
  c[1] = p[1];
  steps = 1;
  dfs(1);
  cout << steps << "\n";
  return 0;
}
