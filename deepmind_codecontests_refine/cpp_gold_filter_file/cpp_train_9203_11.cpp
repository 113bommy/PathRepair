#include <bits/stdc++.h>
int main() {
  long int i, j, n, A[4][4], flag = 0, k, index1, index2;
  scanf("%ld", &n);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) scanf("%d", &A[i][j]);
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 2; k <= 3; k++) {
        if (A[i][j] + A[i][k] <= n) {
          flag = 1;
          index1 = i;
          index2 = j;
          break;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 1) break;
  }
  if (flag == 0)
    printf("-1\n");
  else
    printf("%ld %ld %ld\n", index1 + 1, A[index1][index2],
           n - A[index1][index2]);
  return 0;
}
