#include <bits/stdc++.h>
const double EPS = 1e-10;
const long long int MOD = 1000000007ll;
const long long int mod1 = 1000000009ll;
const long long int mod2 = 1100000009ll;
const double PI = 3.14159265359;
int INF = 2147483645;
long long int INFINF = 9223372036854775807;
int debug = 0;
using namespace std;
long long int bit_count(long long int _x) {
  long long int _ret = 0;
  while (_x) {
    if (_x % 2 == 1) _ret++;
    _x /= 2;
  }
  return _ret;
}
long long int bit(long long int _mask, long long int _i) {
  return (_mask & (1 << _i)) == 0 ? 0 : 1;
}
long long int powermod(long long int _a, long long int _b, long long int _m) {
  long long int _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a) % _m;
    _b /= 2;
    _a = (_a * _a) % _m;
  }
  return _r;
}
long long int add(long long int a, long long int b) {
  long long int x = a + b;
  if (x > MOD) x -= MOD;
  return x;
}
long long int sub(long long int a, long long int b) {
  long long int x = a - b;
  if (x < 0) x += MOD;
  return x;
}
long long int mul(long long int a, long long int b) {
  long long int x = a * b;
  x %= MOD;
  return x;
}
int n;
int a[1000010];
int dp[21][1100010];
int logM = 20;
int M = (1 << logM) - 1;
int main() {
  srand(time(NULL));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) dp[0][a[i]]++;
  for (int i = 1; i <= logM; i++) {
    for (int j = 0; j <= M; j++) {
      if (bit(j, i - 1))
        dp[i][j] += dp[i - 1][j];
      else
        dp[i][j] += dp[i - 1][j] + dp[i - 1][j | (1 << (i - 1))];
      if (dp[i][j] > MOD) dp[i][j] -= MOD;
    }
  }
  long long int ans = powermod(2, n, MOD);
  for (int i = 1; i < (1 << logM); i++) {
    if (bit_count(i) % 2 == 0) {
      ans = add(ans, powermod(2, dp[logM][i], MOD));
    } else {
      ans = sub(ans, powermod(2, dp[logM][i], MOD));
    }
  }
  cout << ans;
  return 0;
}
