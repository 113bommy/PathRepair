#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[4][1002][2002];
const long long MOD = 998244353;
long long do_dp(int move, int inx, int faltantes) {
  if (dp[move][inx][faltantes] != -1) {
    return dp[move][inx][faltantes];
  }
  if (inx == n && faltantes == 0) {
    return dp[move][inx][faltantes] = 1;
  }
  if (inx > n || faltantes < 0) return 0;
  long long ans = 0;
  if (inx == 0) {
    ans += do_dp(0, inx + 1, k - 1);
    ans %= MOD;
    ans += do_dp(1, inx + 1, k - 2);
    ans %= MOD;
    ans += do_dp(2, inx + 1, k - 2);
    ans %= MOD;
    ans += do_dp(3, inx + 1, k - 1);
    ans %= MOD;
    return dp[move][inx][faltantes] = ans;
  }
  ans += do_dp(0, inx + 1, faltantes - ((move == 3) ? 1 : 0));
  ans %= MOD;
  ans +=
      do_dp(1, inx + 1, faltantes - ((move == 2) ? 2 : ((move == 1) ? 0 : 1)));
  ans %= MOD;
  ans +=
      do_dp(2, inx + 1, faltantes - ((move == 1) ? 2 : ((move == 2) ? 0 : 1)));
  ans %= MOD;
  ans += do_dp(3, inx + 1, faltantes - ((move == 0) ? 1 : 0));
  ans %= MOD;
  return dp[move][inx][faltantes] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 1001; j++)
      for (int k = 0; k < 2001; k++) dp[i][j][k] = -1;
  cout << do_dp(0, 0, k);
}
