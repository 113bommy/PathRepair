#include <bits/stdc++.h>
int main() {
  int n, i, j, count = 0;
  char a[150][3];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < 3; j++) {
      if (a[i][j] == '+') {
        count++;
        break;
      } else if (a[i][j] == '-') {
        count--;
        break;
      }
    }
  }
  printf("%d", count);
}
