#include <bits/stdc++.h>
using namespace std;
int r, c, n, k, a[30][30], f[30][30], res;
int main() {
  cin >> r >> c >> n >> k;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    a[u][v] = 1;
  }
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++)
      f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
  for (int x = 1; x <= r; x++)
    for (int y = 1; y <= c; y++)
      for (int u = x + 1; u <= r; u++)
        for (int v = y + 1; v <= c; v++)
          if (f[u][v] - f[u][y - 1] - f[x - 1][v] + f[x - 1][y - 1] >= k) res++;
  cout << res;
}
