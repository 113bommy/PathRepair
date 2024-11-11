#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
  cin >> n >> t;
  if (n == 1 && t == 10) {
    cout << -1;
    return 0;
  }
  if (t == 2) {
    for (int i = 0; i < n - 1; i++) {
      cout << 9;
    }
    cout << 2;
    return 0;
  }
  if (t == 3) {
    for (int i = 0; i < n - 1; i++) {
      cout << 9;
    }
    cout << 3;
    return 0;
  }
  if (t == 4) {
    for (int i = 0; i < n - 1; i++) {
      cout << 4;
    }
    cout << 4;
    return 0;
  }
  if (t == 5) {
    for (int i = 0; i < n - 1; i++) {
      cout << 9;
    }
    cout << 5;
    return 0;
  }
  if (t == 6) {
    for (int i = 0; i < n - 1; i++) {
      cout << 9;
    }
    cout << 6;
    return 0;
  }
  if (t == 7) {
    for (int i = 0; i < n - 1; i++) {
      cout << 7;
    }
    cout << 7;
    return 0;
  }
  if (t == 8) {
    for (int i = 0; i < n - 1; i++) {
      cout << 8;
    }
    cout << 8;
    return 0;
  }
  if (t == 9) {
    for (int i = 0; i < n - 1; i++) {
      cout << 9;
    }
    cout << 9;
    return 0;
  }
  if (t == 10) {
    for (int i = 0; i < n - 1; i++) {
      cout << 9;
    }
    cout << 0;
    return 0;
  }
  return 0;
}
