#include <bits/stdc++.h>
int main() {
  int n, t, i;
  scanf("%d %d", &n, &t);
  if (n == 1) {
    if (t < 10) {
      printf("%d", t);
    } else
      printf("-1");
  } else if (n >= 2 && t < 10) {
    for (i = 1; i <= n; i++) {
      printf("%d", t);
    }
  } else {
    for (i = 1; i <= (n - 1); i++) {
      printf("%d", t / 10);
    }
    printf("0");
  }
}
