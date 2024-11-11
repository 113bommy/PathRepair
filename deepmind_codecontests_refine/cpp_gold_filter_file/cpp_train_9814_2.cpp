#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long dp[N], a[N], b[N];
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (i = 1; i <= n; i++) dp[i] = dp[i - 1] + abs(b[1] - a[i]);
  for (i = 2; i <= n; i++) {
    for (j = 1; j <= n; j++) dp[j] = min(dp[j], dp[j - 1] + abs(b[i] - a[j]));
  }
  printf("%lld\n", dp[n]);
}
