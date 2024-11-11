#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int a[51], f[500009];
int X[500009], tot, dp[500009];
int bin(int L, int R, int x) {
  if (X[R] < x - d) return -1;
  while (L < R) {
    int M = (L + R) >> 1;
    if (X[M] >= x)
      R = M;
    else
      L = M + 1;
  }
  return R;
}
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    m += a[i];
  }
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= a[i]; j--) f[j] = f[j] | f[j - a[i]];
  }
  for (int i = 0; i <= m; i++)
    if (f[i]) X[tot++] = i;
  for (int i = 0; i < tot; i++) dp[i] = 1e9;
  dp[0] = 0;
  for (int i = 1; i < tot; i++) {
    int L = 0, R = i - 1;
    int pos = bin(L, R, X[i] - d);
    if (pos == -1) continue;
    dp[i] = dp[pos] + 1;
  }
  int ans = 0, day = 0;
  for (int i = 0; i < tot; i++) {
    if (dp[i] >= 1e9) continue;
    ans = X[i];
    day = dp[i];
  }
  printf("%d %d\n", ans, day);
  return 0;
}
