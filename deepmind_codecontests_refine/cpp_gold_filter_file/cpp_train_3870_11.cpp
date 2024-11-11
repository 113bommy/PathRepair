#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  const int let_count = 26;
  int n;
  long long left;
  cin >> n >> left;
  vector<long long> x(n);
  for (int i = 0; i < n; i++) {
    char a;
    cin >> a;
    x[i] = (int)a - (int)'a';
  }
  vector<vector<long long> > dp(n + 1);
  dp[0].resize(n, 1);
  for (int i = 0; i < n; i++) dp[0][i] = 1;
  for (long long length = 1; length <= n; length++) {
    vector<long long> char_ans(let_count, 0);
    dp[length].resize(n);
    for (int i = 0; i < length - 1; i++) dp[length][i] = 0;
    dp[length][length - 1] = 1;
    char_ans[x[length - 1]] = 1;
    for (long long i = length; i < n; i++) {
      dp[length][i] =
          dp[length][i - 1] + dp[length - 1][i - 1] - char_ans[x[i]];
      char_ans[x[i]] = dp[length - 1][i - 1];
    }
  }
  long long ans = 0;
  for (long long length = n; length >= 0 && left > 0; length--) {
    long long cur = min(left, dp[length].back());
    ans += cur * (n - length);
    left -= cur;
  }
  if (left == 0)
    cout << ans << endl;
  else
    cout << -1 << endl;
}
