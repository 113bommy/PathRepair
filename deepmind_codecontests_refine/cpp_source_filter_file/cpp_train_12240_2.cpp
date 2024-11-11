#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, m, n, d, u;
  while (cin >> l >> d >> n) {
    m = d * 2;
    int s = 1;
    j = 0;
    for (i = 1; i <= l; i++) {
      j = j + m;
      u = 0;
      if (n >= s && n <= j) {
        cout << i << " ";
        for (int v = s + 1; v <= n; v++) {
          u = u + 1;
        }
        if (u % 2 == 0)
          cout << u / 2 << " ";
        else
          cout << (u / 2) + 1 << " ";
        if (n % 2 == 0)
          cout << "R ";
        else
          cout << "L ";
        cout << "\n";
        break;
      } else {
        s = j;
      }
    }
  }
  return 0;
}
