#include <bits/stdc++.h>
using namespace std;
int n, d;
int val[30005];
int max_ = 30000;
int f = 250;
int dp[30005][800];
int fun(int pos, int step) {
  if (pos > max_) return 0;
  if (dp[pos][step + f] != -1) return dp[pos][step + f];
  dp[pos][step + f] = val[pos];
  int res = 0;
  res = max(res, fun(pos + d + step, step));
  if (d + step - 1 > 0) res = max(res, fun(pos + d + step - 1, step - 1));
  res = max(res, fun(pos + d + step + 1, step + 1));
  dp[pos][step + f] += res;
  return dp[pos][step + f];
}
int main() {
  cin >> n >> d;
  int x;
  for (int i = 0; i <= 30000; i++)
    for (int j = 0; j <= 600; j++) dp[i][j] = -1;
  for (int i = 0; i < n; i++) {
    cin >> x;
    val[x]++;
  }
  cout << fun(0, 0) << endl;
}
