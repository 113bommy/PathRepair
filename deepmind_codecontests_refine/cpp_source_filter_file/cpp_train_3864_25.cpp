#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int n, k;
long long int dp[1005][2][2][1005];
long long int solve(long long int ind, long long int preva, long long int prevb,
                    long long int com) {
  if (ind >= n) {
    if (com == k) return 1;
    return 0;
  }
  if (dp[ind][preva][prevb][com] != -1) return dp[ind][preva][prevb][com];
  long long int ans = 0;
  if (ind == 0) {
    ans += solve(ind + 1, 0, 0, 1);
    ans %= mod;
    ans += solve(ind + 1, 1, 1, 1);
    ans %= mod;
    ans += solve(ind + 1, 1, 0, 2);
    ans %= mod;
    ans += solve(ind + 1, 0, 1, 2);
    ans %= mod;
  } else {
    if (preva == 1 && prevb == 1) {
      ans += solve(ind + 1, 1, 1, com);
      ans %= mod;
      ans += solve(ind + 1, 0, 0, com + 1);
      ans %= mod;
      ans += solve(ind + 1, 0, 1, com + 1);
      ans %= mod;
      ans += solve(ind + 1, 1, 0, com + 1);
      ans %= mod;
    } else if (preva == 0 && prevb == 0) {
      ans += solve(ind + 1, 1, 1, com + 1);
      ans %= mod;
      ans += solve(ind + 1, 0, 0, com);
      ans %= mod;
      ans += solve(ind + 1, 0, 1, com + 1);
      ans %= mod;
      ans += solve(ind + 1, 1, 0, com + 1);
      ans %= mod;
    } else if (preva == 1 && prevb == 0) {
      ans += solve(ind + 1, 1, 1, com);
      ans %= mod;
      ans += solve(ind + 1, 0, 0, com);
      ans %= mod;
      ans += solve(ind + 1, 0, 1, com + 2);
      ans %= mod;
      ans += solve(ind + 1, 1, 0, com);
      ans %= mod;
    } else {
      ans += solve(ind + 1, 1, 1, com);
      ans %= mod;
      ans += solve(ind + 1, 0, 0, com);
      ans %= mod;
      ans += solve(ind + 1, 0, 1, com);
      ans %= mod;
      ans += solve(ind + 1, 1, 0, com + 2);
      ans %= mod;
    }
  }
  dp[ind][preva][prevb][com] = ans % mod;
  return dp[ind][preva][prevb][com];
}
int main() {
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 1, 1, 0) << endl;
  return 0;
}
