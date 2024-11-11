#include <bits/stdc++.h>
using namespace std;
const double eps = 1.0e-11;
const double pi = acos(-1.0);
int main() {
  string s;
  cin >> s;
  vector<int> dp((int)(s).size(), 1);
  int res = 0;
  for (long long i = 0; i < (int)(s).size(); i++) {
    for (long long j = 0; j < i; j++)
      if (s[i] == s[j] && (i - j) % 2)
        dp[i] = max(dp[i], dp[j] + 1), res = max(res, dp[i]);
  }
  cout << res << endl;
  return 0;
}
