#include <bits/stdc++.h>
void swap(int* x, int* y) {
  int u = *x;
  *x = *y;
  *y = u;
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    scanf("%d", &n);
    if ((n / 2) % 2 == 1) {
      printf("NO");
    } else {
      printf("YES\n");
      for (int j = 0; j < n / 2; j++) {
        printf("%d ", 2 * j + 2);
      }
      for (int j = 0; j < n / 2; j++) {
        if (j % 2 == 0) {
          printf("%d ", 2 * j + 1);
        } else {
          printf("%d ", 2 * j + 3);
        }
      }
    }
    printf("\n");
  }
}
