#include <bits/stdc++.h>
int main() {
  int a, b, n, i;
  scanf("%d%d", &a, &b);
  n = a + b + 1;
  if (a != 0) {
    for (i = 1; i <= a; i++) {
      printf("%d\n", i);
    }
  }
  printf("%d\n", n);
  if (b != 0) {
    for (i = 0; i < b; i++) {
      printf("%d\n", n - i - 1);
    }
  }
  return 0;
}
