#include <bits/stdc++.h>
using namespace std;
long long dp[1005][15];
long long N, M, c0, d0;
long long a[15], b[15], c[15], d[15];
long long f(long long n, long long m) {
  if (n == 0) return 0;
  if (m == 0) return (n / c0) * d0;
  if (dp[n][m] != -1) return dp[n][m];
  long long ans = f(n, m - 1);
  for (long long i = 1; n - i * c0 >= 0; i++)
    ans = max(ans, i * d0 + f(n - i * c0, m - 1));
  for (long long i = 1; a[m] - i * b[m] >= 0 && n - i * c[m] >= 0; i++)
    ans = max(ans, i * d[m] + f(n - i * c[m], m - 1));
  return dp[n][m] = ans;
}
int main() {
  cin >> N >> M >> c0 >> d0;
  for (int i = 1; i <= M; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  memset(dp, -1, sizeof(dp));
  long long ans = f(N, M);
  cout << ans << endl;
  return 0;
}
