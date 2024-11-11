#include <bits/stdc++.h>
int main() {
  int i, j, k, m, n, mim;
  scanf("%i%i", &n, &m);
  int v[n + 2];
  bool ma[m + 2][m + 2];
  for (i = 1; i <= n; i++) scanf("%i", &v[i]);
  memset(ma, 0, sizeof(ma));
  for (i = 1; i <= m; i++) {
    scanf("%i%i", &j, &k);
    ma[j][k] = 1;
    ma[k][j] = 1;
  }
  mim = 1000001;
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      for (k = j + 1; k <= n; k++)
        if (ma[i][j] && ma[j][k] && ma[i][k] && v[i] + v[j] + v[k] < mim)
          mim = v[i] + v[j] + v[k];
  if (mim == 1000001) mim = -1;
  printf("%i", mim);
  return 0;
}
