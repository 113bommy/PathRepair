#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  long long a, b, x, y, d;
  cin >> a >> b >> x >> y;
  d = gcd(x, y);
  x /= d;
  y /= d;
  cout << min(a / x, b / y);
}
