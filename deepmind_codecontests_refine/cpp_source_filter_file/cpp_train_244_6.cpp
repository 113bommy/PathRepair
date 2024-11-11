#include <bits/stdc++.h>
using namespace std;
long long a[5001];
int pw2[501], dp[501];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    while (a[i] % 2 == 0) {
      ++pw2[i];
      a[i] /= 2;
    }
  }
  int ans = 1000000000;
  for (int i = 1; i <= n; ++i) {
    dp[i] = i - 1;
    for (int j = 1; j < i; ++j)
      if ((a[j] % a[i] == 0) && (j < i - pw2[i] || pw2[j] == pw2[i] - (i - j)))
        dp[i] = min(dp[i], dp[j] + (i - j - 1));
    ans = min(ans, dp[i] + (n - i));
  }
  printf("%d", ans);
  return 0;
}
