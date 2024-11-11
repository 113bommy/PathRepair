#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int n = s.length();
    vector<long long> dp(n);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (!dp[i + 1]) {
        dp[i] = s[i] == 'A' ? a : b;
      } else {
        if (s[i] == s[i + 1]) {
          dp[i] = dp[i + 1];
        } else {
          dp[i] = dp[i + 1] + (s[i] == 'A' ? a : b);
        }
      }
    }
    int L = 0, R = n - 1;
    while (L < R) {
      int m = (L + R) / 2;
      if (dp[m] <= p)
        R = m;
      else
        L = m + 1;
    }
    cout << L + 1 << endl;
  }
  return 0;
}
