#include <bits/stdc++.h>
const long long MOD = 1000000007;
inline void normal(long long int& a) { a = (a + MOD) % MOD; }
inline int modMul(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline int modAdd(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline int modSub(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline int modPow(long long int b, long long int p) {
  long long int r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline int modInv(long long int a) { return modPow(a, MOD - 2); }
inline int modDiv(long long int a, long long int b) {
  return modMul(a, modInv(b));
}
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, a, b;
    cin >> n >> a >> b;
    int x = 96;
    string out;
    for (long long int i = 0; i < n; i++) {
      if (x == 96 + b) {
        x = 97;
      } else {
        x++;
      }
      out += (char)x;
    }
    cout << out << '\n';
  }
  return 0;
}
