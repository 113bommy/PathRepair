#include <bits/stdc++.h>
using namespace std;
char s[((int)1e6 + 10)];
int dp[((int)1e6 + 10)][3][2], n;
int solve(int idx, int decision, bool prevBomb) {
  if (idx >= n) {
    return decision == 0;
  }
  int& ret = dp[idx][decision][prevBomb];
  if (ret != -1) return ret;
  ret = 0;
  if (decision == 0) {
    if (s[idx] == '*') ret += solve(idx + 1, 0, true);
    if (s[idx] == '?') {
      ret += solve(idx + 1, 0, false);
      ret %= 1000000007;
      ret += solve(idx + 1, 0, true);
    } else {
      int tot = ((int)prevBomb) - s[idx] + '0';
      if (tot == 0) {
        ret += solve(idx + 1, 2, false);
      } else if (tot == -1) {
        ret += solve(idx + 1, 1, false);
      }
    }
  } else if (decision == 1) {
    if (s[idx] == '*' || s[idx] == '?') ret += solve(idx + 1, 0, true);
  } else {
    if (s[idx] == '?') {
      ret += solve(idx + 1, 0, false);
    } else if (s[idx] != '*') {
      int tot = ((int)prevBomb) - s[idx] + '0';
      if (tot == 0) {
        ret += solve(idx + 1, 2, false);
      } else if (tot == -1) {
        ret += solve(idx + 1, 1, false);
      }
    }
  }
  ret %= 1000000007;
  return ret;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0) << endl;
  return 0;
}
