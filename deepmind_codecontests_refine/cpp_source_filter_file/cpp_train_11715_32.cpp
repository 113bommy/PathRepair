#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int m = s.size();
  s = " " + s;
  vector<int> last(k, -1);
  vector<int> dp(n + m + 1), sum(n + m + 1);
  dp[0] = sum[0] = 1;
  for (int i = 1; i <= m + n; ++i) {
    if (i >= m) {
      int min_last = -1;
      for (int j = 0; j < k; ++j) {
        if (min_last == -1 || last[j] < last[min_last]) {
          min_last = j;
        }
      }
      s += char(min_last + 'a');
    }
    dp[i] = (sum[i - 1] -
             (last[s[i] - 'a'] > 0 ? sum[last[s[i] - 'a'] - 1] : 0) + MOD) %
            MOD;
    sum[i] = (sum[i - 1] + dp[i]) % MOD;
    last[s[i] - 'a'] = i;
  }
  cout << sum[n + m] << endl;
  return 0;
}
