#include <bits/stdc++.h>
int main() {
  int n, t, i;
  scanf("%d", &n);
  t = n / 2;
  if (n == 3) {
    printf("1\n");
    printf("3\n");
  } else if (n % 2 == 1) {
    printf("%d\n", t + 1);
    for (i = 1; i <= t; i++) printf("2 ");
    printf("3\n");
  } else {
    printf("%d\n", t);
    for (i = 1; i < t; i++) printf("2 ");
    printf("2\n");
  }
  return 0;
}
