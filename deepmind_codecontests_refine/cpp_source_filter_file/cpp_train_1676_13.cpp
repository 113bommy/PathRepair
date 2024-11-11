#include <bits/stdc++.h>
using namespace std;
int o, dp[2][20005], dp2[2][20005], o2, x[20005], y[20005], mo, n, m, mid, c,
    cur;
bitset<20005> pre[10005];
void print(int x, int y, bool t = false) {
  if (x == 0 && y == 0 || t && x == 0 && y == c) return;
  if (pre[x][y] || x == 0)
    print(x, y - 1, t), putchar('S');
  else
    print(x - 1, y, t), putchar('C');
}
int main() {
  scanf("%d%d%d", &n, &m, &mo);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < m; i++) scanf("%d", &y[i]);
  mid = n >> 1;
  for (int i = 0; i <= mid; i++) {
    o ^= 1;
    for (int j = 0; j < m; j++) {
      dp[o][j] = 0;
      if (j > 0) dp[o][j] = dp[o][j - 1], pre[i][j] = 1;
      if (i > 0 && dp[o ^ 1][j] >= dp[o][j])
        dp[o][j] = dp[o ^ 1][j], pre[i][j] = 0;
      dp[o][j] += ((x[i] + y[j]) % mo);
    }
  }
  for (int i = n - 1; i >= mid; i--) {
    o2 ^= 1;
    for (int j = m - 1; j >= 0; j--) {
      dp2[o2][j] = 0;
      if (j < m - 1) dp2[o2][j] = dp2[o2][j + 1];
      if (i < n - 1 && dp2[o2 ^ 1][j] >= dp2[o2][j])
        dp2[o2][j] = dp2[o2 ^ 1][j];
      dp2[o2][j] += ((x[i] + y[j]) % mo);
    }
  }
  cur = dp2[o2][0] + dp[o][0] - ((x[mid] + y[0]) % mo);
  for (int i = 1; i < m; i++)
    if (dp2[o2][i] + dp[o][i] - ((x[mid] + y[i]) % mo) > cur) {
      cur = dp2[o2][i] + dp[o][i] - ((x[mid] + y[i]) % mo);
      c = i;
    }
  printf("%d\n", cur);
  print(mid, c);
  for (int i = mid + 1; i < n; i++) {
    o ^= 1;
    for (int j = 0; j < m; j++) {
      dp[o][j] = 0;
      if (j > 0) dp[o][j] = dp[o][j - 1], pre[i - mid][j] = 1;
      if (i > 0 && dp[o ^ 1][j] >= dp[o][j])
        dp[o][j] = dp[o ^ 1][j], pre[i - mid][j] = 0;
      dp[o][j] += ((x[i] + y[j]) % mo);
    }
  }
  print(n - mid - 1, m - 1, true);
  return 0;
}
