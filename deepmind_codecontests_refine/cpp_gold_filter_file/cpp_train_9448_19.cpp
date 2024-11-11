#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, k;
bool dp[N][N];
long long a[N], s[N], ans;
bool check(long long w) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (dp[i][j])
        for (int l = i + 1; l <= n; l++)
          if (((s[l] - s[i]) & w) == w) dp[l][j + 1] = 1;
    }
  }
  return dp[n][k];
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 59; i >= 0; i--) {
    if (check(ans | (1ll << i))) ans |= (1ll << i);
  }
  printf("%lld\n", ans);
  return 0;
}
