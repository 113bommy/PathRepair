#include <bits/stdc++.h>
using namespace std;
long long x, y, mod = 1000000007;
long long go() {
  long long res = 1, t = 2;
  while (y) {
    if (y % 2) res = (res * t) % mod;
    t = (t * t) % mod;
    y /= 2;
  }
  return res;
}
int main() {
  cin >> x >> y;
  if (!x) return !(cout << "0");
  cout << (go() * (2 * x % mod - 1) + 1) % mod;
  return 0;
}
