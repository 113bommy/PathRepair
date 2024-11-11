#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, p, q, i;
  cin >> a >> b >> c >> d;
  if ((a * d) > (b * c)) {
    p = a * d - b * c;
    q = a * d;
    for (i = 2; i <= p && i <= q; i++) {
      if (p % i == 0 && q % i == 0) {
        p /= i;
        q /= i;
        i = 2;
      }
    }
  } else if ((a * d) < (b * c)) {
    p = b * c - a * d;
    q = b * c;
    for (i = 2; i <= p && i <= q; i++) {
      if (p % i == 0 && q % i == 0) {
        p /= i;
        q /= i;
        i = 1;
      }
    }
  } else {
    p = 0;
    q = 1;
  }
  cout << p << "/" << q;
  return 0;
}
