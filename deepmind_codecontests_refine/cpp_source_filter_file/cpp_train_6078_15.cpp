#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int>::max();
const int mod = 1000 * 1000 * 1000 + 7;
long long qpow_mod(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    p >>= 1;
  }
  return res;
}
int main() {
  int n, k;
  while (cin >> n >> k) {
    if (k == 1) {
      cout << qpow_mod(n - k, n - k) << endl;
    } else {
      cout << qpow_mod(k, k - 1) * qpow_mod(n - k, n - k) << endl;
    }
  }
  return 0;
}
