#include <bits/stdc++.h>
using namespace std;
const int N = 333;
int n, d[N][N], k;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> d[i][j];
  cin >> k;
  for (int t = 1; t <= k; t++) {
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][x] + d[y][j] + z);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][y] + d[x][j] + z);
    long long res = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) res += d[i][j];
    cout << res << " ";
  }
  return 0;
}
