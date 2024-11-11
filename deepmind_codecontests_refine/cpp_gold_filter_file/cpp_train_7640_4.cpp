#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long mod = 1000000007;
long long expMod(long long base, long long exponente) {
  long long res = 1;
  while (exponente > 0) {
    if ((exponente & 1) != 0) {
      res *= base;
      res %= mod;
    }
    base *= base;
    base %= mod;
    exponente >>= 1;
  }
  return res;
}
long long invMod(long long n) { return expMod(n, mod - 2); }
long long n, m, g;
const long long maxN = 100000;
const long long maxG = 1;
void read() { cin >> n >> m >> g; }
long long c[500005];
void getCombi() {
  for (long long k = 0; k <= m - 2; k++) c[k] = 0;
  c[m - 1] = 1;
  for (long long k = m; k <= 500000; k++) {
    c[k] = c[k - 1] * k;
    c[k] %= mod;
    c[k] *= invMod(k - m + 1);
    c[k] %= mod;
  }
}
long long dp[maxN + 1][2];
void getDP() {
  if (m > 1) {
    dp[0][0] = 1;
    dp[0][1] = 0;
  } else {
    dp[0][0] = 0;
    dp[0][1] = 1;
  }
  for (long long k = 1; k <= n; k++) {
    dp[k][0] = c[k + m - 1] + dp[k - 1][1];
    dp[k][0] %= mod;
    dp[k][1] = dp[k - 1][0];
    dp[k][1] %= mod;
  }
}
void solve() {
  if (m == 0) {
    if (n % 2 == 1) {
      if (g == 0) {
        cout << 1 << endl;
        return;
      } else {
        cout << 0 << endl;
        return;
      }
    } else if (n % 2 == 0) {
      if (g == 1) {
        cout << 1 << endl;
        return;
      } else {
        cout << 0 << endl;
        return;
      }
    }
    return;
  }
  getCombi();
  getDP();
  cout << dp[n][g] << endl;
  return;
}
int main() {
  read(), solve();
  return 0;
}
