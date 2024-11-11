#include <bits/stdc++.h>
using namespace std;
unsigned long long x, k, mod = 1e9 + 7;
unsigned long long expo(unsigned long long b, unsigned long long e) {
  if (e == 1) return b;
  if (e == 0) return (unsigned long long)1;
  unsigned long long r = expo(b, e / 2);
  r = (r * r) % mod;
  if (e % 2 == 1) {
    r = (r * b) % mod;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> x >> k;
  if (x == 0) {
    cout << 0 << endl;
    return 0;
  }
  cout << (expo(2, k + 1) * (x % mod) - expo(2, k) + 1 + 3 * mod) % mod;
  return 0;
}
