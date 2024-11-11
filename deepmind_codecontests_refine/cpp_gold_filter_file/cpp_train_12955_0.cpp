#include <bits/stdc++.h>
using namespace std;
const int la = 10000000;
int dp[la];
int dfs(long long x, bool rev) {
  if (0 <= x && x <= 6) return x;
  if (7 <= x && x <= 11) return 13 - x;
  if (x < la && dp[x]) return dp[x];
  long long one = 1;
  int cnt = 1;
  while (one < x) one = one * 10 + 1, cnt++;
  int ret = la;
  if (!rev) ret = dfs(one - x, true) + cnt;
  one = (one - 1) / 10;
  int cnt2 = (x - 1) / one + 1;
  long long nnn = cnt2 * one;
  ret = min(ret, dfs(nnn - x, false) + cnt2 * (cnt - 1));
  if (nnn != one)
    ret = min(ret, dfs(x - (nnn - one), false) + (cnt2 - 1) * (cnt - 1));
  if (!rev && x < la) dp[x] = ret;
  return ret;
}
int main() {
  long long n;
  cin >> n;
  cout << dfs(n, false);
  return 0;
}
