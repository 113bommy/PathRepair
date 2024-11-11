#include <bits/stdc++.h>
using namespace std;
const int N = 5010, mod = int(1e9) + 7;
int dp[N][N];
int n, a[N];
int mx[N * 20], sm[20], ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int y = 0; y <= n; y++) {
    memset(sm, 0, sizeof(sm));
    for (int i = 1; i <= n; i++) {
      mx[a[i]] = 0;
      mx[a[i] - 1] = 0;
      mx[a[i] + 1] = 0;
    }
    for (int x = 0; x < y; x++) {
      mx[a[x]] = max(mx[a[x]], dp[y][x]);
      sm[a[x] % 7] = max(sm[a[x] % 7], dp[y][x]);
    }
    for (int x = y + 1; x <= n; x++) {
      dp[x][y] = max(sm[a[x] % 7], max(mx[a[x] - 1], mx[a[x] + 1]));
      dp[x][y] = max(dp[x][y], dp[y][0]) + 1;
      mx[a[x]] = max(mx[a[x]], dp[x][y]);
      sm[a[x] % 7] = max(sm[a[x] % 7], dp[x][y]);
      ans = max(ans, dp[x][y]);
    }
  }
  printf("%d", ans);
  return 0;
}
