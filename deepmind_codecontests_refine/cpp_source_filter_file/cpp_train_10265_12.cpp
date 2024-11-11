#include <bits/stdc++.h>
using namespace std;
int l[111], r[111];
char v[111][111];
int dp[111][111];
int n, m, low = INT_MAX;
int ans = INT_MAX;
void go(int lvl, int from, int cost) {
  if (lvl == low - 1) {
    ans = min(ans, cost);
    return;
  }
  if (from == 0) {
    go(lvl - 1, 0, cost + dp[lvl][0]);
    go(lvl - 1, 1, cost + dp[lvl][1]);
  } else {
    go(lvl - 1, 1, cost + dp[lvl][2]);
    go(lvl - 1, 0, cost + dp[lvl][3]);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int left = INT_MAX, right = -1;
    for (int j = 0; j < m + 2; j++) {
      scanf(" %c", &v[i][j]);
      if (v[i][j] == '1') {
        low = min(low, i);
        left = min(j, left);
        right = max(j, right);
      }
    }
    if (left == INT_MAX) left = -1;
    l[i] = left;
    r[i] = right;
  }
  if (low == INT_MAX) {
    printf("0\n");
    return 0;
  }
  for (int i = low + 1; i < n; i++) {
    if (l[i] == -1) {
      dp[i][0] = 0;
      dp[i][1] = 0;
      dp[i][2] = 0;
      dp[i][3] = 0;
      continue;
    }
    dp[i][0] = r[i] + r[i];
    dp[i][1] = m + 1;
    dp[i][2] = 2 * (m + 2 - (l[i] + 1));
    dp[i][3] = m + 1;
  }
  dp[low][0] = r[low];
  dp[low][1] = r[low];
  dp[low][2] = m + 1 - l[low];
  dp[low][3] = m + 1 - l[low];
  go(n - 1, 0, 0);
  printf("%d\n", ans + n - low - 1);
  return 0;
}
