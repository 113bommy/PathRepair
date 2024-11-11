#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
string s;
long long dp[N][3];
long long solve(int ind, int rem) {
  if (ind == s.size()) return rem == 0;
  if (~dp[ind][rem]) return dp[ind][rem];
  if (!rem) return dp[ind][rem] = solve(ind + 1, (s[ind] - '0') % 3) + 1;
  return dp[ind][rem] = max(solve(ind + 1, (rem * 10 + (s[ind] - '0')) % 3),
                            solve(ind + 1, (s[ind] - '0') % 3));
}
int main() {
  cin >> s;
  memset(dp, -1, sizeof(dp));
  cout << solve(1, (s[0] - '0') % 3);
  return 0;
}
