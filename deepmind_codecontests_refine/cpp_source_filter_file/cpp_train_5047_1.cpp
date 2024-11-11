#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  int c = 0;
  cin >> a >> b;
  if (a % b == 0) {
    cout << a / b;
  } else {
    for (;;) {
      if (a > b) {
        c += a / b;
        if (a % b == 0) {
          break;
        }
        a -= (a / b) * b;
      }
      if (b > a) {
        c += b / a;
        if (b % a == 0) {
          break;
        }
        b -= (b / a) * a;
      }
    }
  }
  if (c != 0) {
    cout << c;
  }
  return 0;
}
