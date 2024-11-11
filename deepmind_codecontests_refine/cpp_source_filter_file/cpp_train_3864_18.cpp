#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long dp[1001][1001][2][2];
long long fun(long long i, long long j, long long p, long long l) {
  if (i == 0) {
    if (j == k)
      return 1;
    else
      return 0;
  } else if (dp[i][j][p][l] != -1)
    return dp[i][j][p][l] % 998244353;
  else {
    long long ans = 0;
    if (p == 0 && l == 0)
      ans += (fun(i - 1, j, 0, 0) % 998244353 +
              fun(i - 1, j + 1, 1, 0) % 998244353 +
              fun(i - 1, j + 1, 0, 1) % 998244353 +
              fun(i - 1, j + 1, 1, 1) % 998244353) %
             998244353;
    else if (p == 0 && l == 1)
      ans +=
          (fun(i - 1, j, 0, 0) % 998244353 +
           fun(i - 1, j + 2, 1, 0) % 998244353 +
           fun(i - 1, j, 0, 1) % 998244353 + fun(i - 1, j, 1, 1) % 998244353) %
          998244353;
    else if (p == 1 && l == 0)
      ans +=
          (fun(i - 1, j, 0, 0) % 998244353 + fun(i - 1, j, 1, 0) % 998244353 +
           fun(i - 1, j + 2, 0, 1) % 998244353 +
           fun(i - 1, j, 1, 1) % 998244353) %
          998244353;
    else
      ans += (fun(i - 1, j + 1, 0, 0) % 998244353 +
              fun(i - 1, j + 1, 1, 0) % 998244353 +
              fun(i - 1, j + 1, 0, 1) % 998244353 +
              fun(i - 1, j, 1, 1) % 998244353) %
             998244353;
    dp[i][j][p][l] = ans % 998244353;
    return dp[i][j][p][l] % 998244353;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (long long i = 0; i < 1001; i++)
    for (long long j = 0; j < 1001; j++)
      for (long long p = 0; p < 2; p++)
        for (long long l = 0; l < 2; l++) dp[i][j][p][l] = -1;
  long long ans = 0;
  ans += (fun(n - 1, 1, 0, 0) % 998244353 + fun(n - 1, 1, 1, 1) % 998244353 +
          fun(n - 1, 2, 0, 1) % 998244353 + fun(n - 1, 2, 1, 0) % 998244353) %
         998244353;
  ans %= 998244353;
  cout << ans << '\n';
}
