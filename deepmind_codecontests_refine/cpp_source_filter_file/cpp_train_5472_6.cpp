#include <bits/stdc++.h>
using namespace std;
int n;
int a[4000 + 5];
long long sum[4000 + 5], dp[30000000 + 5];
inline long long get_sum(int l, int r) { return sum[r] - sum[l - 1]; }
inline int get_hash(int l, int r, int k, int type) {
  return (((1ll * l * 4000 + r) * 100 + k) * 2 + type) % 19260817;
}
long long dfs(int l, int r, int k, int type) {
  if (r - l + 1 < k) return 0;
  if (r - l + 1 == k) {
    if (type == 1)
      return -get_sum(l, r);
    else
      return get_sum(l, r);
  }
  int hs = get_hash(l, r, k, type);
  if (dp[hs] != -1) return dp[hs];
  if (type == 0) {
    long long s1, s2;
    s1 = dfs(l + k, r, k, 1) + get_sum(l, l + k - 1);
    if (l + k <= r) s2 = dfs(l + k + 1, r, k + 1, 1) + get_sum(l, l + k);
    dp[hs] = max(s1, s2);
  } else {
    long long s1, s2;
    s1 = dfs(l, r - k, k, 0) - get_sum(r - k + 1, r);
    if (l + k <= r) s2 = dfs(l, r - k - 1, k + 1, 0) - get_sum(r - k, r);
    dp[hs] = min(s1, s2);
  }
  return dp[hs];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  memset(dp, -1, sizeof(dp));
  printf("%I64d\n", dfs(1, n, 1, 0));
}
