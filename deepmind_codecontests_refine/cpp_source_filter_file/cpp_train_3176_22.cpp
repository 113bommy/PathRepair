#include <bits/stdc++.h>
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  if (t >= 2 && t <= 9) {
    for (int i = 1; i <= n; i++) {
      printf("%d", t);
    }
  } else if (t = 10 && n > 2) {
    if (n % 2 == 0) {
      for (int i = 1; i <= n / 2; i++) {
        printf("10");
      }
    } else {
      printf("1");
      for (int i = 1; i <= n - 1; i++) {
        printf("0");
      }
    }
  } else
    printf("-1");
  return 0;
}
