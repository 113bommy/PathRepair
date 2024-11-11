#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
long long powmod(long long base, long long exp, const long long MOD) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return ans;
}
long long modInverse(long long n, const long long p) {
  return powmod(n, p - 2, p);
}
const int N = 5005;
int dp[N][N];
void test_case() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  a = ' ' + a;
  b = ' ' + b;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j])
        dp[i][j] = max({dp[i][j], 2, dp[i - 1][j - 1] + 2});
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  test_case();
  return 0;
}
