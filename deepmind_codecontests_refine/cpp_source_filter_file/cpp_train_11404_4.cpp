#include <bits/stdc++.h>
double a[5][5];
int main() {
  int n, t;
  while (~scanf("%d %d", &n, &t)) {
    int ans = 0;
    memset(a, 0, sizeof(a));
    a[1][1] = t;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= i; j++)
        if (a[i][j] >= 1) {
          ans++;
          a[i + 1][j] += (a[i][j] - 1) / 2.0;
          a[i + 1][j + 1] += (a[i][j] - 1) / 2.0;
        }
    printf("%d\n", ans);
  }
  return 0;
}
