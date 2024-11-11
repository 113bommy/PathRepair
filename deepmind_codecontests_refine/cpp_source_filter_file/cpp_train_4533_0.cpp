#include <bits/stdc++.h>
using namespace std;
int dp[21][(1 << 20)];
char s[101000];
int col[(1 << 20)];
int n, m;
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; ++i) {
    scanf("%s", s);
    for (j = 0; j < m; ++j) col[j] |= ((s[j] - '0') << j);
  }
  for (i = 0; i < m; ++i) dp[0][col[i]]++;
  for (k = 1; k <= n; ++k) {
    int sum;
    for (int mask = 0; mask < (1 << n); ++mask) {
      sum = k > 1 ? dp[k - 2][mask] * (k - 2 - n) : 0;
      for (int p = 0; p < n; ++p) {
        sum += dp[k - 1][mask ^ (1 << p)];
      }
      dp[k][mask] = sum / k;
    }
  }
  int ans = n * m;
  for (i = 0; i < (1 << n); ++i) {
    int sum = 0;
    for (j = 0; j <= n; ++j) sum += min(j, n - j) * dp[j][i];
    ans = min(sum, ans);
  }
  printf("%d\n", ans);
  return 0;
}
