#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
string s;
int a[55];
long long dp[55][10];
long long ans;
bool check;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  ans = 0;
  for (int i = 1; i <= 50; i++) {
    for (int j = 1; j <= 9; j++) dp[i][j] = 0;
  }
  for (int i = 0; i < s.length(); i++) a[i + 1] = char(s[i] - '0');
  for (int i = 0; i <= 9; i++) dp[1][i] = 1;
  int len = s.length();
  check = true;
  for (int i = 1; i < len; i++) {
    for (int j = 0; j <= 9; j++) {
      dp[i + 1][(j + a[i + 1]) / 2] += dp[i][j];
      if ((j + a[i + 1]) % 2 == 1)
        dp[i + 1][(j + a[i + 1]) / 2 + 1] += dp[i][j];
    }
  }
  for (int i = 2; i <= len; i++) {
    if (a[i - 1] == a[i] or a[i - 1] == a[i] + 1 or a[i - 1] == a[i] - 1)
      continue;
    check = false;
    break;
  }
  for (int i = 0; i <= 9; i++) ans += dp[len][i];
  if (check) ans--;
  cout << ans;
  return 0;
}
