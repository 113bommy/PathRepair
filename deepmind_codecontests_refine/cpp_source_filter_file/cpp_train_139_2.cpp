#include <bits/stdc++.h>
int main() {
  int n, i, j, r, c, count;
  scanf("%d", &n);
  int A[n + 100][2];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (A[i][0] == A[j][1]) count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
