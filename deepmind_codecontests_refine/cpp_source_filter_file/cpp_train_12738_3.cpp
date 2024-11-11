#include <bits/stdc++.h>
int main() {
  int n, a[102], i;
  scanf("%d", &n);
  if (n == 1) {
    printf("-1\n");
  } else {
    for (i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        a[i] = i - 1;
      } else if (i % 2 != 0) {
        a[i] = i + 1;
      }
    }
    for (i = 1; i <= n; i++) {
      printf("%d ", a[i]);
    }
  }
  return 0;
}
