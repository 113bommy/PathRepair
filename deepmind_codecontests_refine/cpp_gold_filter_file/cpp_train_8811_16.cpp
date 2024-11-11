#include <bits/stdc++.h>
using namespace std;
const int N = 100010, K = 110;
int n, k, l[N], r[N], dp[N][2], seg[4 * N][2];
int build(int s, int e, int idx, int cur) {
  if (s == e) return seg[idx][cur] = dp[s][cur];
  return seg[idx][cur] = min(build(s, (s + e) / 2, idx * 2, cur),
                             build((s + e) / 2 + 1, e, idx * 2 + 1, cur));
}
int getmin(int s, int e, int idx, int l, int r, int cur) {
  if (s > r || e < l) return 2000000000;
  if (s >= l && e <= r) return seg[idx][cur];
  return min(getmin(s, (s + e) / 2, idx * 2, l, r, cur),
             getmin((s + e) / 2 + 1, e, idx * 2 + 1, l, r, cur));
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &l[i], &r[i]);
  }
  r[k] = l[k] = 2 * n;
  for (int i = 0; i < n; i++) {
    dp[i][1] = dp[i][0] = 2000000000;
  }
  for (int i = k - 1; i >= 0; i--) {
    build(0, n, 1, 0);
    build(0, n, 1, 1);
    for (int j = 0; j <= n; j++) {
      dp[j][0] = dp[j][1] = 2000000000;
      dp[j][0] = getmin(0, n, 1, j, j, 0);
      if (j + l[i + 1] - r[i] <= n)
        dp[j][0] = min(dp[j][0], getmin(0, n, 1, j + l[i + 1] - r[i],
                                        min(n, j + l[i + 1] - l[i]), 1) +
                                     1);
      dp[j][0] =
          min(dp[j][0], getmin(0, n, 1, j, min(n, j + r[i] - l[i]), 0) + 2);
      if (l[i + 1] - l[i] + j <= n)
        dp[j][1] = getmin(0, n, 1, l[i + 1] - l[i] + j, l[i + 1] - l[i] + j, 1);
      dp[j][1] =
          min(dp[j][1], getmin(0, n, 1, j, min(j + r[i] - l[i], n), 0) + 1);
      if (j + l[i + 1] - r[i] <= n)
        dp[j][1] = min(dp[j][1], getmin(0, n, 1, j + l[i + 1] - r[i],
                                        min(n, j + l[i + 1] - l[i]), 1) +
                                     2);
    }
  }
  int cur = dp[0][0];
  if (cur >= 2000000000)
    puts("Hungry");
  else
    printf("Full\n%d\n", cur);
  return 0;
}
