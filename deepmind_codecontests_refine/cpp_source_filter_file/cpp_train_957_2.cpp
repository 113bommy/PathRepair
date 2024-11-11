#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int T1, T2, X1, X2, T0, Y1, Y2, med, sup, inf;
  cin >> T1 >> T2 >> X1 >> X2 >> T0;
  Y1 = -1;
  Y2 = -1;
  if (T1 == T0) {
    if (T2 == T0) {
      cout << X1 << " " << X2 << endl;
    } else {
      cout << X1 << " " << 0 << endl;
    }
    return 0;
  }
  Y1 = 0;
  Y2 = 1;
  for (long long int i = 1; i <= X1; i++) {
    sup = X2;
    inf = -1;
    if ((T2 - T0) * sup - (T0 - T1) * i < 0) continue;
    while (inf + 1 != sup) {
      med = (inf + sup) / 2;
      if ((T2 - T0) * med - (T0 - T1) * i >= 0) {
        sup = med;
      } else {
        inf = med;
      }
    }
    if (Y1 == -1) {
      Y1 = i;
      Y2 = sup;
      continue;
    }
    if ((T1 * i + T2 * sup) * (Y1 + Y2) < (i + sup) * (T1 * Y1 + T2 * Y2)) {
      Y1 = i;
      Y2 = sup;
    } else {
      if ((T1 * i + T2 * sup) * (Y1 + Y2) == (i + sup) * (T1 * Y1 + T2 * Y2)) {
        if (i + sup > Y1 + Y2) {
          Y1 = i;
          Y2 = sup;
        }
      }
    }
  }
  cout << Y1 << " " << Y2 << endl;
  return 0;
}
