#include <bits/stdc++.h>
using namespace std;
int n, ans, dp[105], a[105];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n % 2 == 0 || n == 1) {
    printf("-1");
    return 0;
  }
  for (int i = n; i >= 2; i--) {
    ans += max(a[i], a[i - 1]);
    a[(i - 1) / 2] -= min(a[(i - 1) / 2], max(a[i], a[i - 1]));
    i--;
  }
  printf("%d", ans);
}
