#include <bits/stdc++.h>
using namespace std;
int c, d, n, k, m, ans, dp[10005];
vector<int> v;
int solve(int left) {
  if (left <= 0) return 0;
  if (dp[left] != -1) return dp[left];
  return dp[left] = min(c + solve(left - n), d + solve(left - 1));
}
int main() {
  scanf("%d %d", &c, &d);
  scanf("%d %d", &n, &m);
  scanf("%d", &k);
  int hm = n * m - k;
  for (int i = 0; i <= hm; i++) dp[i] = -1;
  ans = solve(hm);
  printf("%d\n", ans);
  return 0;
}
