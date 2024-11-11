#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int arr[100009];
int main() {
  int a, c;
  cin >> a >> c;
  if (a < c or (c == 1 && a > 1)) {
    cout << "-1" << endl;
    return 0;
  }
  if (c == 2 or c == 1) {
    if (c == 1)
      cout << "a\n";
    else {
      for (int i = 0; i < a; i++) cout << (i & 1 ? "b" : "a");
      cout << "\n";
    }
  } else {
    c -= 2;
    for (int i = 0; i < a - c; i++) cout << (i & 1 ? "b" : "a");
    for (int i = 99; i < 99 + c; i++) cout << char(i);
    cout << "\n";
  }
  return 0;
}
