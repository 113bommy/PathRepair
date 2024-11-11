#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int b[105][105];
int c[105][105];
bool vis[105];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    string str;
    cin >> str;
    for (int j = 1; j <= m; ++j) cin >> a[i][j] >> b[i][j] >> c[i][j];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      memset(vis, 0, sizeof(vis));
      int le = k, sum = 0;
      while (le) {
        int ma = 0, id;
        for (int t = 1; t <= m; ++t) {
          if (!vis[t]) {
            if (ma < b[j][t] - a[i][t]) {
              ma = b[j][t] - a[i][t];
              id = t;
            }
          }
        }
        if (!ma) break;
        vis[id] = 1;
        sum += (b[j][id] - a[i][id]) * min(le, c[i][id]);
        le -= min(le, c[i][id]);
      }
      ans = max(sum, ans);
    }
  }
  cout << ans << endl;
  return 0;
}
