#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
long long a[maxn];
int p[maxn];
int dp[maxn];
int main() {
  int n;
  scanf("%d", &n);
  memset(p, 0, sizeof(p));
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    while (a[i] % 2 == 0) a[i] /= 2, p[i]++;
  }
  int tmp = 1;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (!p[i]) {
        if (a[j] % a[i] == 0) dp[i] = max(dp[j] + 1, dp[i]);
      } else {
        if (i - j - 1 < p[i]) {
          if ((p[i] - p[j]) == (i - j) && a[j] % a[i] == 0)
            dp[i] = max(dp[j] + 1, dp[i]);
        } else {
          if (a[j] % a[i] == 0) dp[i] = max(dp[j] + 1, dp[i]);
        }
      }
    }
    tmp = max(dp[i], tmp);
  }
  printf("%d\n", n - tmp);
  return 0;
}
