#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int mat[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) mat[i][j] = 0;
  }
  int br = 0;
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1, x = i; j <= n && x <= n; j++, x++) {
      mat[x][j] = 1;
      br++;
    }
  }
  for (int i = 3; i <= n; i += 2) {
    for (int h = 1, j = i; h <= n && j <= n; h++, j++) {
      mat[j][h] = 1;
      br++;
    }
  }
  if (br < k) {
    printf("NO");
    return 0;
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (k > 0) {
        if (mat[i][j]) {
          printf("L");
          k--;
        } else
          printf("S");
      } else
        printf("S");
    }
    printf("\n");
  }
  return 0;
}
