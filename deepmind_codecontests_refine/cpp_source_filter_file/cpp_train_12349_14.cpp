#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 5500;
int n, r, f[N], s[N], p[N];
double dp[N][M];
bool check(double tim) {
  for (int i = n; i; i--) {
    for (int j = (r + 1); j <= (M - 1); j++) dp[i + 1][j] = tim;
    for (int j = (0); j <= (r); j++)
      dp[i][j] =
          min(tim, (dp[i + 1][j + f[i]] + f[i]) * p[i] / 100.0 +
                       (dp[i + 1][j + s[i]] + s[i]) * (1.0 - p[i] / 100.0));
  }
  return dp[1][0] < tim;
}
int main() {
  scanf("%d%d", &n, &r);
  for (int i = (1); i <= (n); i++) scanf("%d%d%d", &f[i], &s[i], &p[i]);
  double l = 0, r = 5000, mid;
  for (int step = (0); step <= (59); step++) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf\n", r);
  return 0;
}
