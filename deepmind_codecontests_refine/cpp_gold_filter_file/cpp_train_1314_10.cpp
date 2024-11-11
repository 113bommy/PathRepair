#include <bits/stdc++.h>
using namespace std;
int a[2][10];
int main() {
  for (int i = 0; i < 10; i++) a[1][i] = 1;
  int n, m;
  char c;
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    scanf("%c %d", &c, &m);
    getchar();
    if (c == '&') {
      for (int j = 0; j < 10; j++)
        for (int k = 0; k < 2; k++) a[k][j] &= ((m >> j) & 1);
    }
    if (c == '|') {
      for (int j = 0; j < 10; j++)
        for (int k = 0; k < 2; k++) a[k][j] |= ((m >> j) & 1);
    }
    if (c == '^') {
      for (int j = 0; j < 10; j++)
        for (int k = 0; k < 2; k++) a[k][j] ^= ((m >> j) & 1);
    }
  }
  int x = 0, y = 0, z = 0;
  for (int i = 9; i >= 0; i--) {
    if (a[0][i] == 0 && a[1][i] == 1) {
      x = x * 2 + 1;
      y = y * 2 + 0;
      z = z * 2 + 0;
    } else if (a[0][i] == 1 && a[1][i] == 0) {
      x = x * 2 + 1;
      y = y * 2 + 0;
      z = z * 2 + 1;
    } else if (a[0][i] == 0 && a[1][i] == 0) {
      x = x * 2 + 0;
      y = y * 2 + 0;
      z = z * 2 + 0;
    } else {
      x = x * 2 + 1;
      y = y * 2 + 1;
      z = z * 2 + 0;
    }
  }
  printf("3\n");
  printf("& %d\n", x);
  printf("| %d\n", y);
  printf("^ %d\n", z);
  return 0;
}
