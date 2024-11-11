#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000, mod = 1000000007;
int p[maxn];
int dp[maxn][2];
int main() {
  int n, xi;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) scanf("%d", &p[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &xi), dp[i][xi] = 1;
  for (int i = n - 1; i > 0; --i) {
    dp[p[i]][1] = (1ll * dp[p[i]][1] * (dp[i][0] + dp[i][1]) +
                   1ll * dp[p[i]][0] * dp[i][1]) %
                  mod;
    dp[p[i]][0] = (1ll * dp[p[i]][0] * (dp[i][0] + dp[i][1])) % mod;
  }
  printf("%d\n", dp[0][1]);
}
