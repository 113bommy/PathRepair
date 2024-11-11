#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, d1;
  int b, d2, i;
  cin >> d1 >> a >> d2 >> b;
  int n, m, KK;
  KK = max(max(a, b), max(d1, d2));
  n = 0;
  while (true) {
    if (n > KK) {
      cout << -1;
      return 0;
    }
    m = 0;
    while ((b + m * d2) < (a + n * d1)) m++;
    if ((b + m * d2) == (a + n * d1)) {
      cout << b + m * d2;
      return 0;
    }
    n++;
  }
}
