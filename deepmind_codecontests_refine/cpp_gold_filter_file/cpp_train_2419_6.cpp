#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, a, b, div = 0;
  cin >> c;
  for (int i = 0; i < c; i++) {
    cin >> a >> b;
    if (a % b == 0) {
      cout << 0 << endl;
    } else {
      div = a / b;
      div += 1;
      cout << (b * div) - a << endl;
    }
  }
  return 0;
}
