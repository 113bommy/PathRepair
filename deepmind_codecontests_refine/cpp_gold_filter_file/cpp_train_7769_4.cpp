#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e3 + 100;
const long long MOD = 1e9 + 7;
void exgcd(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inv(long long a) {
  long long d, x, y;
  exgcd(a, MOD, d, x, y);
  return d == 1 ? (x + MOD) % MOD : -1;
}
long long dp[MAXN][MAXN];
int main(int argc, char const* argv[]) {
  long long n, n1, n2;
  cin >> n >> n1 >> n2;
  long long pa = n1 * inv(n1 + n2) % MOD;
  long long pb = n2 * inv(n1 + n2) % MOD;
  long long pbi = inv(pb);
  memset(dp, 0, sizeof dp);
  for (int i = n; i > 0; --i) {
    for (int j = n; j >= 0; --j) {
      if (i + j >= n)
        dp[i][j] = (i + j + pa * pbi) % MOD;
      else
        dp[i][j] = (dp[i + 1][j] * pa % MOD + dp[i][j + i] * pb % MOD) % MOD;
    }
  }
  cout << dp[1][0] << endl;
  return 0;
}
