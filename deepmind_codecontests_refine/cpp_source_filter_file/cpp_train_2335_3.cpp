#include <bits/stdc++.h>
using namespace std;
int a[1001][1000];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int j = 0; j < m; j++) a[0][j] = 5;
  int one = 0, zero = 0, mix = 0;
  char s[3];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%s", s);
      if (strcmp("11", s) == 0)
        one++;
      else if (strcmp("00", s) == 0)
        zero++;
      else
        mix++;
    }
  }
  int i = 1, j = 0;
  while (one--) {
    a[i][j++] = 1;
    if (j == m) {
      i++;
      j = 0;
    }
  }
  int x = m - j;
  while (j != 0 && x > 0 && mix--) {
    x--;
    a[i][j++] = 3;
    if (j == m) {
      i++;
      j = 0;
    }
  }
  while (zero--) {
    a[i][j++] = 2;
    if (j == m) {
      i++;
      j = 0;
    }
  }
  bool in = false;
  for (; i <= n; i++) {
    if (in) j = 0;
    for (; j < m; j++) {
      in = true;
      if (a[i - 1][j] != 3)
        a[i][j] = 3;
      else
        a[i][j] = 4;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1)
        printf("11 ");
      else if (a[i][j] == 2)
        printf("00 ");
      else if (a[i][j] == 3)
        printf("01 ");
      else if (a[i][j] == 4)
        printf("10 ");
    }
    printf("\n");
  }
}
