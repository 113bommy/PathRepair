#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long double PI = 3.14159265;
long long int powerWithMod(long long int base, long long int exponent,
                           long long int modulus = LLONG_MAX) {
  long long int result = 1;
  base %= modulus;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % modulus;
    exponent >>= 1;
    base = (base * base) % modulus;
  }
  return result;
}
long long int modInverse(long long int a, long long int m = MOD) {
  return powerWithMod(a, m - 2, m);
}
int n, m, c, x, y, xx, yy, p = MOD, q = MOD, r = MOD, s = MOD, h, key = -1,
                           val = MOD, curr;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> c;
  while (c--) {
    cin >> x >> y;
    xx = n - x;
    yy = m - y;
    p = min(p, x + y);
    q = min(q, x + yy);
    r = min(r, xx + y);
    s = min(s, xx + yy);
  }
  cin >> h;
  for (int i = 1; i <= h; i++) {
    cin >> x >> y;
    xx = n - x;
    yy = m - y;
    curr = x + y - p;
    curr = max(curr, x + yy - q);
    curr = max(curr, xx + y - r);
    curr = max(curr, xx + yy - s);
    if (val > curr) {
      val = curr;
      key = i;
    }
  }
  cout << val << "\n" << key << "\n";
  return 0;
}
