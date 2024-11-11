#include <bits/stdc++.h>
using namespace std;
int power(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y / 2, x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
int k;
string s;
int minchange[501][501];
int dp[505][505];
int n;
string ans = "";
int tot;
string fuck[501][501];
int func(int index, int done) {
  if (index == n) {
    if (done <= k) return dp[index][done] = 0;
    return dp[index][done] = 1e18;
  }
  int &ret = dp[index][done];
  if (ret != -1) return ret;
  ret = 1e18;
  int i;
  for (i = 1; i <= n; i++) {
    if (index + i > n) break;
    ret = min(ret, func(index + i, done + 1) + minchange[index][index + i - 1]);
  }
  return ret;
}
void sad(int index, int done, int taken) {
  if (index == n) return;
  int i;
  for (i = index; i < n; i++) {
    if (dp[i + 1][done + 1] + minchange[index][i] == tot - taken) {
      ans += fuck[index][i];
      ans += '+';
      sad(i + 1, done + 1, taken + minchange[index][i]);
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> k;
  memset(dp, -1, sizeof(dp));
  n = s.length();
  int i, j, k;
  for (i = 0; i < n; i++) fuck[i][i] = s[i];
  for (i = 0; i <= 500; i++) minchange[i][i] = 0;
  for (i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1])
      minchange[i][i + 1] = 0;
    else
      minchange[i][i + 1] = 1;
    fuck[i][i + 1].push_back(s[i]);
    fuck[i][i + 1].push_back(s[i]);
  }
  for (i = 2; i < n; i++) {
    for (j = 0; j + i < n; j++) {
      minchange[j][j + i] = minchange[j + 1][j + i - 1];
      if (s[j] != s[j + i]) {
        minchange[j][j + i]++;
      }
      fuck[j][j + i] = s[j] + fuck[j + 1][j + i - 1] + s[j];
    }
  }
  cout << func(0, 0) << "\n";
  tot = dp[0][0];
  sad(0, 0, 0);
  for (i = 0; i < ans.length() - 1; i++) cout << ans[i];
}
