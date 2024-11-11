#include <bits/stdc++.h>
int main() {
  int n, i, j, k, l, m, o, p;
  scanf("%d", &n);
  for (i = 0; i <= n / 2; i++) {
    for (j = 1; j <= n / 2 - i; j++) {
      printf("#");
    }
    for (k = 1; k <= i + 1; k++) {
      printf("D");
    }
    for (m = 0; m < i; m++) {
      printf("D");
    }
    for (l = 0; l < n / 2 - i; l++) {
      printf("#");
    }
    printf("\n");
  }
  for (i = 0; i < n / 2; i++) {
    for (j = 0; j <= i; j++) {
      printf("#");
    }
    for (k = 1; k <= n / 2 - i; k++) {
      printf("D");
    }
    for (m = i; m < n / 2 - 1; m++) {
      printf("D");
    }
    for (l = 0; l <= i; l++) {
      printf("#");
    }
    printf("\n");
  }
}
