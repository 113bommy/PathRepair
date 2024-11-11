#include <bits/stdc++.h>
using namespace std;
int n;
long double dp[1 << 18][18], mat[18][18];
long double solve(int mask, int v) {
  if (__builtin_popcount(mask) == n - 1) return mat[0][v];
  long double& ret = dp[mask][v];
  if (ret >= -0.1) return 0;
  ret = 0;
  for (int(i) = (1); (i) < (n); (i)++)
    if (!(mask & (1 << i)))
      ret = max(ret, solve(mask | (1 << i), v) * mat[v][i] +
                         solve(mask | (1 << i), i) * mat[i][v]);
  return ret;
}
int main() {
  for (int(i) = (0); (i) < (1 << 18); (i)++)
    for (int(j) = (0); (j) < (18); (j)++) dp[i][j] = -1;
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (n); (j)++) scanf("%Lf", &mat[i][j]);
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  long double ans = -1;
  for (int(i) = (1); (i) < (n); (i)++) ans = max(ans, solve(1 << i, i));
  printf("%.15Lf\n", ans);
}
