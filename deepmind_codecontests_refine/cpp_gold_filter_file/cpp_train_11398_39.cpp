#include <bits/stdc++.h>
using namespace std;
long long int dp[1001][100][2];
int n, k, m;
long long int solve(int ind, int rem, int pow, bool valid) {
  if (ind == n) return valid;
  if (dp[ind][rem][valid] != -1) return dp[ind][rem][valid];
  int ret = 0;
  for (int i = (ind == n - 1); i < 10; i++) {
    int newr = (rem + (i * pow)) % k;
    ret += solve(ind + 1, newr, (pow * 10) % k, valid || (newr == 0 && i != 0));
    ret %= m;
  }
  return dp[ind][rem][valid] = ret;
}
int main() {
  cin >> n >> k >> m;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0, 1, 0);
}
