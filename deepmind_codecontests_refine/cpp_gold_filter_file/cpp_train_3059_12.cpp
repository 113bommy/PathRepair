#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, p, c, d, e, j, i, t, l, n, m;
  cin >> p;
  a = 0;
  b = 1;
  for (i = 1; i < p; i++) {
    b = 1;
    for (j = 1; j <= p - 1; j++) {
      b = (b * i) % p;
      if (j < p - 1) {
        if ((b - 1) % p == 0) {
          break;
        }
      } else {
        if ((b - 1) % p == 0) {
          a++;
        }
      }
    }
  }
  cout << a;
  return 0;
}
