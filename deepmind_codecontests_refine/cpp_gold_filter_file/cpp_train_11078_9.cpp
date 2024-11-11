#include <bits/stdc++.h>
using namespace std;
int a[55];
int dp[55][505005];
int main() {
  cin.sync_with_stdio(0);
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 505005; j++) {
      if (dp[i][j]) {
        dp[i + 1][j] = 1;
        dp[i + 1][j + a[i]] = 1;
      }
    }
  }
  int ans = 0;
  int days = 0;
  while (true) {
    bool flag = false;
    int temp;
    for (int i = min(505005 - 1, ans + d); i > ans; i--) {
      if (dp[n][i]) {
        temp = i;
        flag = true;
        break;
      }
    }
    if (flag == false) break;
    ans = temp;
    days++;
  }
  cout << ans << " " << days << endl;
  return 0;
}
