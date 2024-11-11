#include <bits/stdc++.h>
using namespace std;
const long long N = 1000 * 600;
const int MAX_X = 1000 + 20;
const int MAX_N = 100 + 20;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000 * 1000 * 1000 * 100 + 1;
int poww(int x, int y) {
  return (!y ? 1 : (y & 1 ? x * poww(x * x, y / 2) : poww(x * x, y / 2)));
}
long long a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long q = n % k, q1 = n / k, x;
  long long m = k;
  long long dp[m + 1][q + 1];
  for (long long i = 0; i <= k; i++)
    for (long long j = 0; j <= q; j++) dp[i][j] = 1e17;
  dp[0][0] = 0;
  for (long long i = 1; i <= m; i++) {
    for (long long j = 0; j <= q; j++) {
      x = i * q1 + j - 1;
      if (j < i && x >= q1 - 1)
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[x] - a[x - q1 + 1]);
      if (j > 0 && j >= 1 && x >= q1)
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[x] - a[x - q1]);
    }
  }
  cout << dp[m][q];
  return 0;
}
