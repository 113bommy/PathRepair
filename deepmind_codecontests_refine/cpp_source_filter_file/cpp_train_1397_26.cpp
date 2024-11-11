#include <bits/stdc++.h>
using namespace std;
int a[105], b[105], n, k;
int dp[105][30005][5];
int solve(int pos, int w, int flag) {
  if (pos == n) {
    if (flag == 1 and w == 0)
      return 0;
    else
      return -1e9;
  }
  if (dp[pos][w + 10000][flag] != -1) return dp[pos][w + 10000][flag];
  int r1 = solve(pos + 1, w, flag);
  int r2 = solve(pos + 1, w + a[pos] - b[pos], 1) + a[pos];
  return dp[pos][w + 10000][flag] = max(r1, r2);
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    b[i] *= k;
  }
  int res = solve(0, 0, 0);
  if (res <= 0)
    printf("-1\n");
  else
    printf("%d\n", res);
  return 0;
}
