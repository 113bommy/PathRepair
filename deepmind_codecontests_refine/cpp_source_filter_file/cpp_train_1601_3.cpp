#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int INF = 0x7f7f7f7f;
const double eps = 1e-6;
int g[333][333];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> g[i][j];
  int k;
  cin >> k;
  while (k--) {
    int x, y, w;
    cin >> x >> y >> w;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        g[i][j] = g[j][i] = min(g[i][j], g[i][x] + w + g[y][j]);
        g[i][j] = g[j][i] = min(g[i][j], g[i][y] + w + g[x][j]);
        sum += g[i][j];
      }
    }
    cout << sum << ' ';
  }
  cout << endl;
  return 0;
}
