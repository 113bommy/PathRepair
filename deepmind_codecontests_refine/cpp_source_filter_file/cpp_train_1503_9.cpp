#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int v[N], a[N], F[N], n;
int f[N][N], u[N][N], d[N][N];
int main() {
  scanf("%d", &n);
  memset(u, 200, sizeof(u));
  ;
  memset(d, 200, sizeof(d));
  ;
  memset(f, 200, sizeof(f));
  ;
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &v[i]);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++) u[i][i] = d[i][i];
  for (int i = (int)(n); i >= (int)(1); i--)
    for (int j = (int)(i); j <= (int)(n); j++) {
      for (int k = (int)(i); k <= (int)(j - 1); k++)
        f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
      for (int k = (int)(i); k <= (int)(j - 1); k++)
        if (a[k] == a[j] - 1)
          u[i][j] = max(u[i][j], u[i][k] + (k < j - 1 ? f[k + 1][j - 1] : 0));
      for (int k = (int)(i + 1); k <= (int)(j); k++)
        if (a[k] == a[i] - 1)
          d[i][j] = max(d[i][j], d[k][j] + (k > i + 1 ? f[i + 1][k - 1] : 0));
      for (int k = (int)(i); k <= (int)(j); k++)
        if (a[k] >= a[i] && a[k] >= a[j] && 2 * a[k] - a[i] - a[j] <= j - i)
          f[i][j] =
              max(f[i][j], u[i][k] + d[k][j] + v[2 * a[k] - a[i] - a[j] + 1]);
    }
  for (int i = (int)(1); i <= (int)(n); i++) {
    F[i] = F[i - 1];
    for (int j = (int)(1); j <= (int)(i); j++)
      F[i] = max(F[i], F[j - 1] + f[j][i]);
  }
  printf("%d\n", F[n]);
}
