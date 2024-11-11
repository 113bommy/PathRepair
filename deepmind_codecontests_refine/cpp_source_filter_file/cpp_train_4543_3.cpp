#include <bits/stdc++.h>
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1000000;
const long long MOD = 1e9 + 7;
using namespace std;
long long bin_pow(long long a, long long b) {
  if (!b) return 1;
  long long ans = bin_pow(a, b / 2);
  ans = ans * ans % MOD;
  if (b % 2) ans = ans * a % MOD;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  if (n == 1 && m == 1) {
    cout << 1 << '\n';
    return 0;
  }
  if (n == 1 || m == 1) {
    if (k == 1)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
    return 0;
  }
  if (k == -1 && n % 2 != m % 2) {
    cout << 0 << '\n';
    return 0;
  }
  n = (n - 1) % (MOD);
  m = (m - 1) % (MOD);
  n = n * m;
  cout << bin_pow(2LL, n) << '\n';
  return 0;
}
