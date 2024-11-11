#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const long long MAX = 1e18;
string s, t;
long long tc, n, dp[N][N], suff1[26][N], suff2[26][N];
long long solve(int i, int j) {
  if (!j) return 0;
  if (~dp[i][j]) return dp[i][j];
  long long ans = MAX;
  if (i)
    ans = min(solve(i - 1, j),
              (s[i - 1] == t[j - 1] ? solve(i - 1, j - 1) : ans));
  if (suff1[t[j - 1] - 'a'][i + 1] > suff2[t[j - 1] - 'a'][j + 1])
    ans = min(ans, solve(i, j - 1) + 1);
  return dp[i][j] = ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> n >> s >> t;
    for (int i = 0; i < n + 5; ++i)
      for (int j = 0; j < n + 5; ++j) dp[i][j] = -1;
    for (int i = 0; i < 26; ++i)
      for (int j = 0; j <= n; ++j) suff1[i][j] = suff2[i][j] = 0;
    for (int i = 0; i < 26; ++i)
      for (int j = n - 1; j >= 0; --j)
        suff1[i][j] = suff1[i][j + 1] + (s[j] - 'a' == i),
        suff2[i][j] = suff2[i][j + 1] + (t[j] - 'a' == i);
    long long ans = solve(n, n);
    cout << (ans >= MAX ? -1 : ans) << '\n';
  }
  return 0;
}
