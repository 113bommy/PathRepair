#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long dp[505][505];
int b[505];
long long dfs(int l, int r) {
  if (l >= r) {
    dp[l][r] = 1LL;
    return 1LL;
  }
  if (dp[l][r] != -1) return dp[l][r];
  long long &res = dp[l][r];
  res = 0LL;
  for (int i = l; i <= r; i++) {
    if (b[i + 1] >= b[l] || i == r) {
      res = (res + (dfs(l + 1, i) * dfs(i + 1, r)) % mod) % mod;
    }
  }
  res %= mod;
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  if (n == 2) {
    printf("1 2\n");
    return 0;
  }
  memset(dp, -1, sizeof(dp));
  cout << dfs(2, n) << endl;
}
