#include <bits/stdc++.h>
int get_int();
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
int min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
void bf(int* a, int* b, int n, int i, int j, int c) {
  if (i < 0 || j < 0 || i >= n || j >= n || b[i * n + j] != 0 ||
      a[i * n + j] == 1) {
    return;
  }
  b[i * n + j] = c;
  bf(a, b, n, i + 1, j + 0, c);
  bf(a, b, n, i + 0, j + 1, c);
  bf(a, b, n, i + 0, j - 1, c);
  bf(a, b, n, i - 1, j + 0, c);
}
int main() {
  int i, j, k, l;
  int n = get_int();
  int r1 = get_int() - 1;
  int c1 = get_int() - 1;
  int r2 = get_int() - 1;
  int c2 = get_int() - 1;
  int a[n][n];
  int b[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = getchar() - '0';
      b[i][j] = 0;
    }
    getchar();
  }
  int mn = 1000000000;
  bf(&(a[0][0]), &(b[0][0]), n, r1, c1, 1);
  bf(&(a[0][0]), &(b[0][0]), n, r2, c2, 2);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (b[i][j] != 1) {
        continue;
      }
      for (k = 0; k < n; k++) {
        for (l = 0; l < n; l++) {
          if (b[k][l] == 2) {
            mn = min(mn, (i - k) * (i - k) + (j - l) * (j - l));
          }
        }
      }
    }
  }
  if (mn == 1000000000) {
    printf("0\n");
  } else {
    printf("%d\n", mn);
  }
  return 0;
}
int get_int() {
  int ret = 0;
  char c = getchar();
  int sgn;
  while (1) {
    if (c == EOF) {
      return EOF;
    }
    if (c >= '0' && c <= '9') {
      sgn = 1;
      break;
    }
    if (c == '-') {
      c = getchar();
      if (c < '0' || c > '9') {
        continue;
      }
      sgn = -1;
      break;
    }
    c = getchar();
  }
  while (1) {
    ret = (ret << 3) + (ret << 1) + c - '0';
    c = getchar();
    if (c < '0' || c > '9') {
      return sgn * ret;
    }
  }
}
