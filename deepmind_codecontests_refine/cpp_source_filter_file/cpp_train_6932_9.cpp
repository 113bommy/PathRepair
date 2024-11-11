#include <bits/stdc++.h>
using namespace std;
long long a, b, c, x, y, d;
void ex_gcd(long long a, long long b) {
  if (b == 0) {
    d = a, x = 1, y = 0;
    return;
  }
  ex_gcd(b, a % b);
  long long t = x;
  x = y, y = t - a / b * y;
}
int main() {
  cin >> a >> b >> c;
  ex_gcd(a, b);
  if (c % d != 0) {
    cout << -1;
    return 0;
  }
  cout << -x / d * c << " " << -y / d * c;
  return 0;
}
