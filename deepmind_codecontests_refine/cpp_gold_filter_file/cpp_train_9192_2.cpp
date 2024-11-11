#include <bits/stdc++.h>
using namespace std;
int n, mx, currmax;
vector<int> adj[201];
int dfs(int source, int par) {
  int max1 = 0, max2 = 0, sum = 0;
  for (auto nx : adj[source]) {
    if (nx == par) continue;
    sum = max(dfs(nx, source), sum);
    if (currmax > max1) {
      max2 = max1;
      max1 = currmax;
    } else
      max2 = max(max2, currmax);
  }
  currmax = max1 + 1;
  sum = max(max1 + max2, sum);
  return sum;
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int v, u;
    cin >> v >> u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  int maxn = 0;
  for (int i = 1; i < n + 1; i++) {
    for (auto j : adj[i]) {
      int x = dfs(i, j);
      int y = dfs(j, i);
      maxn = max(maxn, x * y);
    }
  }
  cout << maxn << endl;
  return 0;
}
