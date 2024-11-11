#include <bits/stdc++.h>
using namespace std;
char s[1000002];
int pos[1000002], sum[1000002], cnt, n;
int dp[1000002];
bool check(int mid) {
  dp[0] = 0;
  for (int i = 1; i <= cnt; i++) {
    if (dp[i - 1] != -1) {
      if (sum[pos[i]] > sum[dp[i - 1]]) {
        if (pos[i] <= mid || sum[pos[i] - mid - 1] == sum[dp[i - 1]])
          dp[i] = pos[i];
        else
          dp[i] = -1;
      } else
        dp[i] = pos[i] + mid;
    } else
      dp[i] = -1;
    if (i > 1 && dp[i - 2] != -1) {
      if (pos[i] - pos[i - 1] < mid &&
          (pos[i] <= mid || sum[pos[i] - mid - 1] == sum[dp[i - 2]]))
        dp[i] = max(dp[i], pos[i - 1] + mid);
    }
    if (dp[i] > n) return true;
  }
  return dp[cnt] != -1 && sum[dp[cnt]] == sum[n];
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (s[i] == '*');
    if (s[i] == 'P') pos[++cnt] = i;
  }
  if (cnt == 1) {
    int c1 = sum[pos[1]], c2 = sum[n] - sum[pos[1]];
    int t1 = pos[1] - (lower_bound(sum + 1, sum + n + 1, 1) - sum);
    int t2 = lower_bound(sum + 1, sum + n + 1, sum[n]) - sum - pos[1];
    if (c1 < c2)
      printf("%d %d", c2, t2);
    else if (c1 > c2)
      printf("%d %d", c1, t1);
    else
      printf("%d %d", c1, min(t1, t2));
  } else {
    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%d %d", sum[n], l);
  }
}
