#include <bits/stdc++.h>
using namespace std;
int n, m, k, s, a[505050], d[505050][111];
vector<int> g[505050];
bool vis[505050];
queue<int> q;
int main() {
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= k; i++) {
    memset(vis, false, sizeof(vis));
    for (int j = 1; j <= n; j++) {
      if (a[j] == i) {
        d[j][i] = 0;
        q.push(j);
        vis[j] = true;
      }
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int j = 0; j < g[x].size(); j++) {
        int y = g[x][j];
        if (!vis[y]) {
          d[y][i] = d[x][i] + 1;
          vis[y] = true;
          q.push(y);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(d[i] + 1, d[i] + k + 1);
    int ans = 0;
    for (int j = 1; j <= s; j++) {
      ans += d[i][j];
    }
    cout << ans << ' ';
  }
  cout << endl;
  return 0;
}
