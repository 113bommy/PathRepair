#include <bits/stdc++.h>
int a[105][104];
int main() {
  int x1, y1, x2, y2;
  int n, i, j, s = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (i = x1; i <= x2; i++) {
      for (j = y1; j <= y2; j++) {
        a[i][j]++;
      }
    }
  }
  for (i = 0; i <= x2; i++) {
    for (j = 0; j <= y2; j++) {
      s = s + a[i][j];
    }
  }
  printf("%d", s);
  return 0;
}
