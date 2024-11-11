#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int a, b, c, d, e, f, g;
  cin >> a >> b;
  d = a + b;
  if (a == b && a == 1)
    cout << '0';
  else {
    for (c = 1; c <= d; c++) {
      if (a <= b) {
        a = a + 1, b = b - 2;
        if (a <= 0 || b <= 0) break;
      } else if (b < a) {
        b++;
        a = a - 2;
      }
      if (a <= 0 || b <= 0) break;
    }
    cout << c;
  }
  return 0;
}
