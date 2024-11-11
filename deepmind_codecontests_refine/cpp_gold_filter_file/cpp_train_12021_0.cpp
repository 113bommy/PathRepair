#include <bits/stdc++.h>
using namespace std;
using DO = double;
int x[1010], b[1010], mn[1010];
int pre[1010], n, L;
DO dp[1010], eps = 1e-7;
DO dist[1010][1010];
bool smin(DO &a, DO b) {
  if (b > a + eps) return false;
  a = b;
  return true;
}
bool can(DO t) {
  for (int i = 1; i <= n; i++) {
    dp[i] = dist[0][i] - b[i] * t, pre[i] = 0;
    for (int j = 1; j < i; j++) {
      if (smin(dp[i], dp[j] + dist[j][i] - b[i] * t)) {
        pre[i] = j;
      }
    }
  }
  return dp[n] < eps;
}
int main() {
  scanf("%d %d", &n, &L);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", x + i, b + i);
    for (int j = 0; j < i; j++) {
      dist[j][i] = sqrt(fabs(x[i] - x[j] - L));
    }
  }
  DO st = 0, ed = dist[0][n] / b[n];
  for (int i = 22; i--;) {
    DO md = (st + ed) / 2;
    if (can(md))
      ed = md;
    else
      st = md;
  }
  L = 0;
  for (int u = n; u; u = pre[u]) x[L++] = u;
  for (int i = L; i--;) printf("%d ", x[i]);
}
