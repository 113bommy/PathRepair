#include <bits/stdc++.h>
using namespace std;
int a[3005], b[3005];
int dp[3005][4];
int main() {
  int n;
  int sum;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
      dp[i][1] = b[i];
    }
    for (int i = 1; i <= n; i++) {
      dp[i][2] = 99999999;
      dp[i][3] = 99999999;
      for (int j = 1; j < i; j++) {
        if (a[i] > a[j]) {
          dp[i][2] = min(dp[j][1] + b[i], dp[i][2]);
          dp[i][3] = min(dp[j][2] + b[i], dp[i][3]);
        }
      }
    }
    sum = 99999999;
    for (int i = 3; i <= n; i++) {
      if (dp[i][3] == 99999999) continue;
      sum = min(sum, dp[i][3]);
    }
    if (sum == 99999999)
      cout << "-1" << endl;
    else
      cout << sum << endl;
  }
  return 0;
}
