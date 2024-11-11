#include <bits/stdc++.h>
int a[8];
int b[8];
int main() {
  int n, num, i, sum = 0, temp;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    a[num] = a[num] + 1;
    b[num] = b[num] + 1;
  }
  if (b[0] > 0 || b[3] > 0 || b[7] > 0 || b[1] == 0) {
    printf("-1");
    return 0;
  } else {
    while (b[1] > 0 && b[2] > 0 && b[4] > 0) {
      b[1] -= 1;
      b[2] -= 1;
      b[4] -= 1;
    }
    while (b[1] > 0 && b[2] > 0 && b[6] > 0) {
      b[1] -= 1;
      b[2] -= 1;
      b[6] -= 1;
    }
    while (b[1] > 0 && b[3] > 0 && b[6] > 0) {
      b[1] -= 1;
      b[3] -= 1;
      b[6] -= 1;
    }
    for (i = 0; i < 8; i++) {
      if (b[i] > 0) {
        printf("-1");
        return 0;
      }
    }
  }
  while (a[1] > 0 && a[2] > 0 && a[4] > 0) {
    a[1] -= 1;
    a[2] -= 1;
    a[4] -= 1;
    printf("1 2 4\n");
  }
  while (a[1] > 0 && a[2] > 0 && a[6] > 0) {
    printf("1 2 6\n");
    a[1] -= 1;
    a[2] -= 1;
    a[6] -= 1;
  }
  while (a[1] > 0 && a[3] > 0 && a[6] > 0) {
    printf("1 3 6\n");
    a[1] -= 1;
    a[3] -= 1;
    a[6] -= 1;
  }
  return 0;
}
