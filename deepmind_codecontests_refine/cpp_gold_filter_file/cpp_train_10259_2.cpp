#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e8;
using namespace std;
long long qpow(long long a, long long b) {
  long long res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  long long a, b, n, x;
  cin >> a >> b >> n >> x;
  if (a != 1)
    cout << (x % mod * qpow(a, n) +
             b % mod * ((1 - qpow(a, n)) % mod * qpow(1 - a, mod - 2) % mod) %
                 mod) %
                mod
         << endl;
  else
    cout << (x % mod + n % mod * b % mod) % mod << endl;
  return 0;
}
