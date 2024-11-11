#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 6e18 + 100;
const int maxn = 3e6 + 7;
int dp[3003][3003];
string s, t;
long long add(long long a, long long b) { return (a + b) % mod; }
long long mul(long long a, long long b) { return (a * b) % mod; }
long long DP(int l, int r, int id) {
  if (l == r && (l >= t.size() || s[id] == t[l])) {
    return 2;
  }
  if (dp[l][r] != -1) return dp[l][r];
  long long ret = 0;
  if (l >= t.size() || s[id] == t[l]) ret = add(ret, DP(l + 1, r, id - 1));
  if (r >= t.size() || s[id] == t[r]) ret = add(ret, DP(l, r - 1, id - 1));
  return dp[l][r] = ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> s >> t;
  long long ans = 0;
  memset(dp, -1, sizeof(dp));
  for (int i = t.size() - 1; i < s.size(); i++) {
    ans = add(ans, DP(0, i, i));
  }
  cout << ans << endl;
  return 0;
}
