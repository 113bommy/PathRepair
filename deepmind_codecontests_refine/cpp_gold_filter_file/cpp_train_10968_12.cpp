#include <bits/stdc++.h>
using namespace std;
int n, m, a[5050], b[5050], dis[5050];
vector<int> g[2][1010];
bool can_reach[2][1010];
void dfs(int x, int xh) {
  can_reach[xh][x] = true;
  for (int i = 0; i < g[xh][x].size(); i++) {
    int y = g[xh][x][i];
    if (!can_reach[xh][y]) {
      dfs(y, xh);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    g[0][a[i]].push_back(b[i]);
    g[1][b[i]].push_back(a[i]);
  }
  dfs(1, 0);
  dfs(n, 1);
  for (int i = 0; i < n; i++) {
    bool gx = false;
    for (int j = 0; j < m; j++) {
      if (can_reach[0][a[j]] && can_reach[1][b[j]]) {
        if (dis[a[j]] > dis[b[j]] - 1) {
          gx = true;
          dis[a[j]] = dis[b[j]] - 1;
        }
        if (dis[b[j]] > dis[a[j]] + 2) {
          gx = true;
          dis[b[j]] = dis[a[j]] + 2;
        }
      }
    }
    if (gx == true && i == n - 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < m; i++) {
    if (can_reach[0][a[i]] && can_reach[1][b[i]]) {
      cout << dis[b[i]] - dis[a[i]] << endl;
    } else {
      cout << 2 << endl;
    }
  }
  return 0;
}
