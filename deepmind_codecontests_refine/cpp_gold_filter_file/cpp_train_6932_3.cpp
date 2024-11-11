#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b != 0) {
    d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
int main() {
  long long a, b, c, ans, x, y;
  cin >> a >> b >> c;
  ans = exgcd(a, b, x, y);
  if (c % ans != 0) {
    cout << "-1\n" << endl;
  } else {
    cout << x * (-c / ans) << " " << y * (-c / ans) << endl;
  }
  return 0;
}
