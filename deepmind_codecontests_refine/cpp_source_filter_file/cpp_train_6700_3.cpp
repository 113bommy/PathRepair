#include <bits/stdc++.h>
int main() {
  static int cc[10000], dd[10000];
  int n, m, h, j, d, ans;
  scanf("%d%d", &n, &m);
  ans = n * m;
  while (n--) {
    static char aa[10000 + 1];
    scanf("%s", aa);
    for (j = 0; j < m; j++) dd[j] = m;
    for (j = 0; j < m; j++)
      if (aa[j] == '1') {
        dd[j] = 0;
        for (d = 1; d < n && aa[h = (j - d + m) % m] == '0'; d++)
          if (dd[h] > d) dd[h] = d;
        for (d = 1; d < m && aa[h = (j + d) % m] == '0'; d++)
          if (dd[h] > d) dd[h] = d;
      }
    for (j = 0; j < m; j++) {
      if (dd[j] == m) {
        printf("-1\n");
        return 0;
      }
      cc[j] += dd[j];
    }
  }
  for (j = 0; j < m; j++)
    if (ans > cc[j]) ans = cc[j];
  printf("%d\n", ans);
  return 0;
}
