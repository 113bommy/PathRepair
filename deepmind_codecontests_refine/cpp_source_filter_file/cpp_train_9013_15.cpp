#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > colors, g;
vector<bool> vis, cols;
vector<int> colmap;
int maxi;
void dfs(int v, int par) {
  for (int col : colors[v]) {
    if (colmap[col]) cols[colmap[col]] = true;
  }
  int it = 1;
  for (int col : colors[v]) {
    if (!colmap[col]) {
      while (cols[it]) ++it;
      colmap[col] = it++;
    }
  }
  for (int col : colors[v]) {
    if (colmap[col]) cols[colmap[col]] = false;
  }
  for (int x : g[v]) {
    if (!vis[x]) {
      vis[x] = true;
      dfs(x, v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  colors.resize(n);
  maxi = 0;
  for (int i = 0; i < n; ++i) {
    int si, col;
    cin >> si;
    maxi = max(si, maxi);
    while (si--) {
      cin >> col;
      colors[i].push_back(col);
    }
  }
  g.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vis.resize(n, 0);
  cols.resize(maxi + 1, 0);
  colmap.resize(m + 1, 0);
  vis[0] = true;
  dfs(0, 0);
  cout << maxi << endl;
  for (int i = 1; i < m + 1; ++i) {
    int out = colmap[i];
    if (!out) out++;
    cout << out << " ";
  }
  return 0;
}
