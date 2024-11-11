#include <bits/stdc++.h>
using namespace std;
int main() {
  int h1, h2, a, b;
  cin >> h1 >> h2 >> a >> b;
  int h = 14;
  int d = 0;
  int od;
  int nd = 0;
  while (h1 < h2) {
    if (h >= 10 && h < 22)
      h1 += a;
    else {
      h1 -= b;
    }
    if (h == 24) {
      od = nd;
      nd = h1;
      d++;
      h = 0;
      if (d == 3 && od >= nd) {
        cout << -1;
        return 0;
      }
      if (d > 25000) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << d;
  return 0;
}
