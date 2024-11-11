#include <bits/stdc++.h>
using namespace std;
int a[300005], n, k, dp[300005];
bool f(int d) {
  int last = 0;
  for (int i = k; i <= n; ++i) {
    int j = dp[i - k];
    if (a[i] - a[j + 1] <= d) last = i;
    dp[i] = last;
  }
  return dp[n] == n;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int l = 0, r = a[n] - a[1], ans;
  while (l <= r) {
    int mid = l + r >> 1;
    if (f(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
