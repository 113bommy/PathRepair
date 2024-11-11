#include <bits/stdc++.h>
using namespace std;
int two[20];
double a[20][20], f[262144];
int main() {
  int i, j, k, n;
  scanf("%d", &n);
  two[0] = 1;
  for (i = 1; i <= n; ++i) two[i] = two[i - 1] << 1;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) scanf("%lf", &a[i][j]);
  f[1] = 1.0;
  for (i = 2; i < two[n]; ++i)
    for (j = 1; j <= n; ++j)
      for (k = 1; k <= n; ++k)
        if ((i & two[j - 1]) && (i & two[k - 1]))
          f[i] = ((f[i]) > (f[i ^ two[j - 1]] * a[k][j] +
                            f[i ^ two[k - 1]] * a[j][k])
                      ? (f[i])
                      : (f[i ^ two[j - 1]] * a[k][j] +
                         f[i ^ two[k - 1]] * a[j][k]));
  printf("%.7lf\n", f[two[n] - 1]);
  return 0;
}
