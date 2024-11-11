#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[4000][4000];
vector<int> g[4000];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
    f[a][b] = f[b][a] = 1;
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      int sn = g[i][j];
      for (int k = 0; k < g[sn].size(); k++) {
        int th = g[sn][k];
        if (th != i && f[i][th]) {
          if (ans == -1) {
            ans = g[i].size() + g[sn].size() + g[th].size() - 3;
          } else {
            ans =
                min(ans, (int)(g[i].size() + g[sn].size() + g[th].size()) - 3);
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
