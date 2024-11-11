#include <bits/stdc++.h>
using namespace std;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
const long long mod = 1e9 + 7;
long long pw(long long b, long long p) {
  if (p == 1) return b;
  if (p == 0) return 1;
  long long ret = pw(b, p / 2) % mod;
  ret = (ret * ret) % mod;
  if (p % 2 == 1) ret = (ret * b) % mod;
  return ret;
}
int main() {
  long long n, k, a, b, q, p, x;
  while (cin >> a >> b >> n >> x) {
    if (a == 1)
      cout << ((x % mod) + (b % mod) * (n % mod)) % mod << endl;
    else {
      long long L = (pw(a, n) * x) % mod;
      long long R =
          (((pw(a, n) - 1) % mod) * (pw(a - 1, -1 + mod - 1) % mod)) % mod;
      R = (b * R) % mod;
      cout << (L + R) % mod << endl;
    }
  }
  return 0;
}
