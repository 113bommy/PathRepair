#include <bits/stdc++.h>
using namespace std;
template <typename T>
void vout(T x) {
  cout << x << endl;
  exit(0);
}
int gcd(int a, int b) {
  while (a && b) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
const int inf = 2e9 + 7;
const long long INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2000;
long long n, k, x, a[201], dp[300][300];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> x;
  if (n / k > x) vout(-1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < 300; ++i) {
    for (int j = 0; j < 300; ++j) dp[i][j] = -INF;
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= x; ++j) {
      for (int t = max(0LL, i - k); t < i; ++t)
        dp[i][j] = max(dp[i][j], dp[t][j - 1] + a[i]);
    }
  }
  long long ans = 0;
  for (int i = n - k + 1; i <= n; ++i) {
    ans = max(ans, dp[i][x]);
  }
  cout << ans << endl;
  return 0;
}
