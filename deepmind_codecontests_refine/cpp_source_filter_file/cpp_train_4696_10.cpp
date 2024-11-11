#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}
int main() {
  long long a, b, x, y, mini;
  cin >> a >> b >> x >> y;
  int div = gcd(x, y);
  x = x / div;
  y = y / div;
  if (a / x > b / y)
    mini = b / y;
  else
    mini = a / x;
  cout << mini;
  return 0;
}
