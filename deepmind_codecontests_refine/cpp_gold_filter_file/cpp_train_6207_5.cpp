#include <bits/stdc++.h>
using namespace std;
const int MAX = 120;
char ans[4][MAX];
int n;
int main() {
  scanf("%d", &n);
  if (n % 2 == 0) {
    int x = 0;
    int f = 0;
    while (x <= n - 2) {
      if (f == 0)
        ans[0][x] = ans[0][x + 1] = 'a';
      else
        ans[0][x] = ans[0][x + 1] = 'b';
      x = x + 2;
      f = f ^ 1;
    }
    ans[1][0] = ans[2][0] = 'c', ans[1][n - 1] = ans[2][n - 1] = 'd';
    x = 1, f = 0;
    while (x <= n - 3) {
      if (f == 0)
        ans[1][x] = ans[1][x + 1] = 'e';
      else
        ans[1][x] = ans[1][x + 1] = 'f';
      x = x + 2;
      f = f ^ 1;
    }
    x = 1, f = 0;
    while (x <= n - 3) {
      if (f == 0)
        ans[2][x] = ans[2][x + 1] = 'f';
      else
        ans[2][x] = ans[2][x + 1] = 'e';
      x = x + 2;
      f = f ^ 1;
    }
    x = 0, f = 0;
    while (x <= n - 2) {
      if (f == 0)
        ans[3][x] = ans[3][x + 1] = 'g';
      else
        ans[3][x] = ans[3][x + 1] = 'h';
      x = x + 2;
      f = f ^ 1;
    }
  } else {
    int x = 0, f = 0;
    ans[0][n - 1] = ans[1][n - 1] = 'c';
    while (x <= n - 3) {
      if (f == 0)
        ans[0][x] = ans[0][x + 1] = 'a';
      else
        ans[0][x] = ans[0][x + 1] = 'b';
      x = x + 2;
      f = f ^ 1;
    }
    x = 0, f = 0;
    while (x <= n - 3) {
      if (f == 0)
        ans[1][x] = ans[1][x + 1] = 'b';
      else
        ans[1][x] = ans[1][x + 1] = 'a';
      x = x + 2;
      f = f ^ 1;
    }
    ans[2][0] = ans[3][0] = 'd';
    x = 1, f = 0;
    while (x <= n - 2) {
      if (f == 0)
        ans[2][x] = ans[2][x + 1] = 'e';
      else
        ans[2][x] = ans[2][x + 1] = 'f';
      x = x + 2;
      f = f ^ 1;
    }
    x = 1, f = 0;
    while (x <= n - 2) {
      if (f == 0)
        ans[3][x] = ans[3][x + 1] = 'f';
      else
        ans[3][x] = ans[3][x + 1] = 'e';
      x = x + 2;
      f = f ^ 1;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) printf("%c", ans[i][j]);
    printf("\n");
  }
  return 0;
}
