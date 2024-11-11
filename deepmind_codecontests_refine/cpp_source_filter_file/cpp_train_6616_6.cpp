#include <bits/stdc++.h>
using namespace std;
const int maxn = 3333;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long a[maxn], b[maxn], dp[maxn][maxn], prvmin[maxn];
long long iabs(long long x) { return x < 0 ? -x : x; }
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    dp[1][i] = iabs(a[1] - b[i]);
    prvmin[i] = i == 1 ? dp[1][i] : min(prvmin[i - 1], dp[1][i]);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = prvmin[j] + iabs(a[i] - b[j]);
      prvmin[j] = j == 1 ? dp[i][j] : min(dp[i][j], prvmin[j - 1]);
    }
  }
  long long ans = prvmin[1];
  for (int i = 2; i <= n; i++) {
    ans = min(ans, prvmin[i - 1]);
  }
  printf("%lld\n", ans);
  return 0;
}
