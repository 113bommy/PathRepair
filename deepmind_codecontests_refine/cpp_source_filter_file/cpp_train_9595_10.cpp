#include <bits/stdc++.h>
using namespace std;
long long a, b, d[1001], y[100001], dp[1001][1001];
int main() {
  scanf("%lld%lld", &a, &b);
  for (int i = 1; i <= a; i++) {
    scanf("%lld", &d[i]);
  }
  sort(d + 1, d + a + 1);
  long long pp = 1;
  for (int i = d[1]; i <= 100000; i++) {
    while (pp < a && i >= d[pp + 1]) {
      pp++;
    }
    y[i] = pp;
  }
  long long ans = 0;
  for (int i = 0; i <= b; i++) {
    dp[i][0] = 1;
  }
  for (int ii = 1; ii * (b - 1) <= 100000; ii++) {
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
        dp[i][j] = dp[i - 1][j] + dp[d[i] - ii >= 0 ? y[d[i] - ii] : 0][j - 1];
        dp[i][j] %= 998244353;
      }
    }
    ans += dp[a][b];
    ans %= 998244353;
  }
  printf("%lld", ans);
  return 0;
}
