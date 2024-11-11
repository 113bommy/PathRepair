#include <bits/stdc++.h>
using namespace std;
long long counti[3] = {0};
long long dp[200005][3];
long long z = 1000000007;
long long ans(long long n, long long k) {
  if (n == 1) return dp[n][k] = counti[k] % z;
  if (dp[n][k] != -1) return dp[n][k] % z;
  dp[n][0] = (((ans(n - 1, 0)) % z * (counti[0]) % z) % z +
              ((ans(n - 1, 2)) % z * (counti[1]) % z) % z +
              ((ans(n - 1, 1)) % z * (counti[2]) % z) % z) %
             z;
  dp[n][1] = (((ans(n - 1, 0)) % z * (counti[1]) % z) % z +
              ((ans(n - 1, 2)) % z * (counti[2]) % z) % z +
              ((ans(n - 1, 1)) % z * (counti[0]) % z) % z) %
             z;
  dp[n][2] = (((ans(n - 1, 0)) % z * (counti[2]) % z) % z +
              ((ans(n - 1, 1)) % z * (counti[1]) % z) % z +
              ((ans(n - 1, 2)) % z * (counti[0]) % z) % z) %
             z;
  return dp[n][k] % z;
}
int main() {
  long long n, l, r;
  cin >> n >> l >> r;
  memset(dp, -1, sizeof(dp));
  if (r % 3 == 0) {
    counti[0] = r / 3;
    counti[1] = r / 3;
    counti[2] = r / 3;
  } else if (r % 3 == 1) {
    counti[0] = r / 3;
    counti[1] = r / 3 + 1;
    counti[2] = r / 3;
  } else if (r % 3 == 2) {
    counti[0] = r / 3;
    counti[1] = r / 3 + 1;
    counti[2] = r / 3 + 1;
  }
  if ((l - 1) % 3 == 0) {
    counti[0] -= (l - 1) / 3;
    counti[1] -= (l - 1) / 3;
    counti[2] -= (l - 1) / 3;
  } else if ((l - 1) % 3 == 1) {
    counti[0] -= (l - 1) / 3;
    counti[1] -= ((l - 1) / 3 + 1);
    counti[2] -= (l - 1) / 3;
  } else if ((l - 1) % 3 == 2) {
    counti[0] -= (l - 1) / 3;
    counti[1] -= ((l - 1) / 3 + 1);
    counti[2] -= ((l - 1) / 3 + 1);
  }
  cout << ans(n, 0);
}
