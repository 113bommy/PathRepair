#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, cnt = 0, j, ans;
  vector<long long> dp(1, 2);
  while (dp[cnt] < 1000000000) {
    ++cnt;
    dp.push_back(dp[cnt - 1] + cnt + 2 * (cnt + 1));
  }
  cin >> t;
  for (i = 0; i < t; ++i) {
    ans = 0;
    cin >> n;
    for (j = (int)dp.size() - 1; j >= 0; --j)
      if (n >= dp[j]) {
        n -= dp[j];
        ++ans;
      }
    cout << ans << endl;
  }
  return 0;
}
