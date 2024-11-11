#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x;
  cin >> a >> b >> x;
  if (x % 2 == 0) {
    if (a > b) {
      for (int i = 0; i < a - x / 2 - 1; i++) {
        cout << 0;
      }
      for (int i = 0; i < x; i++) {
        if (i % 2 == 0) {
          cout << 0;
        } else {
          cout << 1;
        }
      }
      for (int i = 0; i < b - x / 2; i++) {
        cout << 1;
      }
      cout << 0;
    } else {
      cout << 1;
      for (int i = 0; i < a - x / 2; i++) {
        cout << 0;
      }
      for (int i = 0; i < x; i++) {
        if (i % 2 == 0) {
          cout << 0;
        } else {
          cout << 1;
        }
      }
      for (int i = 0; i < b - x / 2 - 1; i++) {
        cout << 1;
      }
    }
  } else {
    for (int i = 0; i < a - (x + 1) / 2; i++) {
      cout << 0;
    }
    for (int i = 0; i < x + 1; i++) {
      if (i % 2 == 0) {
        cout << 0;
      } else {
        cout << 1;
      }
    }
    for (int i = 0; i < b - (x + 1) / 2; i++) {
      cout << 1;
    }
  }
  return 0;
}
