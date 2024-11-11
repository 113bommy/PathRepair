#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a - b > 1) {
      cout << "NO" << endl;
    } else {
      c = a + b;
      if (c % 2 == 0 && c != 2) {
        while (c % 2 == 0) {
          c = c / 2;
        }
      }
      for (int64_t i = 3; i * i <= c; i += 2) {
        if (c % i == 0) {
          while (c % i == 0) {
            c = c / i;
          }
        }
      }
      if (c != (a + b)) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}
