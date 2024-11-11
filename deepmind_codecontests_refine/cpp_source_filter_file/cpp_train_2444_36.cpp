#include <bits/stdc++.h>
using namespace std;
char ch, arr[60][60];
int count, beginr, beginc, n, m, dp[60][60];
bool func(int i, int j, int temp) {
  if (i >= 0 && i < ::n && j >= 0 && j < ::m) {
    if (dp[i][j] == 1)
      return false;
    else if (dp[i][j] == 0 && (i != beginr || j != beginc))
      dp[i][j] = 1;
  }
  if (i >= ::n || i < 0)
    return false;
  else if (j >= ::m || j < 0)
    return false;
  else if (arr[i][j] != ::ch)
    return false;
  else if (i == ::beginr && j == ::beginc && temp > 2)
    return true;
  else if (i == ::beginr && j == ::beginc && temp == 2)
    return false;
  else {
    if (func(i + 1, j, temp + 1) || func(i, j + 1, temp + 1) ||
        func(i - 1, j, temp + 1) || func(i, j - 1, temp + 1)) {
      ::count++;
      return true;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> ::n >> ::m;
  for (int i = 0; i < ::n; i++) {
    for (int j = 0; j < ::m; j++) cin >> arr[i][j];
  }
  for (int i = 0; i < ::n; i++) {
    for (int j = 0; j < ::m; j++) {
      memset(dp, 0, sizeof(dp));
      ::count = 0;
      ::ch = arr[i][j];
      ::beginr = i;
      ::beginc = j;
      if (func(i, j, 0)) {
        if (::count >= 4) {
          cout << "YES";
          return 0;
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
