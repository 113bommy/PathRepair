#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
int n, m, c0, d0;
vector<int> a(11), b(11), c(11), d(11);
int dp[1005][11];
int f(int n, int m) {
  if (n <= 0 || m <= 0) return 0;
  if (dp[n][m] >= 0) return dp[n][m];
  int ans = 0;
  if (m == 0 || n == 0)
    ans = 0;
  else {
    int k = a[m] / b[m];
    for (long long i = 0; i < (k + 1); ++i) {
      if (n - i * c[n] > 0) {
        ans = max(ans, f(n - (int)i * c[m], m - 1) + d[m] * (int)i);
      }
    }
  }
  return dp[n][m] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> c0 >> d0;
  for (long long i = 1; i <= (m); ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  memset(dp, -1, sizeof(dp));
  for (long long i = 0; i <= (n); ++i) dp[i][0] = 0;
  f(n, m);
  int ans = 0;
  for (long long i = 0; i < (n + 1); ++i) {
    ans = max(ans, f((int)i, m) + ((n - (int)i) / c0) * d0);
  }
  cout << ans << '\n';
  return 0;
}
