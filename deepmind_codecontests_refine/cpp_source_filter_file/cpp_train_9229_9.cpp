#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j;
  scanf("%d %d", &n, &k);
  if (k % 2 == 0) {
    printf("YES\n");
    for (i = 0; i < n; i++) {
      printf(".");
    }
    printf("\n");
    for (i = 1; i < 3; i++) {
      printf(".");
      for (int j = 1; j <= k / 2; j++) {
        printf("#");
      }
      for (int j = 1; j < n - 1 - k / 2; j++) {
        printf(".");
      }
      printf(".\n");
    }
    for (i = 0; i < n; i++) {
      printf(".");
    }
  } else if (n == k) {
    printf("YES\n");
    for (i = 0; i < n; i++) {
      printf(".");
    }
    printf("\n");
    printf(".");
    for (i = 1; i <= (k - 1) / 2; i++) printf("#");
    printf("#.");
    for (i = 1; i <= (n - 5) / 2; i++) printf(".");
    printf("\n.#.");
    for (i = 1; i <= (k - 3) / 2; i++) printf("#");
    for (i = 1; i <= ((n - 1) - (k - 1) / 2) / 2; i++) printf(".");
    printf(".\n");
    for (i = 0; i < n; i++) {
      printf(".");
    }
  } else if (n <= k) {
    printf("YES\n");
    for (i = 0; i < n; i++) {
      printf(".");
    }
    printf("\n");
    printf(".");
    for (i = 1; i <= (k - 1) / 2; i++) printf("#");
    printf("#");
    for (i = 1; i <= ((n - 1) - (k - 1) / 2) / 2; i++) printf(".");
    printf("\n.#.");
    for (i = 1; i <= (k - 3) / 2; i++) printf("#");
    for (i = 1; i <= ((n - 1) - (k - 1) / 2) / 2; i++) printf(".");
    printf("\n");
    for (i = 0; i < n; i++) {
      printf(".");
    }
  } else {
    printf("YES\n");
    for (i = 0; i < n; i++) {
      printf(".");
    }
    printf("\n");
    for (j = 0; j <= (n - k) / 2 - 1; j++) {
      printf(".");
    }
    for (int j = 1; j <= k; j++) {
      printf("#");
    }
    for (int j = 0; j <= (n - k) / 2 - 1; j++) {
      printf(".");
    }
    printf("\n");
    for (j = 0; j < n; j++) {
      printf(".");
    }
    printf("\n");
    for (i = 0; i < n; i++) {
      printf(".");
    }
  }
  return 0;
}
