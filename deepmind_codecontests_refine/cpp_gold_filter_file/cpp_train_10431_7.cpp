#include <bits/stdc++.h>
using namespace std;
int n, h[2010];
long long k, dp[2010][2 * 2010] = {0LL};
int main() {
  cin >> n >> k;
  for (int i = (1); i < (n + 1); i++) cin >> h[i];
  dp[0][n + 1] = 1LL;
  for (int i = (1); i < (n + 1); i++)
    for (int s = (-n); s < (n + 1); s++)
      if (h[i] == h[i % n + 1])
        dp[i][s + n + 1] = (k * dp[i - 1][s + n + 1]) % 998244353;
      else
        dp[i][s + n + 1] =
            ((dp[i - 1][s + n] + ((k - 2) * dp[i - 1][s + n + 1]) % 998244353) %
                 998244353 +
             dp[i - 1][s + n + 2]) %
            998244353;
  long long ans = 0LL;
  for (int s = (1); s < (n + 1); s++)
    ans = (ans + dp[n][s + n + 1]) % 998244353;
  cout << ans << '\n';
}
