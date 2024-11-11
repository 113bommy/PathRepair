#include <bits/stdc++.h>
using namespace std;
int n, a[2009][2009];
long long d[2009];
bool bo[2009];
int main() {
  scanf("%d", &n);
  int i, j, k, mn = 1000000000;
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      a[j][i] = a[i][j];
      mn = min(mn, a[i][j]);
    }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (i != j) a[i][j] -= mn;
  memset(d, 60, sizeof(d));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (i != j) {
        if (!a[i][j]) bo[i] = 1;
        d[i] = min(d[i], 2ll * a[i][j]);
        d[j] = min(d[j], 2ll * a[i][j]);
      }
  for (i = 1; i <= n; i++)
    if (bo[i]) {
      d[i] = 0;
      for (j = 1; j <= n; j++)
        if (i != j) d[j] = min(d[j], (long long)a[i][j]);
    }
  memset(bo, 1, sizeof(bo));
  for (i = 1; i <= n; i++) {
    for (j = 1, k = 0; j <= n; j++)
      if (bo[j] && d[j] < d[k]) k = j;
    bo[k] = 0;
    for (j = 1; j <= n; j++)
      if (bo[j]) d[j] = min(d[j], d[k] + a[k][j]);
  }
  for (i = 1; i <= n; i++) printf("%lld\n", d[i] + (long long)mn * (n - 1));
  return 0;
}
