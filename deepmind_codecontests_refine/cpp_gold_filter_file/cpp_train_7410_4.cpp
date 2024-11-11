#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e5 + 7;
vector<vector<pair<int, int> > > g(N);
int col[N], far[N];
bool cyc;
void dfs(int u) {
  far[u] = 1;
  for (auto &i : g[u]) {
    int v = i.first, id = i.second;
    if (far[v] == 0) {
      dfs(v);
      col[id] = 1;
    } else if (far[v] == 2) {
      col[id] = 1;
    } else {
      col[id] = 2;
      cyc = true;
    }
  }
  far[u] = 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u - 1].push_back({v - 1, i});
  }
  for (int i = 0; i < n; ++i) {
    if (!far[i]) dfs(i);
  }
  cout << 1 + cyc << endl;
  for (int i = 0; i < m; ++i) cout << col[i] << ' ';
  return 0;
}
