#include <bits/stdc++.h>
int a[10005];
int main() {
  int i, j, k, n, a;
  scanf("%d%d", &n, &k);
  a = n / 2;
  if (a > k || (a == 0 && k != 0)) {
    printf("-1");
  } else if (a == k) {
    for (i = 1; i <= n; i++) {
      if (i == 1) {
        printf("%d", i);
      } else {
        printf(" %d", i);
      }
    }
  } else if (a < k) {
    int temp = k - a + 1;
    printf("%d %d", temp, temp * 2);
    for (i = temp * 2 + 1; i <= temp * 2 + n - 2; i++) {
      printf(" %d", i);
    }
  }
  printf("\n");
  return 0;
}
