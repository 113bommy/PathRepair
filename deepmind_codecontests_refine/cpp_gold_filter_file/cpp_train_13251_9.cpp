#include <bits/stdc++.h>
using namespace std;
int a4, a7, a47, a74;
int main() {
  int n;
  cin >> a4 >> a7 >> a47 >> a74;
  if (abs(a47 - a74) > 1) {
    cout << -1;
    return 0;
  }
  if (a47 == a74) {
    if (!((a4 >= a47) && (a7 > a47)) && !((a4 > a47) && (a7 >= a47))) {
      cout << -1;
      return 0;
    }
  }
  if ((a47 > a74) && (min(a4, a7) < a47)) {
    cout << -1;
    return 0;
  }
  if ((a47 < a74) && (min(a4, a7) < a74)) {
    cout << -1;
    return 0;
  }
  if (a47 == a74) {
    if (a4 == a47) {
      for (int i = 0; i < a74; i++) {
        cout << 74;
      }
      for (int i = 0; i < a7 - a74; i++) {
        cout << 7;
      }
    } else {
      for (int i = 0; i < a4 - a47; i++) {
        cout << 4;
      }
      for (int i = 0; i < a74 - 1; i++) {
        cout << 74;
      }
      for (int i = 0; i < a7 - a74; i++) {
        cout << 7;
      }
      cout << 74;
    }
  }
  if (a47 > a74) {
    for (int i = 0; i < a4 - a47; i++) {
      cout << 4;
    }
    for (int i = 0; i < a47; i++) {
      cout << 47;
    }
    for (int i = 0; i < a7 - a47; i++) {
      cout << 7;
    }
  }
  if (a47 < a74) {
    cout << 74;
    for (int i = 0; i < a4 - a74; i++) {
      cout << 4;
    }
    for (int i = 0; i < a74 - 2; i++) {
      cout << 74;
    }
    for (int i = 0; i < a7 - a74; i++) {
      cout << 7;
    }
    cout << 74;
  }
  return 0;
}
