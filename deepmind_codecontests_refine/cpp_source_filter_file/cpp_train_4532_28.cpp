#include <bits/stdc++.h>
using namespace std;
int n, m, nr, k, i, j, l, c, a[11][11], s[11][11], cnt, v, w, sol;
int main() {
  cin >> n >> m >> nr >> k;
  for (i = 1; i <= nr; i++) {
    cin >> l >> c;
    a[l][c] = 1;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      for (v = 1; v <= n; v++)
        for (w = 1; w <= m; w++)
          if (s[v][w] - s[i - 1][w] - s[v][j - 1] + s[i - 1][j - 1] >= k) sol++;
  cout << sol;
}
