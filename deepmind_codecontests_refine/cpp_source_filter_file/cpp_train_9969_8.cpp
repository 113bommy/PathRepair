#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long double PI = acos(-1);
long long POWER[65];
long long power(long long x, long long y, long long mod) {
  long long res = 1;
  x %= mod;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    y >>= 1;
    x = (x * x) % mod;
  }
  return res;
}
long long inv(long long x, long long mod) { return power(x, mod - 2, mod); }
long long fastMul(long long a, long long b, long long mod) {
  long long res = 0;
  a %= mod;
  while (b) {
    if (b & 1) {
      res = (res + a) % mod;
    }
    a = (2 * a) % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  long long n;
  cin >> n;
  int A[12] = {4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};
  if (n < 12) {
    cout << A[n];
  } else {
    cout << (A[11] + (n - 12) * 49);
  }
  return 0;
}
