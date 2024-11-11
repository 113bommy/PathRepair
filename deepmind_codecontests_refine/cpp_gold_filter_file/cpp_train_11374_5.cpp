#include <bits/stdc++.h>
using namespace std;
const int maxn = 30 + 5;
int T, n, m;
int a[maxn][maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    int k = (n + m - 1) / 2, ans = 0, c1, c2;
    if (n < m) {
      for (int i = 1; i <= k; i++) {
        c1 = c2 = 0;
        for (int j = 1; j <= i && j <= n; j++) {
          int tmp = a[j][i - j + 1] + a[n - j + 1][m - (i - j + 1) + 1];
          c1 += tmp;
          c2 += 2 - tmp;
        }
        ans += min(c1, c2);
      }
    } else {
      for (int i = 1; i <= k; i++) {
        c1 = c2 = 0;
        for (int j = 1; j <= i && j <= m; j++) {
          int tmp = a[i - j + 1][j] + a[n - (i - j + 1) + 1][m - j + 1];
          c1 += tmp;
          c2 += 2 - tmp;
        }
        ans += min(c1, c2);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
