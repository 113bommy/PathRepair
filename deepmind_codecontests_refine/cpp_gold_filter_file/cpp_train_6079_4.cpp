#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int dp[s.size() + 1];
  dp[0] = 0;
  for (int i = 0, sum; i < s.size() - 1; i++) {
    sum = (s[i] == s[i + 1]) ? 1 : 0;
    dp[i + 1] = sum + dp[i];
  }
  dp[s.size()] = dp[s.size() - 1];
  if (false) {
    for (int i = 1; i <= s.size(); i++) cout << dp[i] << " ";
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    int i, j;
    cin >> i >> j;
    cout << (dp[j - 1] - dp[i - 1]) << endl;
  }
}
