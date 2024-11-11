#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int dp[N];
string s;
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    int sum = 0;
    for (int j = i; i - j <= 5 && j > -1; --j) {
      if (s[j] == '0' && i != j) continue;
      sum += s[i] - '0';
      if (sum % 3 == 0) {
        int add = (j > 0) ? dp[j - 1] : 0;
        dp[i] = max(dp[i], add + 1);
      }
    }
    if (i) dp[i] = max(dp[i], dp[i - 1]);
  }
  cout << dp[s.length() - 1] << endl;
  return 0;
}
