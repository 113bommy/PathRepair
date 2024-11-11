#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c = 0;
  cin >> a >> b;
  if (a >= b) {
    cout << b << " ";
    c = a - b;
    if ((c) % 2 == 0) {
      cout << c / 2;
    } else {
      cout << (c - 1) / 2;
    }
  } else {
    cout << a << " ";
    c = b - a;
    if (c % 2 == 0) {
      cout << c / 2;
    } else {
      cout << (c - 1) / 2;
    }
  }
}
