#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  vector<int> v(m);
  vector<int> dp(n);
  for (int i = 0; i < m; ++i) {
    cin >> v[i];
    dp[v[i] - 1] += 1;
    if (v[i] - 1 + str.size() < n) dp[v[i] - 1 + str.size()] -= 1;
    if (!i) continue;
    int cur = v[i];
    int pref = v[i - 1];
    int diff = cur - pref;
    if (diff < str.size() && str[0] != str[diff]) {
      cout << 0 << endl;
      return 0;
    }
  }
  long long ret = 1, inf = 1000000007;
  for (int i = 0; i < n; ++i) {
    if (i) dp[i] += dp[i - 1];
    int val = dp[i] > 0 ? 1 : 26;
    ret = (ret * val) % inf;
  }
  cout << ret << endl;
  return 0;
}
