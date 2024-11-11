#include <bits/stdc++.h>
int main() {
  int n, i, j, l, a[1000], k = 1, step[100], stair = 1;
  scanf("%d", &n);
  for (i = 1; i < 100; i++) step[i] = 0;
  step[1] = 1;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (j = 2; j <= n; j++) {
    if (a[j] == 1) {
      stair++;
      k++;
    }
    step[k]++;
  }
  printf("%d\n", stair);
  for (l = 1; l <= k; l++) printf("%d ", step[l]);
  return 0;
}
