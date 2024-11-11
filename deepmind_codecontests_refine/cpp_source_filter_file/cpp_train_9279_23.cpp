#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const long long MOD = 1e9 + 7;
long long n_bits(long long n) {
  long long x = __builtin_popcount(n);
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    long long n, x, y, k = 0;
    cin >> n >> x >> y;
    k = y - n + 1;
    if (k < 0 || k * k + (n - 1) < x)
      cout << -1;
    else {
      cout << k << endl;
      for (long long i = 0; i < (n - 1); i++) {
        cout << 1 << endl;
      }
    }
  }
  return 0;
}
