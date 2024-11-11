#include <bits/stdc++.h>
using namespace std;
void adds(long long& a, long long b) {
  a = a + b;
  if (a >= 1000000007) a -= 1000000007;
  return;
}
void test_case() {
  long long n, i, j, m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<long long> a(n);
  vector<vector<long long>> dp(2, vector<long long>(m, 0));
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  if (n >= m) {
    printf("%s", "YES\n");
    return;
  }
  if (n == 1) {
    if (a[0] % m == 0)
      printf("%s", "YES\n");
    else
      printf("%s", "NO\n");
    return;
  }
  dp[0][0] = 1;
  dp[0][a[0] % m] = 1;
  for (i = 1; i < n; i++) {
    for (j = 0; j < m; j++) {
      dp[1][j] = dp[0][j];
      adds(dp[1][j], dp[0][(j - a[i] + m) % m]);
    }
    for (j = 0; j < m; j++) {
      dp[0][j] = dp[1][j];
    }
  }
  if (dp[0][0] > 1)
    printf("%s", "YES\n");
  else
    printf("%s", "NO\n");
  return;
}
signed main() {
  long long t;
  t = 1;
  while (t--) {
    test_case();
  }
  return 0;
}
