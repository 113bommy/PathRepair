#include <bits/stdc++.h>
using namespace std;
long long n, x, y, p, q, a, b, res, r;
int main() {
  cin >> n >> a >> b >> p >> q;
  x = a;
  y = b;
  while (y != 0) {
    r = x % y;
    x = y;
    y = r;
  }
  long long bc = (a * b) / x;
  res = (n / a - n / bc) * p + (n / b - n / bc) * q + (n / bc) * max(p, q);
  cout << res;
}
