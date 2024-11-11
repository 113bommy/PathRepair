#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 100;
int d[MAXN], dp[MAXN], ans;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (int j = 1; (j * j) <= a[i]; j++) {
      if (!(a[i] % j)) {
        dp[i] = max(dp[i], (dp[d[a[i] / j]] + 1));
        if (j > 1) dp[i] = max(dp[i], (dp[d[j]] + 1));
        ans = max(ans, dp[i]);
        d[j] = d[a[i] / j] = i;
      }
    }
  }
  printf("%d\n", ans);
  return false;
}
