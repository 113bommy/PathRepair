#include <bits/stdc++.h>
int main() {
  int i, j, k = 0, count = 0, a[5][5];
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (a[i][j] == 1) {
        k = 1;
        break;
      }
    }
    if (k == 1) break;
  }
  if (j > 2) {
    for (; j != 2; j--) count++;
  } else if (j < 2) {
    for (; j != 2; j++) count++;
  }
  if (i > 2) {
    for (; i != 2; i--) count++;
  } else if (i < 2) {
    for (; i != 2; i++) count++;
  }
  printf("\n%d", count);
}
