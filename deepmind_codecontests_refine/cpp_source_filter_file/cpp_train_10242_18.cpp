#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, v[5][5], a[5][5];
int main() {
  for (i = 1; i <= 3; i++)
    for (j = 1; j <= 3; j++) scanf("%d", &v[i][j]), v[i][j] %= 2, a[i][j] = 1;
  for (i = 1; i <= 3; i++)
    for (j = 1; j <= 3; j++)
      if (v[i][j] == 1) {
        a[i][j] *= -1;
        a[i + 1][j] *= -1;
        a[i - 1][j] *= -1;
        a[i][j - 1] *= -1;
        a[i][j + 1] *= -1;
      }
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) printf("%d ", a[i][j] == 1);
    printf("\n");
  }
  return 0;
}
