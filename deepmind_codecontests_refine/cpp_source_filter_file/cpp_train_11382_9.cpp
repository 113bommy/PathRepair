#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int main() {
  string a, b;
  cin >> a >> b;
  int mn = 0;
  for (int j = 1; j < a.length(); ++j) {
    for (int i = 1; i < b.length(); ++i) {
      char x = a[i - 1], y = b[j - 1];
      if (x == y)
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = dp[i - 1][j - 1];
      mn = max(dp[i][j], mn);
    }
  }
  cout << b.length() - mn << endl;
}
