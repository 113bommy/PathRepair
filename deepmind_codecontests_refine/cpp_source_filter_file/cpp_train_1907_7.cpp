#include <bits/stdc++.h>
using namespace std;
int n;
char a[155];
int Best[155][155], Full[155][155], D[155][155][155], cost[155];
int main() {
  int i, j, k, t;
  cin.sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> cost[i];
  cin >> (a + 1);
  for (i = 0; i <= n; ++i)
    for (j = 0; j <= n; ++j) {
      Full[i][j] = -1000000000;
      for (k = 0; k <= n; ++k) D[i][j][k] = -1000000000;
    }
  for (i = 1; i <= n; ++i) {
    D[i][i][1] = 0;
    D[i][i - 1][0] = 0;
    if (cost[1] != -1) Full[i][i] = D[i][i][0] = cost[1];
  }
  D[n + 1][n][0] = 0;
  for (i = n; i; --i)
    for (j = i + 1; j <= n; ++j) {
      for (k = 1; k <= j - i + 1; ++k) {
        for (t = i; t <= j; ++t) {
          if (t > i) D[i][j][k] = max(D[i][j][k], D[t][j][k] + Full[i][t - 1]);
          if (t < j) D[i][j][k] = max(D[i][j][k], D[i][t][k] + Full[t + 1][j]);
        }
        if (a[i] == a[j])
          if (k >= 2) D[i][j][k] = max(D[i][j][k], D[i + 1][j - 1][k - 2]);
        if (cost[k] != -1) Full[i][j] = max(Full[i][j], D[i][j][k] + cost[k]);
      }
      D[i][j][0] = Full[i][j];
    }
  for (i = 0; i <= n; ++i)
    for (j = 0; j <= n; ++j) Best[i][j] = -1000000000;
  for (i = 1; i <= n + 1; ++i) Best[i][i - 1] = 0;
  for (i = n; i; --i)
    for (j = i + 1; j <= n; ++j) {
      Best[i][j] = Full[i][j];
      for (k = i; k <= j; ++k)
        Best[i][j] = max(Best[i][j], Best[i][k - 1] + Best[k + 1][j]);
    }
  cout << max(Best[1][n], 0) << "\n";
  return 0;
}
