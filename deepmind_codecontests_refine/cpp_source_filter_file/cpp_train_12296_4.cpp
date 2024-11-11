#include <bits/stdc++.h>
using namespace std;
int arr[51];
int n, m, k;
int dp[51][2001];
string s;
int solve(int idx, int reminder) {
  if (reminder <= 0) return 0;
  int &ret = dp[idx][reminder];
  if (ret != -1) return ret;
  ret = 100000000;
  for (int i = 1; i <= n; i++) {
    if (arr[i] > arr[idx] && s[i] != s[idx]) {
      ret = min(ret, solve(i, reminder - arr[i]) + abs(i - idx));
    }
  }
  return ret;
}
int main() {
  for (int i = 1; i <= 50; i++)
    for (int j = 1; j <= 2000; j++) dp[i][j] = -1;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  cin >> s;
  int ans = 100000000;
  for (int i = 1; i <= n; i++) {
    ans = min(solve(i, k - arr[i]) + abs(m - i), ans);
  }
  if (ans == 100000000) ans = -1;
  cout << ans;
  return 0;
}
