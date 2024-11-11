#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  int n;
  scanf("%d", &n);
  int mat[100 + 7][100 + 7];
  memset(mat, 0, sizeof(mat));
  int x[2], y[2];
  for (i = 0; i < n; i++) {
    scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
    for (j = x[0]; j <= x[1]; j++) {
      for (int k = y[0]; k <= y[1]; k++) {
        mat[j][k]++;
      }
    }
  }
  int sum = 0;
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++) sum += mat[i][j];
  printf("%d", sum);
  return 0;
}
