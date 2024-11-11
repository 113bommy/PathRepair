#include <bits/stdc++.h>
using namespace std;
vector<int> g[100010];
int comp_v, comp_e, cnt, v[100010];
void dfs(int i, int p) {
  v[i] = cnt;
  comp_v++;
  comp_e += g[i].size();
  for (int j(0); j < g[i].size(); ++j)
    if (!v[i]) dfs(g[i][j], i);
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, x, y, ans(0);
  cin >> n >> m;
  for (int i(0); i < m; ++i) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i(1); i <= n; ++i)
    if (!v[i]) {
      cnt++;
      comp_e = comp_v = 0;
      dfs(i, -1);
      if (comp_v * 2 - 2 == comp_e) ans++;
    }
  cout << ans;
}
