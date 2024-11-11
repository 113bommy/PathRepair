#include <bits/stdc++.h>
using namespace std;
char s[25][25];
int mask[25][25], cost[25][25], dp[1 << 20], a[25][25];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int mx = 0;
      for (int k = 0; k < n; k++) {
        if (s[i][j] == s[k][j]) {
          cost[i][j] += a[k][j];
          mask[i][j] |= (1 << k);
          mx = max(mx, a[k][j]);
        }
      }
      cost[i][j] -= mx;
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i < 1 << n; i++) {
    int lowbit = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        lowbit = j;
        break;
      }
    }
    for (int j = 0; j < m; j++) {
      dp[i] = min(dp[i], dp[i ^ (1 << lowbit)] + a[lowbit][j]);
      dp[i] = min(dp[i], dp[i & (i ^ mask[lowbit][j])] + cost[lowbit][j]);
    }
  }
  printf("%d\n", dp[(1 << n) - 1]);
  return 0;
}
