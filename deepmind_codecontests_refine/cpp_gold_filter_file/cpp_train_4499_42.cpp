#include <bits/stdc++.h>
using namespace std;
const int N = 91;
long long f[N], g[N], dp[N][2];
long long t, n;
void init() {
  scanf("%d", &t);
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i <= N; i++) f[i] = f[i - 1] + f[i - 2];
  while (t--) {
    long long tot = 0;
    scanf("%I64d", &n);
    for (int i = N; i >= 1; i--)
      if (n >= f[i]) {
        g[++tot] = i;
        n -= f[i];
      }
    for (int i = 1; i <= tot / 2; i++) swap(g[i], g[tot - i + 1]);
    dp[1][0] = 1;
    dp[1][1] = (g[1] - 1) / 2;
    for (int i = 2; i <= tot; i++) {
      dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] * ((g[i] - g[i - 1] - 1) / 2) +
                 dp[i - 1][1] * ((g[i] - g[i - 1]) / 2);
    }
    printf("%I64d\n", dp[tot][0] + dp[tot][1]);
  }
}
int main() {
  init();
  return 0;
}
