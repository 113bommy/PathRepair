#include <bits/stdc++.h>
using namespace std;
int n, l, k;
double prob[200];
int cap[200];
double dp[200][200][451];
double solve(int ind, int won, int remCap) {
  if (ind == n)
    if (won >= l && remCap >= 0)
      return 1.0;
    else
      return 0.0;
  if (remCap >= 200) {
    if (dp[ind][won][451] >= 0) return dp[ind][won][451];
  } else if (dp[ind][won][remCap + 200] >= 0)
    return dp[ind][won][remCap + 200];
  double win = solve(ind + 1, won + 1, remCap + cap[ind]) * prob[ind];
  double lose = solve(ind + 1, won, remCap) * (1 - prob[ind]);
  if (remCap >= 200)
    return dp[ind][won][451] = win + lose;
  else
    return dp[ind][won][remCap + 200] = win + lose;
}
int main() {
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    cin >> prob[i];
    prob[i] /= 100;
  }
  for (int i = 0; i < n; i++) cin >> cap[i];
  for (int i = 0; i < 200; i++)
    for (int j = 0; j < 200; j++)
      for (int k = 0; k < 451; k++) dp[i][j][k] = -1;
  printf("%0.12lf", solve(0, 0, k));
  return 0;
}
