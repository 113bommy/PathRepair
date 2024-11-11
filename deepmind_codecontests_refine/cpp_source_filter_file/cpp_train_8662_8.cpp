#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], b[N], s0, s1, ans, f[N][N][N][2];
int main() {
  scanf("%d", &n);
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]] = 1;
  b[0] = 0;
  for (int i = 1; i <= n; i++)
    if (!b[i]) (i & 1) ? s1++ : s0++;
  if (a[1])
    f[1][0][0][a[1] & 1] = 0;
  else
    f[1][1][0][0] = f[1][0][1][1] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j <= s0; j++)
      for (int k = 0; k <= s1; k++)
        for (int u = 0; u < 2; u++)
          if (a[i])
            f[i][j][k][a[i] & 1] = min(f[i - 1][j][k][u] + (u != (a[i] & 1)),
                                       f[i][j][k][a[i] & 1]);
          else
            for (int v = 0; v < 2; v++)
              f[i][j + (v == 0)][k + (v == 1)][v] =
                  min(f[i - 1][j][k][u] + (u != v),
                      f[i][j + (v == 0)][k + (v == 1)][v]);
  printf("%d\n", min(f[n][s0][s1][0], f[n][s0][s1][1]));
}
