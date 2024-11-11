#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  string str;
  cin >> n >> m >> str;
  vector<int> v(m), dp(n + m);
  for (int i = 0; i < m; ++i) {
    cin >> v[i];
    dp[v[i] - 1] += 1;
    dp[v[i] - 1 + str.size()] -= 1;
    if (!i) continue;
    int d = v[i] - v[i - 1];
    if (d < str.size() && str[0] != str[d]) {
      cout << 0 << endl;
      return 0;
    }
  }
  int ret = 1, mod = 1000000007;
  for (int i = 0; i < n; ++i) {
    if (i) dp[i] += dp[i - 1];
    int val = dp[i] > 0 ? 1 : 26;
    ret = (ret * val) % mod;
  }
  cout << ret << endl;
  return 0;
}
