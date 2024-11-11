#include <bits/stdc++.h>
int row[1005], col[1005];
char field[1005][1005], buf[1005];
int main(void) {
  int i, j, m, n;
  long long total;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; ++i) {
    scanf("%s", buf);
    for (j = 0; j < m; ++j) {
      field[i][j] = buf[j];
      if (field[i][j] == '*') {
        row[i]++;
        col[j]++;
      }
    }
  }
  total = 0;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
      if (field[i][j] == '*') total += (row[i] - 1) * (col[j] - 1);
  printf("%lld\n", total);
  return 0;
}
