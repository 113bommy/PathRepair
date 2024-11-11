#include <bits/stdc++.h>
using namespace std;
int f1[100][100][3];
int f(int i, int j, int k) {
  if (i == 0 && j == 0) return 1;
  if (i <= 0 || j <= 0)
    return 0;
  else
    return f1[i][j][k];
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++) {
      f1[i][j][1] = f(i - 1, j - 2, 3) + 2 * f(i - 1, j - 2, 2) +
                    3 * f(i - 1, j - 2, 1) + 2 * f(i - 1, j - 3, 3) +
                    4 * f(i - 1, j - 3, 2) + 6 * f(i - 1, j - 3, 1) +
                    f(i - 1, j - 4, 3) + 3 * f(i - 1, j - 4, 2) +
                    7 * f(i - 1, j - 4, 1) + f(i - 1, j - 5, 2) +
                    4 * f(i - 1, j - 5, 1) + f(i - 1, j - 6, 1);
      f1[i][j][2] =
          f(i - 1, j - 2, 3) + 2 * f(i - 1, j - 2, 2) + 2 * f(i - 1, j - 2, 1) +
          f(i - 1, j - 3, 3) + 2 * f(i - 1, j - 3, 2) + 4 * f(i - 1, j - 3, 1) +
          f(i - 1, j - 4, 2) + 3 * f(i - 1, j - 4, 1) + f(i - 1, j - 5, 1);
      f1[i][j][3] = f(i - 1, j - 2, 1) + f(i - 1, j - 2, 2) +
                    f(i - 1, j - 2, 3) + f(i - 1, j - 2, 2) +
                    2 * f(i - 1, j - 2, 1) + f(i - 1, j - 3, 1);
    }
  printf("%d", f1[k][n - 1][1] + f1[k][n - 1][2] + f1[k][n - 1][3]);
}
