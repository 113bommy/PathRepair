#include <bits/stdc++.h>
using namespace std;
long long int const MOD = 1e9 + 7;
long long int fpow(long long int base, long long int power) {
  long long int res = 1;
  while (power) {
    if (power & 1) {
      res = (res * base) % MOD;
    }
    base = (base * base) % MOD;
    power >>= 1;
  }
  return res;
}
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  if (k > n && k < 2) {
    cout << fpow(m, n) << endl;
  } else if (k == n) {
    cout << fpow(m, (n + 1) / 2) << endl;
  } else {
    if (k & 1) {
      cout << fpow(m, 2) << endl;
    } else
      cout << m << endl;
  }
}
