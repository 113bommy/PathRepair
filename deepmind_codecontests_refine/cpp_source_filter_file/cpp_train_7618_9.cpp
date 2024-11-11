#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m;
int res;
int g[N][N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> g[i][j];
      res += g[i][j];
    }
  bool flag = true;
  for (int i = n; i >= 1 && flag; i--)
    for (int j = m; j >= 1; j--)
      if (g[i][j] == 0) {
        g[i][j] = min(g[i + 1][j], g[i][j + 1]) - 1;
        res += g[i][j];
      } else if ((i < n && g[i][j] >= g[i + 1][j]) ||
                 (j < m - 1 && g[i][j] >= g[i][j + 1])) {
        flag = false;
        break;
      }
  if (flag)
    cout << res << endl;
  else
    cout << -1 << endl;
  return 0;
}
