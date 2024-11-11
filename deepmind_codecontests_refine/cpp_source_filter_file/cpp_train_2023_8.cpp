#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, A = 1e6 + 2;
int add(int x, int y) { return ((x + y) % mod + mod) % mod; }
string s;
int n, dp[A][5][2];
int solve(int ind, int type, bool f = 0) {
  if (s[ind] != '?') {
    if (type == 0 && s[ind] != '0') return 0;
    if (type == 1 && s[ind] != '1') return 0;
    if (type == 2 && s[ind] != '2') return 0;
    if (type == 3 && s[ind] != '3') return 0;
  }
  if (ind + 1 == n) {
    if ((type == 1 && f == 1) || type == 2) return 0;
    return 1;
  }
  if (~dp[ind][type][f]) return dp[ind][type][f];
  int val = 0;
  if (type == 0) {
    val = add(val, solve(ind + 1, 0));
    val = add(val, solve(ind + 1, 1, 1));
  }
  if (type == 1) {
    if (f)
      val = add(val, solve(ind + 1, 3));
    else {
      val = add(val, solve(ind + 1, 0));
      val = add(val, solve(ind + 1, 1, 1));
    }
  }
  if (type == 2) val = add(val, solve(ind + 1, 3));
  if (type == 3) {
    val = add(val, solve(ind + 1, 1));
    val = add(val, solve(ind + 1, 2));
    val = add(val, solve(ind + 1, 3));
  }
  return dp[ind][type][f] = val;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s;
  n = s.size();
  memset(dp, -1, sizeof dp);
  int ans = solve(0, 0);
  ans = add(ans, solve(0, 1, 1));
  ans = add(ans, solve(0, 3));
  cout << ans;
  return 0;
}
