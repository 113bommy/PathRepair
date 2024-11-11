#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a;
  cin >> b;
  if (b > 15) {
    cout << 15;
    return 0;
  }
  for (int i = 0; i < a; i++) {
    cin >> c;
    if (c - b > 15) {
      cout << b + 15;
      return 0;
    } else {
      b = c;
    }
  }
  if (90 - c < 16) {
    cout << 90;
  } else {
    cout << c + 15;
  }
}
