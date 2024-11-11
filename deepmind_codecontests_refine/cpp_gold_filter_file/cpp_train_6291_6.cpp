#include <bits/stdc++.h>
int main() {
  int i, j, k, a[500][500], n, b[1000] = {0};
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i][0]);
  for (i = 0; i < n; i++)
    for (j = 1; j < a[i][0] + 1; j++) scanf("%d", &a[i][j]);
  for (i = 0, k = 0; i < n; i++, k++)
    for (j = 1; j < a[i][0] + 1; j++) b[k] += 5 * a[i][j] + 15;
  for (i = 0, j = b[0]; i < n; i++)
    if (j > b[i]) j = b[i];
  printf("%d\n", j);
  return 0;
}
