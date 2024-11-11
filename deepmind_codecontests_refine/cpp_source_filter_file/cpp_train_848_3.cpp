#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<bool> vis(3 * n + 1);
  vector<int> edges;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if (!vis[x] && !vis[y]) {
      vis[x] = 1;
      vis[y] = 1;
      edges.push_back(i);
    }
  }
  if (edges.size() >= n) {
    cout << "Matching\n";
    for (int i = 0; i < n; i++) {
      cout << edges[i] << ' ';
    }
    cout << '\n';
    return;
  }
  cout << "IndSet\n";
  for (int i = 1, ct = 0; ct < n; i++) {
    if (vis[i]) {
      cout << i << ' ';
      ct++;
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
