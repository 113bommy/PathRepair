#include <bits/stdc++.h>
using namespace std;
const int maxn = 30011, maxk = 211;
int n, k;
int a[maxn];
void init() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
}
int f[maxn][maxk][4];
void work() {
  for (int i = 1; i <= k; ++i)
    for (int j = 0; j <= 3; ++j) f[0][i][j] = -1e9;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      int flag = 1;
      if (j != 1 && j != k) flag++;
      f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j - 1][3]) - flag * a[i];
      f[i][j][1] = max(f[i - 1][j][1], f[i][j][0]);
      f[i][j][2] = max(f[i - 1][j][2], f[i - 1][j - 1][1]) + flag * a[i];
      f[i][j][3] = max(f[i - 1][j][3], f[i][j][2]);
      if (flag == 2) {
        f[i][j][1] = max(f[i][j][1], f[i - 1][j - 1][1]);
        f[i][j][3] = max(f[i][j][3], f[i - i][j - 1][3]);
      }
    }
  printf("%d\n", max(f[n][k][1], f[n][k][3]));
}
int main() {
  init();
  work();
  return 0;
}
