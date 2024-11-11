#include <bits/stdc++.h>
int main() {
  int n, k = 5, i, x[100] = {}, gs = 0, y[100];
  scanf("%d", &n);
  for (i = 1; i <= 100000; i = i * 5 + 1, k *= 5) {
    if (i > n) break;
    x[gs] = i;
    y[gs++] = k;
  }
  int ans = 0, remain = n, j;
  for (i = gs - 1; i >= 0; i--) {
    for (j = 0; j <= 4; j++)
      if (x[i] * j <= remain && x[i] * (j + 1) > remain) break;
    if (j > 4) break;
    ans += y[i] * j;
    remain -= x[i] * j;
  }
  if (remain != 0)
    printf("0\n");
  else
    printf("5\n%d %d %d %d %d\n", ans, ans + 1, ans + 2, ans + 3, ans + 4);
  return 0;
}
