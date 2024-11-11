#include <bits/stdc++.h>
using namespace std;
int n, q, c;
int ans[105][105][15];
int x, y, s, xx, yy, t;
int main() {
  cin >> n >> q >> c;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> s;
    for (int j = 0; j <= c; j++) {
      ans[x][y][j] = (s + j) % (c + 1);
    }
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      for (int k = 0; k <= c; k++) {
        ans[i][j][k] = ans[i][j][k] + ans[i - 1][j][k] + ans[i][j - 1][k] -
                       ans[i - 1][j - 1][k];
      }
    }
  }
  while (q--) {
    cin >> t >> x >> y >> xx >> yy;
    t %= c + 1;
    cout << ans[xx][yy][t] + ans[x - 1][y - 1][t] - ans[x - 1][yy][t] -
                ans[xx][y - 1][t]
         << endl;
  }
}
