#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int memo[150][150][2805];
int a[155];
int dp(int idx, int take, int swap) {
  if (swap > k) return 160000000;
  if (take == m) return 0;
  if (idx >= n) return 160000000;
  if (memo[idx][take][swap] != -1)
    return memo[idx][take][swap];
  else {
    int ans = dp(idx + 1, take, swap);
    ans = min(ans, dp(idx + 1, take + 1, swap + (idx - take)) + a[idx]);
    memo[idx][take][swap] = ans;
    return ans;
  }
}
int main() {
  memset(memo, -1, sizeof(memo));
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int ans = dp(0, 0, 0);
  printf("%d\n", ans);
}
