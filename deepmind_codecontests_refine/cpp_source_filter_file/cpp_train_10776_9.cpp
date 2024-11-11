#include <bits/stdc++.h>
using namespace std;
int const MAX = 500 + 10;
vector<int> adj[MAX];
void solve() {
  int c[MAX][MAX], deg[MAX], color[MAX];
  memset(deg, 0, sizeof(deg));
  memset(c, 0, sizeof(c));
  memset(color, 0, sizeof(color));
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    c[u][v] = c[v][u] = 1;
    deg[u]++, deg[v]++;
    if (deg[u] == n - 1) color[u] = 2;
    if (deg[v] == n - 1) color[v] = 2;
  }
  char letter[4] = {'x', 'a', 'b', 'c'};
  bool ans = true;
  for (int i = 1; i <= n; i++) {
    if (color[i] == 0) {
      color[i] = 1;
      for (int j = 1; j <= n; j++) {
        if (c[i][j] == 1 && color[j] == 0) color[j] = 1;
      }
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (color[i] == 0) color[i] = 3;
  }
  int newm = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (abs(color[i] - color[j]) <= 1) newm++;
      if (c[i][j] == 0 && color[i] == color[j] && i != j) {
        ans = false;
        break;
      }
    }
  }
  if (ans && newm == m) {
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) cout << letter[color[i]];
    cout << "\n";
  } else
    cout << "No\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
