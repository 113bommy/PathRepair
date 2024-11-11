#include <bits/stdc++.h>
using namespace std;
int DP[107][107][17];
char MAT[107][107];
pair<char, int> PATH[107][107][17];
int main() {
  int i, j, k, l, m, n, x, y, z, a, b, r;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &b);
  for (i = 0; i < n; i++) scanf("%s", MAT[i]);
  for (i = 0; i < 107; i++)
    for (j = 0; j < 107; j++)
      for (k = 0; k < 17; k++) {
        DP[i][j][k] = -1;
        PATH[i][j][k] = make_pair('\0', -1);
      }
  for (j = 0; j < m; j++)
    DP[0][j][(MAT[0][j] - '0') % (b + 1)] = (MAT[0][j] - '0');
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < m; j++) {
      for (k = 0; k < (b + 1); k++) {
        if (DP[i][j][k] == -1) continue;
        if (j - 1 >= 0) {
          if (DP[i][j][k] + (MAT[i + 1][j - 1] - '0') >
              DP[i + 1][j - 1][(k + (MAT[i + 1][j - 1] - '0')) % (b + 1)]) {
            DP[i + 1][j - 1][(k + (MAT[i + 1][j - 1] - '0')) % (b + 1)] =
                DP[i][j][k] + (MAT[i + 1][j - 1] - '0');
            PATH[i + 1][j - 1][(k + (MAT[i + 1][j - 1] - '0')) % (b + 1)] =
                make_pair('R', k);
          }
        }
        if (j + 1 < m) {
          if (DP[i][j][k] + (MAT[i + 1][j + 1] - '0') >
              DP[i + 1][j + 1][(k + (MAT[i + 1][j + 1] - '0')) % (b + 1)]) {
            DP[i + 1][j + 1][(k + (MAT[i + 1][j + 1] - '0')) % (b + 1)] =
                DP[i][j][k] + (MAT[i + 1][j + 1] - '0');
            PATH[i + 1][j + 1][(k + (MAT[i + 1][j + 1] - '0')) % (b + 1)] =
                make_pair('L', k);
          }
        }
      }
    }
  }
  int ans = -1;
  for (j = 0; j < m; j++)
    if (ans < DP[n - 1][j][0]) {
      ans = DP[n - 1][j][0];
      i = j;
    }
  printf("%d\n", ans);
  if (ans != -1) {
    printf("%d\n", i + 1);
    j = i;
    i = n - 1;
    k = 0;
    while (i > 0) {
      printf("%c", PATH[i][j][k].first);
      z = PATH[i][j][k].second;
      if (PATH[i][j][k].first == 'L')
        j--;
      else
        j++;
      i--;
      k = z;
    }
    if (n - 1 > 0) printf("\n");
  }
  return 0;
}
