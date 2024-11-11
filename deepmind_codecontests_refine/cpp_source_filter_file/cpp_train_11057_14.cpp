#include <bits/stdc++.h>
using namespace std;
long long G, B;
vector<pair<int, int>> *adj;
int k;
int dfs(int v, int par = 0) {
  int nodesCount = 0;
  for (auto u : adj[v]) {
    if (u.first != par) {
      int n = dfs(u.first, v);
      nodesCount += n;
      G += (n % 2) * u.second;
      B += min(n, 2 * k - n) * u.second;
    }
  }
  return ++nodesCount;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> k;
    adj = new vector<pair<int, int>>[2 * k + 1];
    for (int i = 1; i < 2 * k; i++) {
      int a, b, t;
      cin >> a >> b >> t;
      adj[a].push_back({b, t});
      adj[b].push_back({a, t});
    }
    G = B = 0;
    dfs(1);
    cout << G << " " << B << endl;
  }
  return 0;
}
