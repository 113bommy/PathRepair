#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:500000000")
using namespace std;
const int mod = 1000000009;
int modpow(int a, int n, int mod) {
  int b = 1;
  while (n > 0) {
    if (n & 1) b = (long long)b * a % mod;
    n >>= 1;
    a = (long long)a * a % mod;
  }
  return b;
}
int main() {
  int n, m, i, j;
  cin >> n >> m;
  int mm = modpow(2, m, mod);
  int res = 1;
  if (m < 40 && n >= (1ll << m))
    puts("0");
  else {
    for (i = 1; i <= n; i++) {
      res = (long long)res * ((mm - i + mod) % mod);
    }
    cout << res << endl;
  }
}
