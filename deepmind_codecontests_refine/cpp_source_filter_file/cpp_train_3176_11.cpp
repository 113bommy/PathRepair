#include <bits/stdc++.h>
int main() {
  int n, t, i;
  scanf("%d %d", &n, &t);
  if (t != 10) {
    for (i = 1; i <= n; i++) printf("%d", t);
  } else {
    if (n == 1)
      printf("%d", -1);
    else {
      if (n % 2 == 0) {
        for (i = 1; i <= (n / 2); i++) printf("%d", t);
      } else {
        for (i = 1; i <= (n / 2); i++) printf("%d", t);
        printf("%d", 1);
      }
    }
  }
  return 0;
}
