#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int z = c / 4;
  while (a >= 0) {
    z = a;
    if (b >= z * 2) {
      b = z * 2;
      if (c >= z * 4) {
        c = z * 4;
        cout << z + b + c << endl;
        break;
      }
    }
    a--;
    if (a == 0) cout << 0;
  }
}
