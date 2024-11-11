#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, P = 1e9 + 7;
int n, m;
long long dp[maxn][maxn], bin[maxn];
int main() {
  scanf("%d%d", &n, &m);
  bin[0] = 1;
  for (int i = 1; i < n * n; ++i) {
    bin[i] = bin[i - 1] * 2 % P;
  }
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= min(m, i); ++j) {
      for (int k = j - 1; k <= i; ++k) {
        dp[i][j] = (dp[i][j] + dp[k][j - 1] * (bin[i - k] - 1) % P *
                                   bin[k * (i - k)] % P) %
                   P;
      }
    }
  }
  printf("%lld\n", dp[n][m]);
  return 0;
}
