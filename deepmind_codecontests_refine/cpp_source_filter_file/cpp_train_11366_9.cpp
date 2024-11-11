#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, q = 0, z = 0;
  cin >> a >> b >> n;
  for (int i = 0; n >= 0; ++i) {
    for (int j = a; j >= 1; --j) {
      if (b % j == 0 && n % j == 0) {
        q = n;
        n = n - j;
        break;
      }
    }
    if (n >= 0) {
      for (int c = b; c >= 1; --c) {
        if (a % c == 0 && n % c == 0) {
          z = n;
          n = n - c;
          break;
        }
      }
    }
  }
  if (z == 0) {
    cout << "0";
  }
  if (q == 0) {
    cout << "1";
  }
  return 0;
}
