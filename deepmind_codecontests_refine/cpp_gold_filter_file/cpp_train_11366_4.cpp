#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int k = 1;
  int a, b, n;
  cin >> a >> b >> n;
  int f = 0;
  int r = n;
  for (int i = 1; i <= n + 1; i++) {
    if (i % 2 == 0)
      f = gcd(r, b);
    else if (i % 2 != 0)
      f = gcd(r, a);
    if (f > r && i % 2 == 0) {
      cout << "0";
      k = 0;
      break;
    } else if (f > r && (i % 2 != 0)) {
      k = 1;
      break;
    }
    r = r - f;
  }
  if (k == 1) cout << k;
  return 0;
}
