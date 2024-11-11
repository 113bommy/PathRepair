#include <bits/stdc++.h>
int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  getchar();
  char ab[x + 1][y + 1];
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      scanf("%c", &ab[i][j]);
    }
    getchar();
  }
  int a[5], b[5];
  int z = 1;
  int x1, y1;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      if (ab[i][j] == '*') {
        a[z] = i;
        b[z] = j;
        z++;
      }
    }
  }
  if (a[1] != a[2] && a[1] != a[3]) {
    x1 = a[1];
  } else if (a[2] != a[1] && a[2] != a[3]) {
    x1 = a[2];
  } else if (a[3] != a[1] && a[3] != a[2]) {
    x1 = a[3];
  }
  if (b[1] != b[2] && b[1] != b[3]) {
    y1 = b[1];
  } else if (b[2] != b[1] && b[2] != b[3]) {
    y1 = b[2];
  } else if (b[3] != b[1] && b[3] != b[2]) {
    y1 = b[3];
  }
  printf("%d %d", x1, y1);
  return 0;
}
