#include <bits/stdc++.h>
int last[100001], next[100001], max[100001], input[100001], sum[100001],
    rec[100001];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &input[i]);
  for (int i = 1; i <= n; i++) {
    int color = input[i];
    if (input[i] != input[i - 1]) {
      next[last[color]] = i;
      last[color] = i;
    }
    sum[color]++;
    rec[i] = sum[color];
  }
  for (int i = 0; i <= m; i++) last[i] = 0;
  for (int i = 1; i <= n; i++)
    if (last[input[i]] == 0) last[input[i]] = i;
  for (int i = 1; i <= n; i++) {
    int color = input[i];
    int same_color;
    while (true) {
      int total_color = i - last[color] + 1;
      same_color = rec[i] - rec[last[color]] + 1;
      int dis = total_color - same_color;
      if (dis <= k) break;
      last[color] = next[last[color]];
    }
    if (same_color > max[color]) max[color] = same_color;
  }
  int ans = 0;
  for (int i = 1; i <= m; i++)
    if (max[i] > ans) ans = max[i];
  printf("%d\n", ans);
  return 0;
}
