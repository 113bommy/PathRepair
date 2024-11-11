#include <bits/stdc++.h>
using namespace std;
const long long D = 998244353;
long long d[5001];
long long e[5001];
long long n, m, k;
long long pow2(long long x, long long y) {
  if (y == 0) return 1;
  long long w = pow2(x, y / 2);
  return y % 2 == 0 ? w * w % D : w * w % D * x % D;
}
long long f(long long x) {
  long long i;
  long long ret = 1;
  for (i = n; i >= n - x + 1; i--) ret = ret * i % D;
  ret = ret * pow2(pow2(m, x), D - 2) % D;
  return ret;
}
long long dp[5001][5001];
void process() {
  long long i, j;
  long long ans = 0;
  for (i = 0; i <= n; i++) {
    dp[i][0] = 1;
    for (j = 1; j <= i; j++) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % D;
  }
  for (i = 0; i <= n; i++) {
    ans = (ans + pow2(i, k) * dp[n][i] % D * pow2(m - 1, n - i) % D *
                     pow2(pow2(m, k), D - 2) % D) %
          D;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  if (n < k) {
    process();
    return 0;
  }
  long long i, j;
  e[1] = n * pow2(m, D - 2) % D;
  d[1] = 1;
  for (i = 2; i <= k; i++) {
    long long c = f(i);
    for (j = i; j >= 1; j--) d[j] = (d[j - 1] - ((i - 1) * d[j] % D) + D) % D;
    e[i] = c;
    for (j = i - 1; j >= 1; j--) e[i] = (e[i] - (d[j] * e[j] % D) + D) % D;
  }
  cout << e[k];
  return 0;
}
