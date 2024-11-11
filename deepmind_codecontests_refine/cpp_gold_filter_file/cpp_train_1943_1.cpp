#include <bits/stdc++.h>
using namespace std;
long long dp[2][2][1010][1010][2], k;
string num, numl, numr;
long long solve(long long isStart, long long isSmall, long long pos,
                long long last, long long isLucky) {
  if (pos == 0) return isLucky;
  long long &ret = dp[isStart][isSmall][pos][last][isLucky];
  if (ret != -1 && isSmall) return ret;
  long long lim, pos2 = num.size() - pos;
  if (isSmall)
    lim = 9;
  else
    lim = num[pos2] - '0';
  long long rt = 0;
  if (!isStart) {
    for (long long i = 0; i <= lim; i++) {
      long long nlast = last;
      bool tmp = 0;
      if (i == 4 || i == 7) {
        if (last != 1008 && abs(last - pos) <= k) tmp = 1;
        nlast = pos;
      }
      rt += solve(0, isSmall | i < (num[pos2] - '0'), pos - 1, nlast,
                  isLucky | tmp);
    }
    rt %= 1000000007;
  } else {
    for (long long i = 1; i <= lim; i++) {
      long long nlast = last;
      bool tmp = 0;
      if (i == 4 || i == 7) {
        if (last != 1008 && abs(last - pos) <= k) tmp = 1;
        nlast = pos;
      }
      rt += solve(0, isSmall | i < (num[pos2] - '0'), pos - 1, nlast,
                  isLucky | tmp);
    }
    rt += solve(1, 1, pos - 1, 1008, 0);
    rt %= 1000000007;
  }
  return ret = rt % 1000000007;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  long long t, caseno = 0;
  memset(dp, -1, sizeof(dp));
  cin >> t >> k;
  while (t--) {
    cin >> numl >> numr;
    long long carry = 1;
    for (long long i = (long long)numl.length() - 1; i >= 0; i--) {
      if (numl[i] == '0') {
        numl[i] = '9';
        carry = 1;
      } else {
        numl[i] = (numl[i] - '1') + '0';
        break;
      }
    }
    num = numr;
    long long ans = solve(1, 0, num.length(), 1008, 0);
    num = "";
    bool chk = 0;
    for (long long i = 0; i < numl.length(); i++) {
      if (numl[i] != '0') chk = 1;
      if (chk) num += numl[i];
    }
    if (num.length() != 0) ans -= solve(1, 0, num.length(), 1008, 0);
    ans = (ans + 1000000007) % 1000000007;
    cout << ans << endl;
  }
  return 0;
}
