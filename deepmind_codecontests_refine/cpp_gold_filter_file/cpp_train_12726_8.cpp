#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int fastPower(long long x, int n) {
  long long result = 1;
  while (n != 0) {
    if ((n & 1) == 1) {
      result *= x;
      result %= mod;
    }
    x *= x;
    x %= mod;
    n >>= 1;
  }
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int N;
  cin >> N;
  while (N--) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      cout << 0 << '\n';
      continue;
    } else if (a == 2) {
      cout << b << '\n';
    } else {
      cout << b * 2 << '\n';
    }
  }
}
