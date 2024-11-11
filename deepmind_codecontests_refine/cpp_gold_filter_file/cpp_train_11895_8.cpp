#include <bits/stdc++.h>
using namespace std;
const int N = 150;
int n, m, al[N][N], ar[N][N], f[N][N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, t, x, y; i <= n; i++) {
    scanf("%d", &t);
    while (t--) {
      scanf("%d%d", &x, &y);
      for (int j = x; j <= y; j++) al[i][j] = x, ar[i][j] = y;
    }
  }
  for (int l = m; l; l--)
    for (int r = l; r <= m; r++)
      for (int k = l; k <= r; k++) {
        int x = 0;
        for (int i = 1; i <= n; i++)
          if (l <= al[i][k] && ar[i][k] <= r) x++;
        f[l][r] = max(f[l][r], f[l][k - 1] + f[k + 1][r] + x * x);
      }
  printf("%d", f[1][m]);
}
