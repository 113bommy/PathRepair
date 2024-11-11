#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a, b, c = 0;
  int shag;
  int minshag;
  cin >> n;
  minshag = n;
  for (int i = 1; i <= n / 2; ++i) {
    shag = 0;
    a = i;
    b = n - i;
    while (true) {
      if (a == 1) {
        shag += b;
        break;
      }
      if (b == 1) {
        shag += a;
        break;
      }
      if ((a % b == 0) || (b % a == 0)) {
        shag = 0;
        break;
      }
      if (a > b) {
        c = a / b;
        a = a - c * b;
        shag += c;
      } else {
        c = b / a;
        b = b - c * a;
        shag += c;
      }
    }
    if ((shag < minshag) && (shag != 0)) minshag = shag;
  }
  if (n == 1) minshag = 0;
  cout << minshag;
}
