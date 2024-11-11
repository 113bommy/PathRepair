#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  long long a, b;
  while (cin >> a >> b) {
    long long x, y;
    if (a > b) {
      x = a;
      y = b;
    } else {
      x = b;
      y = a;
    }
    long long tem = gcd(x, y);
    tem = x * y / tem;
    long long p = tem / a;
    long long q = tem / b;
    if (p > q)
      p--;
    else
      p--;
    if (q > p)
      cout << "Masha" << endl;
    else if (q < p)
      cout << "Dasha" << endl;
    else
      cout << "Equal" << endl;
  }
  return 0;
}
