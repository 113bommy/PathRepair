#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, fashiondays, normaldays;
  cin >> a >> b;
  if (a < b) {
    fashiondays = a;
    normaldays = (b - a);
  } else {
    fashiondays = b;
    normaldays = (a - b);
  }
  if (normaldays == 1) {
    cout << fashiondays << " " << 0;
  } else if (normaldays % 2 == 0) {
    cout << fashiondays << " " << normaldays / 2;
  } else {
    cout << fashiondays << " " << (normaldays / 2) - 1;
  }
}
