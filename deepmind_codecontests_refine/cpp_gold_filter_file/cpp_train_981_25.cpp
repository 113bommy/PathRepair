#include <bits/stdc++.h>
using namespace std;
const int M = 2000 + 4, Inf = 1e9 + 10;
int n, m, k;
char f[M][M];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> f[i][j];
  for (int i = 0; i < m; i++) {
    int ans = 0;
    for (int y = 2; y < n; y += 2)
      if (f[y][i] == 'U') ans++;
    for (int x = i, y = 0; x >= 0 && y < n; y++, x--)
      if (f[y][x] == 'R') ans++;
    for (int x = i, y = 0; x < m && y < n; y++, x++)
      if (f[y][x] == 'L') ans++;
    cout << ans << " ";
  }
  return 0;
}
