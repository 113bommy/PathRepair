#include <bits/stdc++.h>
using namespace std;
int n;
double arr[20][20];
double dp[20][1 << 18];
bool vis[20][1 << 18];
double solve(int w, int mask) {
  if (__builtin_popcount(mask) == n) {
    if (w == 1)
      return 1;
    else
      return 0;
  }
  if (vis[w][mask] == 1) return dp[w][mask];
  vis[w][mask] = 1;
  double ret = 0;
  for (int i = 1; i <= n; i++) {
    if (!(mask & (1 << i))) {
      double tmp = 0;
      tmp += solve(w, mask | (1 << i)) * arr[w][i];
      tmp += solve(i, mask | (1 << i)) * arr[i][w];
      ret = max(ret, tmp);
    }
  }
  return dp[w][mask] = ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%lf", &arr[i][j]);
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, solve(i, 1 << i));
  }
  printf("%.9lf\n", ans);
  return 0;
}
