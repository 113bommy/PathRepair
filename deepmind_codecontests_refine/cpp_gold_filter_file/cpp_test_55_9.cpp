#include <bits/stdc++.h>
using namespace std;
const int N = 300004, mod = 1e9 + 7;
int n;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b /= 2;
  }
  return ans;
}
int main() {
  cin >> n;
  cout << 6 * qpow(4, (1ll << n) - 2) % mod << endl;
  return 0;
}
