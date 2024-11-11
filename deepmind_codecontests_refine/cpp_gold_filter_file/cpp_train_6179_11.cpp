#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n][n];
  int i, j, k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }
  int c = 0;
  for (i = 0; i < m; i++) {
    int x, y;
    c = 1;
    scanf("%d%d", &x, &y);
    a[x - 1][y - 1] = 1;
    if (x - 3 >= 0 && y - 3 >= 0) {
      for (j = x - 3; j < x; j++) {
        for (k = y - 3; k < y; k++) {
          c = c & a[j][k];
        }
      }
      if (c == 1) {
        printf("%d", i + 1);
        return 0;
      }
      c = 1;
    }
    if (x - 3 >= 0 && y + 2 <= n) {
      for (j = x - 3; j < x; j++) {
        for (k = y - 1; k < y + 2; k++) {
          c = c & a[j][k];
        }
      }
      if (c == 1) {
        printf("%d", i + 1);
        return 0;
      }
      c = 1;
    }
    if (x - 3 >= 0 && y + 1 <= n && y - 2 >= 0) {
      for (j = x - 3; j < x; j++) {
        for (k = y - 2; k < y + 1; k++) {
          c = c & a[j][k];
        }
      }
      if (c == 1) {
        printf("%d", i + 1);
        return 0;
      }
      c = 1;
    }
    if (x - 2 >= 0 && y - 3 >= 0 && x + 1 <= n) {
      for (j = x - 2; j < x + 1; j++) {
        for (k = y - 3; k < y; k++) {
          c = c & a[j][k];
        }
      }
      if (c == 1) {
        printf("%d", i + 1);
        return 0;
      }
      c = 1;
    }
    if (x - 2 >= 0 && y + 2 <= n && x + 1 <= n) {
      for (j = x - 2; j < x + 1; j++) {
        for (k = y - 1; k < y + 2; k++) {
          c = c & a[j][k];
        }
      }
      if (c == 1) {
        printf("%d", i + 1);
        return 0;
      }
      c = 1;
    }
    if (x - 2 >= 0 && y + 1 <= n && y - 2 >= 0 && x + 1 <= n) {
      for (j = x - 2; j < x + 1; j++) {
        for (k = y - 2; k < y + 1; k++) {
          c = c & a[j][k];
        }
      }
      if (c == 1) {
        printf("%d", i + 1);
        return 0;
      }
      c = 1;
    }
    if (x + 2 <= n && y - 3 >= 0) {
      for (j = x - 1; j < x + 2; j++) {
        for (k = y - 3; k < y; k++) {
          c = c & a[j][k];
        }
      }
      if (c == 1) {
        printf("%d", i + 1);
        return 0;
      }
      c = 1;
    }
    if (x + 2 <= n && y + 2 <= n) {
      for (j = x - 1; j < x + 2; j++) {
        for (k = y - 1; k < y + 2; k++) {
          c = c & a[j][k];
        }
      }
      if (c == 1) {
        printf("%d", i + 1);
        return 0;
      }
      c = 1;
    }
    if (x + 2 <= n && y + 1 <= n && y - 2 >= 0) {
      for (j = x - 1; j < x + 2; j++) {
        for (k = y - 2; k < y + 1; k++) {
          c = c & a[j][k];
        }
      }
      if (c == 1) {
        printf("%d", i + 1);
        return 0;
      }
      c = 1;
    }
  }
  printf("-1");
  return 0;
}
