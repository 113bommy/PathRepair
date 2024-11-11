#include <bits/stdc++.h>
using namespace std;
int n, m, p, f[55][55][55][105], C[105][105], ans;
void inc(int x, int &y) {
  x += y;
  if (x >= 1000000007) x -= 1000000007;
}
int main() {
  int i, j, k, l, x, y;
  cin >> n >> m >> p;
  C[0][0] = 1, n >>= 1;
  for (i = 1; i < 105; i++) {
    C[i][0] = C[i][i] = 1;
    for (j = 1; j < i; j++) C[i][j] = min(C[i - 1][j - 1] + C[i - 1][j], 100);
  }
  for (i = 1; i <= n; i++) f[1][i][i][1] = 1;
  for (i = 1; i <= n && i <= m; i++)
    for (j = 1; j <= n; j++)
      for (k = 1; k <= n; k++)
        for (l = 1; l <= p; l++) {
          if (!f[i][j][k][l]) continue;
          ans = (ans + 1LL * f[i][j][k][l] * (m - i)) % 1000000007;
          for (x = 1; x <= n - k; x++) {
            y = l * C[j + x - 1][j - 1];
            if (y > p) continue;
            inc(f[i + 1][x][k + x][y], f[i][j][k][l]);
          }
        }
  cout << ans;
  return 0;
}
