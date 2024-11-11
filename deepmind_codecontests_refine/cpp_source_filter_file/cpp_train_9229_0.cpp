#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j;
  scanf("%d%d", &n, &k);
  printf("YES\n");
  for (i = 1; i <= n; i++) {
    printf(".");
  }
  printf("\n");
  if (k & 1) {
    if (k <= n - 2) {
      int c = (n - k) / 2;
      for (i = 1; i <= c; i++) {
        printf(".");
      }
      for (i = 1; i <= k; i++) {
        printf("#");
      }
      for (i = 1; i <= c; i++) {
        printf(".");
      }
      printf("\n");
      for (i = 1; i <= n; i++) {
        printf(".");
      }
      printf("\n");
    } else {
      printf(".");
      for (i = 2; i < n; i++) {
        printf("#");
      }
      printf(".\n.");
      int kk = (k - n + 2) / 2;
      for (i = 1; i <= kk; i++) {
        printf("#");
      }
      for (i = 1; i <= n - 2 * kk - 2; i++) {
        printf(".");
      }
      for (i = 1; i <= kk; i++) {
        printf("#");
      }
      printf(".\n");
    }
  } else {
    int kk = k / 2;
    printf(".");
    for (i = 1; i <= kk; i++) {
      printf("#");
    }
    for (i = kk + 1; i <= n; i++) {
      printf(".");
    }
    printf("\n");
    printf(".");
    for (i = 1; i <= kk; i++) {
      printf("#");
    }
    for (i = kk + 1; i <= n; i++) {
      printf(".");
    }
    printf("\n");
  }
  for (i = 1; i <= n; i++) {
    printf(".");
  }
  printf("\n");
  return 0;
}
