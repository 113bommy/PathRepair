#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long _pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  long long x, k;
  cin >> x >> k;
  if (!x) {
    cout << "0" << endl;
    return 0;
  }
  long long n = k + 1;
  x %= mod;
  x = (x * _pow((long long)2, n));
  long long m = _pow((long long)2, k);
  long long ans = (1 - m) / -1;
  if (x - ans > 0)
    cout << (x - ans) % mod << endl;
  else
    cout << (x - ans) % mod + mod << endl;
  return 0;
}
