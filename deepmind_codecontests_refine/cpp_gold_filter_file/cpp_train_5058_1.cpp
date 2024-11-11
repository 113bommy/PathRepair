#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  int x = 0, y = 0;
  int ax = 0;
  int ay = 9999999999;
  int bx = 0;
  int by = 9999999999;
  for (int i = 0; i < t; i++) {
    cin >> x >> y;
    if (x > ax) {
      ax = x;
    }
    if (y < ay) {
      ay = y;
    }
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x >> y;
    if (x > bx) {
      bx = x;
    }
    if (y < by) {
      by = y;
    }
  }
  int M1 = bx - ay;
  int M2 = ax - by;
  if (M1 < M2) {
    if (M2 < 0) {
      cout << 0 << endl;
    } else
      cout << M2 << endl;
  } else if (M1 >= M2) {
    if (M1 < 0) {
      cout << 0 << endl;
    } else
      cout << M1 << endl;
  }
}
