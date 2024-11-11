#include <bits/stdc++.h>
const double EPS = 0.00000001;
const long long mod = 1000000000 + 7;
using namespace std;
long long powMod(long long x, long long n) {
  long long ans = 1;
  while (n) {
    if (n % 2) ans = (ans * x) % mod;
    x = (x * x) % mod;
    n /= 2;
  }
  return ans;
}
int n, m;
int a[100020], b[100020];
long long dp[100020];
long long f(int i) {
  if (i == n) return 0;
  if (dp[i] != -1) return dp[i];
  long long ans = 0;
  if (a[i] > 0 && b[i] > 0) {
    if (a[i] == b[i])
      ans = f(i + 1);
    else if (a[i] > b[i])
      ans = 1;
    else
      ans = 0;
  } else if (a[i] == 0 && b[i] == 0) {
    long long r1 = (m * (m - 1)) % mod;
    r1 = (r1 * powMod(2, mod - 2)) % mod;
    r1 = (r1 * (powMod((m * m) % mod, mod - 2))) % mod;
    long long r2 = (powMod(m, mod - 2) * f(i + 1)) % mod;
    ans = (r1 + r2) % mod;
  } else if (a[i] == 0) {
    long long r1 = ((m - b[i]) * powMod(m, mod - 2)) % mod;
    long long r2 = (powMod(m, mod - 2) * f(i + 1)) % mod;
    ans = (r1 + r2) % mod;
  } else if (b[i] == 0) {
    long long r1 = ((a[i] - 1) * powMod(m, mod - 2)) % mod;
    long long r2 = (powMod(m, mod - 2) * f(i + 1)) % mod;
    ans = (r1 + r2) % mod;
  }
  return dp[i] = ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  memset(dp, -1, sizeof(dp));
  cout << f(0) << endl;
  return 0;
}
