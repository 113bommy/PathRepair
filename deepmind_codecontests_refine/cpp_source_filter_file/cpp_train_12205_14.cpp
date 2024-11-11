#include <bits/stdc++.h>
using namespace std;
char s[110];
int n, ls, oo = 1 << 29, dp[101][201][2][51][2];
int solve(int ind, int pos, bool right, int moves, bool changed) {
  int ret = -oo;
  if (ind == ls) {
    if (moves == 0) return abs(pos);
    return -oo;
  }
  if (dp[ind][pos + 100][right][moves][changed] != -1)
    return dp[ind][pos + 100][right][moves][changed];
  if (moves > 0) ret = max(ret, solve(ind, pos, right, moves - 1, !changed));
  int tmp;
  if (!right)
    tmp = -1;
  else if (right)
    tmp = 1;
  if ((s[ind] == 'F' && !changed) || (s[ind] == 'T' && changed)) {
    ret = max(ret, solve(ind + 1, pos + tmp, right, moves, 0));
  } else if ((s[ind] == 'T' && !changed) || (s[ind] == 'F' && changed))
    ret = max(ret, solve(ind + 1, pos, !right, moves, 0));
  return dp[ind][pos + 100][right][moves][changed] = ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> s >> n;
  ls = strlen(s);
  cout << solve(0, 100, 1, n, 0) << endl;
  return 0;
}
