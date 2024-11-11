#include <bits/stdc++.h>
using namespace std;
int dp[1 << 20 + 5];
char s[25][25];
int sameCost[25][25], same[25][25], a[25][25], n, m;
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
          sameCost[i][j] += a[k][j];
          mx = max(mx, a[k][j]);
          same[i][j] |= (1 << k);
        }
      }
      sameCost[i][j] -= mx;
    }
  }
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0] = 0;
  for (int S = 0; S < (1 << n); S++) {
    for (int i = 0; i < n; i++) {
      if ((S & (1 << i)) == 0) {
        for (int j = 0; j < m; j++) {
          dp[S | (1 << j)] = min(dp[S | (1 << j)], dp[S] + a[i][j]);
          dp[S | same[i][j]] = min(dp[S | same[i][j]], dp[S] + sameCost[i][j]);
        }
        break;
      }
    }
  }
  printf("%d\n", dp[(1 << n) - 1]);
  return 0;
}
