#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, l, r;
  string s;
  getline(cin >> ws, s);
  int dp[s.length() + 1];
  dp[0] = 0;
  for (int i = 1; i < s.length(); i++) {
    if (s[i - 1] == s[i]) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = dp[i - 1];
    }
  }
  cin >> n;
  while (n--) {
    int cnt = 0;
    cin >> l >> r;
    cout << dp[r - 1] - dp[l - 1] << endl;
  }
  return 0;
}
