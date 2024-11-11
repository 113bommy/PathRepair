#include <bits/stdc++.h>
using namespace std;
int i, j, l, x, y, z, ans = 0, p, q, n;
double k;
int dp[103][300000], taste[300], calorie[300], diffrnce[300];
int answr(int pos, int diff) {
  if (pos >= n) {
    if (diff == 0)
      return 0;
    else
      return (-100000);
  }
  int p = -100, q = -100, r = 0, s = 0;
  if (dp[pos][diff] != -1) return dp[pos][diff];
  p = answr(pos + 1, diff);
  p = max(p, answr(pos + 1, diff + diffrnce[pos]) + taste[pos]);
  dp[pos][diff] = p;
  return dp[pos][diff];
}
int main() {
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  for (i = 0; i < n; i++) scanf("%d", &taste[i]);
  for (i = 0; i < n; i++) scanf("%d", &calorie[i]);
  for (i = 0; i < n; i++) {
    diffrnce[i] = k * calorie[i] - taste[i];
  }
  ans = answr(0, 0);
  if (ans <= 0) ans = -1;
  cout << ans;
  return 0;
}
