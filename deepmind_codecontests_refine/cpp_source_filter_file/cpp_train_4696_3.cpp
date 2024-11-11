#include <bits/stdc++.h>
using namespace std;
long long cmmdc(long long a, long long b) {
  long long r;
  while (a > 0) {
    r = b % a;
    b = a;
    a = r;
  }
  return b;
}
int main() {
  long long a, b, x, y;
  cin >> a >> b >> x >> y;
  int xy = cmmdc(x, y);
  x /= xy;
  y /= xy;
  cout << min(a / x, b / y);
}
