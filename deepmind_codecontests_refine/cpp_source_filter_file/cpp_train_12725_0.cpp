#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int epow(long long int b, long long int e, long long int m) {
  b %= m;
  long long int ans = 1;
  while (e > 0) {
    if (e & 1) {
      ans = (ans * b) % m;
    }
    b = (b * b) % m;
    e >>= 1;
  }
  return ans;
}
int main() {
  long long int n, m, l, r;
  cin >> n >> m >> l >> r;
  if ((n * m) % 2 == 1) {
    cout << epow(r - l + 1, n * m, mod) % mod << "\n";
  } else {
    long long int e = r / 2 - (l - 1) / 2;
    long long int o = (l - r + 1) - e;
    cout << (epow(e + o, m * n, mod) + epow(e - o, m * n, mod)) * (mod + 1) /
                2 % mod
         << "\n";
  }
  return 0;
}
