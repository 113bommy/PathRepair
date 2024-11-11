#include <bits/stdc++.h>
using namespace std;
long long nod(long long a, long long b) {
  while (a != 0 && b != 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}
signed main() {
  long long a, b, x, y;
  cin >> a >> b >> x >> y;
  int l = nod(x, y);
  x /= l;
  y /= l;
  cout << min(a / x, b / y);
  return 0;
}
