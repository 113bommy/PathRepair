#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long i, j, k, n, t, y;
  long long mod = 998244353;
  cin >> n;
  long long total = n;
  for (i = 1; i <= n; i++) {
    total *= i;
    total %= mod;
  }
  int pre = 0;
  for (i = 2; i <= n; i++) {
    pre += 1;
    pre *= i;
    pre %= mod;
    if (i == n) {
      total -= pre;
      total += mod;
      total %= mod;
      break;
    }
  }
  cout << (mod + total) % mod;
  return 0;
}
