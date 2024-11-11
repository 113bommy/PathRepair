#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010];
int i, j;
int ii, jj;
int dp[1010][1010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << a[0] << endl;
    cout << 1 << endl;
    return 0;
  }
  memset(dp, 0x3f, sizeof(dp));
  i = n;
  dp[i][i] = min(dp[i][i], 0);
  for (j = 0; j < i; j++) dp[i][j] = min(dp[i][j], a[j]);
  i = n - 1;
  dp[i][i] = min(dp[i][i], a[i]);
  for (j = 0; j < i; j++) dp[i][j] = min(dp[i][j], max(a[i], a[j]));
  i = n - 2;
  dp[i][i] = min(dp[i][i], max(a[i], a[i + 1]));
  for (i = n - 2; i >= 0; i--) {
    if (i < n - 2) {
      dp[i][i] = min(dp[i][i], max(a[i], a[i + 1]) + dp[i + 3][i + 2]);
      dp[i][i] = min(dp[i][i], max(a[i], a[i + 2]) + dp[i + 3][i + 1]);
      dp[i][i] = min(dp[i][i], max(a[i + 1], a[i + 2]) + dp[i + 3][i]);
    }
    for (j = 0; j < i; j++) {
      dp[i][j] = min(dp[i][j], max(a[i], a[i + 1]) + dp[i + 2][j]);
      dp[i][j] = min(dp[i][j], max(a[i], a[j]) + dp[i + 2][i + 1]);
      dp[i][j] = min(dp[i][j], max(a[i + 1], a[j]) + dp[i + 2][i]);
    }
  }
  cout << dp[0][0] << endl;
  i = 0, j = 0;
  while (1)
    if (i == n) {
      if (i == j)
        break;
      else {
        cout << j + 1 << endl;
        break;
      }
    } else if (i == n - 1) {
      if (i == j) {
        cout << i + 1 << endl;
        break;
      } else {
        cout << i + 1 << ' ' << j + 1 << endl;
        break;
      }
    } else if (i == n - 2 && i == j) {
      cout << i + 1 << ' ' << i + 2 << endl;
      break;
    } else {
      if (i == j) {
        if (0) {
        } else if (dp[i][i] == (max(a[i], a[i + 1]) + dp[i + 3][i + 2])) {
          cout << i + 1 << ' ' << i + 2 << endl;
          ii = i + 3;
          jj = i + 2;
        } else if (dp[i][i] == (max(a[i], a[i + 2]) + dp[i + 3][i + 1])) {
          cout << i + 1 << ' ' << i + 3 << endl;
          ii = i + 3;
          jj = i + 1;
        } else if (dp[i][i] == (max(a[i + 1], a[i + 2]) + dp[i + 3][i])) {
          cout << i + 2 << ' ' << i + 3 << endl;
          ii = i + 3;
          jj = i;
        }
      } else {
        if (0) {
        } else if (dp[i][j] == (max(a[i], a[i + 1]) + dp[i + 2][j])) {
          cout << i + 1 << ' ' << i + 2 << endl;
          ii = i + 2;
          jj = j;
        } else if (dp[i][j] == (max(a[i], a[j]) + dp[i + 2][i + 1])) {
          cout << i + 2 << ' ' << j + 1 << endl;
          ii = i + 2;
          jj = i + 1;
        } else if (dp[i][j] == (max(a[i + 1], a[j]) + dp[i + 2][i])) {
          cout << i + 2 << ' ' << j + 1 << endl;
          ii = i + 2;
          jj = i;
        }
      }
      i = ii;
      j = jj;
    }
  return 0;
}
