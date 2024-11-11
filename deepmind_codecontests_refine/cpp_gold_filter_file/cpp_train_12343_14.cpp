#include <bits/stdc++.h>
using namespace std;
int main() {
  int a00, a01, a10, a11;
  cin >> a00 >> a01 >> a10 >> a11;
  int n1 = sqrt(2 * a00) + 1;
  int n2 = sqrt(2 * a11) + 1;
  (n1 < n2 ? n1 : n2) -= (!a01 && !a10);
  if ((n1 * (n1 - 1)) / 2 != a00 || (n2 * (n2 - 1)) / 2 != a11 ||
      n1 * n2 != a01 + a10) {
    cout << "Impossible";
  } else {
    for (int i = n1 + n2; i > 0; --i) {
      if (a01 >= n2) {
        cout << 0;
        a01 -= n2;
      } else {
        cout << 1;
        n2--;
      }
    }
  }
  return 0;
}
