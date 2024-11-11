#include <bits/stdc++.h>
int main() {
  int a[4], temp, i, j;
  scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
  for (i = 0; i < 4; i++) {
    for (j = i + 1; j < 4; j++) {
      if (a[j] > a[i]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  printf("%d %d %d", a[0] - a[1], a[0] - a[2], a[0] - a[3]);
}
