#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> g[N];
int sz[N], l[N], r[N];
int dfs(int node, int anc, int x) {
  for (int to : g[node]) {
    if (to != anc) {
      x--;
    }
  }
  l[node] = x;
  x--;
  int z = x + 1;
  for (int to : g[node]) {
    if (to != anc) {
      z++;
      r[to] = z;
      int y = dfs(to, node, x);
      x = y - 1;
    }
  }
  return l[node];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0, -1, 2 * n - 1);
  r[0] = 2 * n;
  for (int i = 0; i < n; i++) {
    cout << l[i] << " " << r[i] << "\n";
  }
  return 0;
}
