#include <bits/stdc++.h>
int min(int a, int b) { return a < b ? a : b; }
int main() {
  int i, j, a[109][109], n, m, ans = 0;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (i = n - 1; i >= 0; i--)
    for (j = m - 1; j >= 0; j--) {
      if (a[i][j] == 0) {
        if (i == n - 1 && j == m - 1)
          a[i][j] = 8000;
        else if (i == n - 1)
          a[i][j] = a[i][j + 1] - 1;
        else if (j == m - 1)
          a[i][j] = a[i + 1][j] - 1;
        else
          a[i][j] = min(a[i][j + 1], a[i + 1][j]) - 1;
      } else if (j != m - 1 && a[i][j] >= a[i][j + 1]) {
        printf("-1\n");
        return 0;
      } else if (i != n - 1 && a[i][j] >= a[i + 1][j]) {
        printf("-1\n");
        return 0;
      }
      ans += a[i][j];
    }
  printf("%d\n", ans);
}
