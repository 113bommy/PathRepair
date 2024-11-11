#include <bits/stdc++.h>
using namespace std;
int ans, n, i, j, m, l, r, a[401][401], pr[401][401], f[401][401];
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (i = 1; i <= n; i++) {
    for (l = m; l; l--)
      for (r = l; r <= m; r++) {
        if (l == r)
          f[l][r] = max(f[l][r], pr[l][a[i][j]]);
        else {
          f[l][r] = max(f[l][r], max(f[l][r - 1], f[l + 1][r]));
          f[l][r] = max(f[l][r], max(pr[l][a[i][r]], pr[r][a[i][l]]));
          if (a[i][l] == a[i][r]) f[l][r] = i;
        }
        ans = max(ans, (r - l + 1) * (i - f[l][r]));
      }
    for (j = 1; j <= m; j++) pr[j][a[i][j]] = i;
  }
  printf("%d", ans);
}
