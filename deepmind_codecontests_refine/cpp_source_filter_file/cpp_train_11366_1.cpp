#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  int i;
  i = max(x, y);
  x = min(x, y);
  y = i;
  if (x == 0)
    return y;
  else {
    for (i = x; i > 0; i--) {
      if ((x % i) == 0 && (y % i) == 0) break;
    }
    return i;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int a, b, n;
  cin >> a >> b >> n;
  while (5) {
    if (n < gcd(a, n)) {
      cout << "0";
      break;
    }
    n -= gcd(a, n);
    if (n < gcd(b, n)) {
      cout << "1";
      break;
    }
    n -= gcd(b, n);
  }
}
