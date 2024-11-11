#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int dp[N];
int a[N];
bool check(int mid, int n, int m) {
  dp[0] = a[0];
  for (int i = 1; i < n; i++) {
    dp[i] = dp[i - 1];
    if (dp[i - 1] >= a[i] - mid - 1) dp[i] = max(dp[i], a[i]);
    if (dp[i - 1] >= a[i] - 1) dp[i] = max(dp[i], a[i] + mid);
    if (i >= 2 && dp[i - 2] >= a[i] - mid - 1)
      dp[i] = max(dp[i], a[i - 1] + mid);
  }
  if (dp[n - 1] >= min(m - 1, m - 1 + a[0] - mid)) {
    return true;
  }
  dp[1] = max(a[1], a[0] + mid);
  for (int i = 1; i < n; i++) {
    dp[i] = dp[i - 1];
    if (dp[i - 1] >= a[i] - mid - 1) dp[i] = max(dp[i], a[i]);
    if (dp[i - 1] >= a[i] - 1) dp[i] = max(dp[i], a[i] + mid);
    if (i >= 2 && dp[i - 2] >= a[i] - mid - 1)
      dp[i] = max(dp[i], a[i - 1] + mid);
  }
  if (dp[n - 1] >= min(m - 1, m - 1 + a[1] - mid)) {
    return true;
  }
  return false;
}
int main() {
  int n, m;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int pos = 0, dist = m + a[0] - a[n - 1];
  for (int i = 1; i < n; i++)
    if (dist < a[i] - a[i - 1]) dist = a[i] - a[i - 1], pos = i;
  for (int i = 0, j = a[pos]; i < n; i++) {
    a[i] -= j;
    if (a[i] < 0) a[i] += m;
  }
  sort(a, a + n);
  int lt = 0, rt = dist - 1, mid, ans = 0;
  while (lt <= rt) {
    mid = (lt + rt) >> 1;
    if (check(mid, n, m))
      ans = mid, rt = mid - 1;
    else
      lt = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
