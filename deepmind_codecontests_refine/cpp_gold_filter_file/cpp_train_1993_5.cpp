#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000;
int a[maxn + 5], q[maxn + 5];
int dp[maxn + 5][maxn + 5];
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int l = 0, r = 0;
  while (l < n) {
    while (r < n && a[r] - a[l] <= 5) r++;
    r--;
    q[l] = r;
    l++;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + 1 <= k)
        dp[q[i] + 1][j + 1] = max(dp[q[i] + 1][j + 1], dp[i][j] + q[i] - i + 1);
    }
  printf("%d\n", dp[n][k]);
}
