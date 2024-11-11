#include <bits/stdc++.h>
using namespace std;
const int B = 1e9 + 7, N = 2010;
int n, k;
char s[N];
long long dp[N][N];
long long g[N][N];
void add(long long &x, long long y) { x = (x + y) % B; }
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  dp[0][0] = 1;
  g[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      add(dp[i][j], g[i - 1][j] * (s[i] - 'a'));
      for (int l = 0; l < i; ++l) {
        if ((1 + l) * (n - i + 1) > j) break;
        add(dp[i][j], dp[i - l - 1][j - (1 + l) * (n - i + 1)] * ('z' - s[i]));
      }
    }
    for (int j = 0; j <= k; ++j) {
      g[i][j] = (g[i - 1][j] + dp[i][j]) % B;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    add(ans, dp[i][k]);
  }
  printf("%lld\n", ans);
  return 0;
}
