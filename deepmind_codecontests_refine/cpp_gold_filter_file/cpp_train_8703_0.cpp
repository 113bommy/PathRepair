#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int mod = 1e9 + 7;
const int N = 2e6 + 10;
const long long INF = 1e18;
long long power(long long x, long long y, long long mod) {
  long long t = 1;
  while (y > 0) {
    if (y % 2)
      y -= 1, t = t * x % mod;
    else
      y /= 2, x = x * x % mod;
  }
  return t % mod;
}
int main() {
  int l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  while (l <= r && x <= y) {
    double curr = double(double(l) / double(x));
    if (curr == k) {
      cout << "YES" << endl;
      return 0;
    }
    if (curr > k)
      x++;
    else
      l++;
  }
  cout << "NO" << endl;
  return 0;
}
