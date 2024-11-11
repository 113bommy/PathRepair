#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  scanf("%d", &n);
  if (n % 2 == 0) {
    printf("%d\n", n * n / 2);
    for (i = 0; i < n; i++) {
      for (j = 0; j < n / 2; j++) {
        if (i % 2 == 0)
          printf("C.");
        else
          printf(".C");
      }
      printf("\n");
    }
  } else {
    printf("%d\n", ((n / 2) * (n / 2)) + ((n / 2 + 1) * (n / 2 + 1)));
    for (i = 0; i < n; i++) {
      for (j = 0; j < n / 2; j++) {
        if (i % 2 == 0)
          printf("C.");
        else
          printf(".C");
      }
      if (i % 2 == 0)
        printf("C\n");
      else
        printf(".\n");
    }
  }
}
