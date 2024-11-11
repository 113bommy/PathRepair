#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5;
int n, dp[mxN], occur[26];
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for (int i = n - 1; ~i; --i) {
    int cd = 1;
    for (int j = 0; j < s[i] - 'a'; ++j) cd = max(cd, occur[j] + 1);
    dp[i] = cd;
    occur[s[i] - 'a'] = cd;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
  for (int i = 0; i < n; ++i) cout << dp[i] << " ";
}
