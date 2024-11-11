#include <bits/stdc++.h>
using namespace std;
const long long maxn = 300000 + 5;
const long long maxk = 5000 + 5;
const long long INF = (1 << 30);
long long a[maxn], dp[maxk][maxk];
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i <= n; i++) scanf("%lld", a + i);
  sort(a + 1, a + n + 1);
  long long L = n % k, S = k - L, sz = n / k;
  for (long long i = 0; i <= S; i++)
    for (long long j = 0; j <= L; j++) dp[i][j] = INF;
  dp[0][0] = 0;
  for (long long i = 0; i <= S; i++)
    for (long long j = 0; j <= L; j++) {
      long long p = i * (sz) + j * (sz + 1) + 1;
      if (p + sz - 1 <= n)
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[p + sz - 1] - a[p]);
      if (p + sz <= n)
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + a[p + sz] - a[p]);
    }
  printf("%lld\n", dp[S][L]);
}
