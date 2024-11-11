#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)(1e3 + 123);
long long n, k, m, dp[maxn][maxn], ans[maxn][maxn];
int main() {
  scanf("%I64d %I64d %I64d", &n, &k, &m);
  dp[0][0] = 1 % m;
  for (int i = 1; i <= n; ++i) {
    for (int dig = bool(i == 1); dig < 10; ++dig) {
      for (int mod = 0; mod < k; ++mod) {
        dp[i][(mod * 10 + dig) % k] =
            (dp[i][(mod * 10 + dig) % k] + dp[i - 1][mod]) % m;
      }
    }
  }
  ans[1][0] = 9 / k % m;
  int deg = 10 % m;
  for (long long i = 2; i <= n; ++i) {
    long long sum = 0;
    for (long long dig = bool(i == n); dig < 10; ++dig) {
      for (long long mod = 0; mod < k; ++mod) {
        if (!ans[i - 1][mod]) continue;
        if ((mod + dig * deg) % k) {
          ans[i][(mod + dig * deg) % k] =
              (ans[i][(mod + dig * deg) % k] + ans[i - 1][mod]) % m;
        }
      }
    }
    deg = deg * 10 % k;
    ans[i][0] = (ans[i][0] + dp[i][0]) % m;
    if (i != n) ans[i][0] = (ans[i][0] + ans[i - 1][0]) % m;
  }
  long long sum = 0;
  for (long long mod = 0; mod < k; ++mod) {
    sum = (sum + ans[n][mod]) % m;
  }
  printf("%I64d", sum);
  return 0;
}
