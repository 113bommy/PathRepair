#include <bits/stdc++.h>
using namespace std;
vector<int> order, all[100001], g[100001];
int n, m, x, y, ans, color[100001], i;
bool cycle, u[100001];
void dfs1(int v) {
  u[v] = true;
  order.push_back(v);
  for (int j = 0; j < all[v].size(); j++) {
    int to = all[v][j];
    if (!u[to]) dfs1(to);
  }
}
void dfscolor(int v) {
  color[v] = 1;
  for (int j = 0; j < g[v].size(); j++) {
    int to = g[v][j];
    if (color[to] == 0)
      dfscolor(to);
    else if (color[to] == 1)
      cycle = 0;
  }
  color[v] = 2;
}
int main() {
  srand(time(NULL));
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    all[x].push_back(y);
    all[y].push_back(x);
    g[x].push_back(y);
  }
  for (i = 1; i <= n; i++)
    if (!u[i]) {
      order.clear();
      dfs1(i);
      cycle = 1;
      for (int j = 0; j < order.size(); ++j)
        if (color[order[j]] == 0) dfscolor(order[j]);
      ans += order.size() - cycle;
    }
  cout << ans;
}
