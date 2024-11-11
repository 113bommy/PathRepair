#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int A[1010];
  int i, j, x = 0, y = 0, ymax = -100000000, ymin = 100000000;
  for (i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    x += A[i];
    if (i % 2 == 1)
      y += A[i];
    else
      y -= A[i];
    if (y > ymax) ymax = y;
    if (y < ymin) ymin = y;
  }
  char str[ymax - ymin + 1][x + 1];
  for (i = 0; i < ymax - ymin + 1; i++) {
    for (j = 0; j < x + 1; j++) str[i][j] = ' ';
  }
  int c = -1, r = ymax - 1;
  for (i = 1; i <= n; i++) {
    c++;
    if (i % 2 == 1) {
      for (j = 0; j < A[i]; j++) {
        str[r - j][c + j] = '/';
      }
      r -= (A[i] - 1);
      c += A[i] - 1;
    } else {
      for (j = 0; j < A[i]; j++) {
        str[r + j][c + j] = '\\';
      }
      r += (A[i] - 1);
      c += A[i] - 1;
    }
  }
  for (i = 0; i < ymax - ymin; i++) {
    for (j = 0; j < x; j++) printf("%c", str[i][j]);
    printf("\n");
  }
  return 0;
}
