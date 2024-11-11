#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9;
const long long dx[4] = {0, 1, 0, -1};
const long long dy[4] = {1, 0, -1, 0};
const long long K = 2;
long long mod_exp(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long t = mod_exp(a, b / 2, m);
  t = (t * t) % m;
  if (b & 1) t = (t * a) % m;
  return t;
}
long long mod_inv(long long a, long long m) { return mod_exp(a, m - 2, m); }
int main() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  long long ans =
      (mod_exp(2, n - 1, MOD) % MOD * (1 + mod_exp(2, n, MOD)) % MOD) % MOD;
  cout << ans % MOD << "\n";
  return 0;
}
