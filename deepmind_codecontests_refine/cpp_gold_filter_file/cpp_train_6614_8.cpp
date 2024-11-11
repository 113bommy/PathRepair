#include <bits/stdc++.h>
using namespace std;
const int nmax = 200, qmax = 200000;
int a[nmax][nmax], t[qmax], x[qmax], y[qmax], z[qmax];
int n, m, q;
int main() {
  int i, j;
  cin >> n >> m >> q;
  for (i = 1; i <= q; i++) {
    scanf("%d%d", t + i, x + i);
    if (t[i] == 3) scanf("%d%d", y + i, z + i);
  }
  for (i = q; i; i--) {
    if (t[i] == 3)
      a[x[i]][y[i]] = z[i];
    else if (t[i] == 2) {
      for (j = n; j; j--) a[j + 1][x[i]] = a[j][x[i]];
      a[1][x[i]] = a[n + 1][x[i]];
    } else {
      for (j = m; j; j--) a[x[i]][j + 1] = a[x[i]][j];
      a[x[i]][1] = a[x[i]][m + 1];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) printf("%d ", a[i][j]);
    printf("\n");
  }
  return 0;
}
