#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1e5;
long long int bs(long long int val, vector<long long int>& v) {
  long long int ans = -1;
  long long int l = 0, r = v.size() - 1;
  while (l <= r) {
    long long int m = (l + r) / 2;
    if (v[m] >= val) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}
void runcases(long long int T) {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long int dp[n];
  memset(dp, 0, sizeof(dp));
  dp[0] = 20;
  for (long long int i = 1; i < n; i++) {
    long long int ans1 = dp[i - 1] + 20;
    long long int val1 = v[i] - 89;
    long long int val2 = v[i] - 1339;
    long long int idx1 = bs(val1, v);
    long long int idx2 = bs(val2, v);
    long long int ans2 = ((idx1 - 1 >= 0) ? dp[idx1 - 1] : 0) + 50;
    long long int ans3 = ((idx2 - 1 >= 0) ? dp[idx2 - 1] : 0) + 120;
    ans1 = min({ans1, ans2, ans3});
    dp[i] = ans1;
  }
  long long int sum = 0;
  cout << dp[0] << " "
       << "\n";
  for (long long int i = 1; i < n; i++) {
    cout << (dp[i] - dp[i - 1]) << " "
         << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  for (long long int t = 1; t <= T; t++) {
    runcases(t);
  }
  return 0;
}
