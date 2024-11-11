#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e2 + 1;
int n, m, q, ans[MAX][MAX], t[MAX][MAX][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> q;
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++) {
      t[i][j][0] = i;
      t[i][j][1] = j;
    }
  while (q--) {
    int ty;
    cin >> ty;
    if (ty == 1) {
      int x;
      cin >> x;
      int x1 = t[x][1][0], y1 = t[x][1][1];
      for (int i = 1; i < m; i++) {
        t[x][i][0] = t[x][i + 1][0];
        t[x][i][1] = t[x][i + 1][1];
      }
      t[x][m][0] = x1;
      t[x][m][1] = y1;
    } else if (ty == 2) {
      int x;
      cin >> x;
      int x1 = t[1][x][0], y1 = t[1][x][1];
      for (int i = 1; i < n; i++) {
        t[i][x][0] = t[i + 1][x][0];
        t[i][x][1] = t[i + 1][x][1];
      }
      t[n][x][0] = x1;
      t[n][x][1] = y1;
    } else {
      int x, y, z;
      cin >> x >> y >> z;
      ans[t[x][y][0]][t[x][y][1]] = z;
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) cout << ans[i][j] << " ";
    cout << '\n';
  }
  return 0;
}
