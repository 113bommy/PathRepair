#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, k, p;
long long dp[N][N];
int a[N], b[N];
long long solve(int i, int j) {
  if (i == n) return 0;
  if (j == k) return 1e18;
  if (dp[i][j] != -1) return dp[i][j];
  dp[i][j] = 1e18;
  long long dis = p - b[j];
  long long dis2 = a[i] - b[j];
  if (dis < 0) dis *= -1;
  if (dis2 < 0) dis2 *= -1;
  long long cur = dis + dis2;
  return dp[i][j] = min(max(solve(i + 1, j + 1), cur), solve(i, j + 1));
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < k; i++) scanf("%d", &b[i]);
  sort(a, a + n);
  sort(b, b + k);
  cout << solve(0, 0) << endl;
  return 0;
}
