#include <bits/stdc++.h>
int main(void) {
  int a, b, n;
  scanf("%d%d", &a, &b);
  n = a + b + 1;
  if (a == 0) {
    for (int i = n; i >= 1; i--) {
      printf("%d", i);
    }
  } else if (b == 0) {
    for (int i = 1; i <= n; i++) {
      printf("%d", i);
    }
  } else {
    for (int i = n - a; i <= n; i++) {
      printf("%d", i);
    }
    for (int i = b; i >= 1; i--) {
      printf("%d", i);
    }
  }
  printf("\n");
  return 0;
}
