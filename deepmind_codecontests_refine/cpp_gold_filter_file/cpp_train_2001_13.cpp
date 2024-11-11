#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int maxdp[27];
int dp[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string str;
  cin >> n >> str;
  for (int i = 0; i < n; ++i) {
    for (int c = 26; c > str[i] - 'a'; --c)
      maxdp[str[i] - 'a'] = max(maxdp[c] + 1, maxdp[str[i] - 'a']);
    dp[i] = maxdp[str[i] - 'a'];
  }
  cout << *max_element(dp, dp + n) << endl;
  for (int i = 0; i < n; ++i) {
    cout << dp[i] << " ";
  }
  return 0;
}
