#include <bits/stdc++.h>
int m, n, a[105], a1, a2, flag = 1, k;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a1, &a2);
    for (int j = a1; j <= a2; j++) {
      a[j]++;
    }
  }
  for (k = 1; k <= n; k++) {
    if (a[k] == 0) {
      printf("%d %d", k, 0);
      break;
    } else if (a[k] > 1) {
      printf("%d %d", k, a[k]);
      break;
    }
  }
  if (k == n + 1) {
    printf("OK");
  }
  return 0;
}
