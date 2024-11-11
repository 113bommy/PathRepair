#include <bits/stdc++.h>
using namespace std;
int n;
int a[505];
int dp[505][505];
int solve(int l, int r) {
  if (l >= r) return 1;
  if (dp[l][r] != -1) return dp[l][r];
  dp[l][r] = 1e9;
  if (a[l] == a[r]) dp[l][r] = solve(l + 1, r - 1);
  for (int i = l + 1; i < r; i++)
    dp[l][r] = min(dp[l][r], solve(l, i) + solve(i + 1, r));
  return dp[l][r];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(1, n));
  return 0;
}
