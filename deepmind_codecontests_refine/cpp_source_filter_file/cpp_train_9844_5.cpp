#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
int a[3030], b[3030];
long long dp[3030][3030];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    a[i] -= i;
    b[i] = a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    long long temp = dp[i - 1][1];
    for (int j = 1; j <= n; ++j) {
      temp = min(temp, dp[i - 1][j]);
      dp[i][j] = abs(b[i] - a[j]) + temp;
    }
  }
  long long ans = INF;
  for (int i = 1; i <= n; ++i) ans = min(ans, dp[n][i]);
  printf("%I64d\n", ans);
  return 0;
}
