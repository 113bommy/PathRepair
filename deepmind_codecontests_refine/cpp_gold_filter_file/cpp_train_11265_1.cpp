#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int a[N];
int dp[N][3];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[1][0] = dp[1][1] = 1;
  if (a[1] < a[2])
    dp[2][1] = 2;
  else
    dp[2][1] = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] < a[i])
      dp[i][0] = dp[i - 1][0] + 1;
    else
      dp[i][0] = 1;
  }
  for (int i = 3; i <= n; i++) {
    dp[i][1] = 1;
    if (a[i - 1] < a[i]) {
      dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
    }
    if (a[i - 2] < a[i]) {
      dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
    }
  }
  int maxn = -1;
  for (int i = 1; i <= n; i++) {
    maxn = max(maxn, dp[i][1]);
  }
  cout << maxn;
}
