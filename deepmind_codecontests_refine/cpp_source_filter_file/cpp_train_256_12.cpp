#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int maxn = 100000 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
long long a[3 * maxn];
long long dp[5050][5050];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  int l = n / k;
  int num1 = n % k;
  int num2 = k - n % k;
  memset(dp, INF, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i <= num1; i++)
    for (int j = 0; j <= num2; j++) {
      int now = i * (l + 1) + j * l;
      if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[now] - a[now - l]);
      if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[now] - a[now - (l - 1)]);
    }
  printf("%d\n", dp[num1][num2]);
  return 0;
}
