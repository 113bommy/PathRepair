#include <bits/stdc++.h>
using namespace std;
int arr[100010], dp[100010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  int now = 1, ans = 1;
  dp[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1])
      dp[i] = ++now;
    else
      dp[i] = now = 1;
    ans = max(ans, dp[i] + 1);
  }
  now = 1;
  for (int i = 1; i < n; i++) {
    if (i < n - 1)
      if (arr[i - 1] + 1 < arr[i + 1]) ans = max(ans, now + dp[i + 1] + 1);
    ans = max(ans, now + 1);
    if (arr[i - 1] < arr[i])
      now++;
    else
      now = 1;
  }
  printf("%d", min(ans, n));
  return 0;
}
