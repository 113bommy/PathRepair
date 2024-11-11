#include <bits/stdc++.h>
using namespace std;
const int long long mod = 1e9 + 7;
long long n, m;
long long zps_ak_ioi;
long long quick_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2 == 1) {
      ans = ans % mod * a % mod;
    }
    a = a % mod * a % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    zps_ak_ioi = zps_ak_ioi % mod +
                 quick_pow(m, i) % mod * quick_pow((2 * m - 1), n - i) % mod;
  }
  cout << zps_ak_ioi % mod + quick_pow(m, n) % mod;
  return 0;
}
