#include <bits/stdc++.h>
int main() {
  int n, **p, i, j;
  long long int t, max1 = 0, max2 = 0, s1[5000] = {0}, s2[5000] = {0};
  scanf("%d", &n);
  p = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) p[i] = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      scanf("%d", &p[i][j]);
      s1[i + j] += p[i][j];
      s2[i - j + n] += p[i][j];
    }
  int x1 = 0, y1 = 0, x2 = 0, y2 = 1;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      t = s1[i + j] + s2[i - j + n] - p[i][j];
      if ((i + j) % 2 == 0 && t > max1) {
        x1 = i;
        y1 = j;
        max1 = t;
      }
      if ((i + j) % 2 == 1 && t > max2) {
        x2 = i;
        y2 = j;
        max2 = t;
      }
    }
  printf("%I64d\n", max1 + max2);
  printf("%d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
  return 0;
}
