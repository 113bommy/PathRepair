#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string res1 = "";
  res1 += s[0];
  string res2 = "";
  int dp[n];
  dp[0] = 1;
  int flag = 0;
  for (int i = 1; i < n; i++) {
    if (res1.back() <= s[i]) {
      dp[i] = 0;
      res1 += s[i];
    } else if (res2 == "" || res2.back() <= s[i]) {
      dp[i] = 1;
      res2 += s[i];
    } else {
      flag = 1;
      break;
    }
  }
  if (flag) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  cout << "\n";
  for (int i = 0; i < n; i++) cout << dp[i];
  return 0;
}
