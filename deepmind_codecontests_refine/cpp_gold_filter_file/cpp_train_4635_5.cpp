#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const double Pi = acos(-1);
using namespace std;
int debug = 01;
int main() {
  int n, m;
  cin >> n >> m;
  string g[n];
  int x[n][m], y[n][m];
  for (int i = 0; i < n; i++) cin >> g[i];
  memset(x, 0, sizeof(x)), memset(y, 0, sizeof(y));
  for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++) {
      x[i][j] = x[i][j - 1];
      if (g[i][j] == '.' && g[i][j - 1] == '.') x[i][j]++;
    }
  for (int i = 0; i < m; i++)
    for (int j = 1; j < n; j++) {
      y[j][i] = y[j - 1][i];
      if (g[j][i] == '.' && g[j - 1][i] == '.') y[j][i]++;
    }
  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2, ans = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;
    for (int i = x1; i <= x2; i++) ans += (x[i][y2] - x[i][y1]);
    for (int i = y1; i <= y2; i++) ans += (y[x2][i] - y[x1][i]);
    cout << ans << "\n";
  }
}
