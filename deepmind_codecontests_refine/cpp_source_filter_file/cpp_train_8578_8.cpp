#include <bits/stdc++.h>
using namespace std;
int n;
int aa[3005];
int bb[3005];
int cc[3005];
int dp[3005][2];
int solve(int index, bool prev) {
  int p = prev;
  if (dp[index][p] != -1) return dp[index][p];
  if (index == n) return 0;
  if (prev) {
    int ans = solve(index + 1, true) + bb[index];
    if (index != n - 1) ans = max(ans, solve(index + 1, false) + cc[index]);
    dp[index][p] = ans;
    return ans;
  }
  int ans = solve(index + 1, true) + aa[index];
  if (index != n - 1) ans = max(ans, solve(index + 1, false) + bb[index]);
  dp[index][p] = ans;
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int a = 0; a < n; a++) scanf("%d", &aa[a]);
  for (int a = 0; a < n; a++) scanf("%d", &bb[a]);
  for (int a = 0; a < n; a++) scanf("%d", &cc[a]);
  for (int a = 0; a < n; a++)
    for (int b = 0; b < 2; b++) dp[a][b] = -1;
  printf("%d\n", solve(25, false));
  return 0;
}
