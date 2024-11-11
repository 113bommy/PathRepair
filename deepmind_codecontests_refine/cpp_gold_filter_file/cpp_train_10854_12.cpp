#include <bits/stdc++.h>
using namespace std;
const int c = 4e6 + 2, mod = 998244353;
long long n, m, sum = 1, inv[c];
int main() {
  cin >> n >> m, inv[1] = 1;
  for (int i = 2; i <= n + m; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    if (i <= n) sum += inv[i];
  }
  cout << (n * inv[m + 1] + 1) % mod * (sum % mod * m % mod + 1) % mod << "\n";
}
