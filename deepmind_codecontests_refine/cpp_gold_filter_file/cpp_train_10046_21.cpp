#include <bits/stdc++.h>
using namespace std;
int mn(int x, int y) {
  if (x <= y) return x;
  return y;
}
int mx(int x, int y) {
  if (x >= y) return x;
  return y;
}
int main() {
  int n, x1, x2, y1, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  if (x1 == 0) {
    if (x2 == 0) {
      cout << mx(y1, y2) - mn(y1, y2);
      return 0;
    }
    if (x2 == n) {
      cout << mn(n - y1 + n + n - y2, y1 + n + y2);
      return 0;
    }
    if (y2 == 0) {
      cout << x2 + y1;
      return 0;
    }
    if (y2 == n) {
      cout << x2 + n - y1;
      return 0;
    }
  }
  if (x1 == n) {
    if (x2 == n) {
      cout << mx(y1, y2) - mn(y1, y2);
      return 0;
    }
    if (x2 == 0) {
      cout << mn(n - y1 + n + n - y2, y1 + n + y2);
      return 0;
    }
    if (y2 == 0) {
      cout << n - x2 + y1;
      return 0;
    }
    if (y2 == n) {
      cout << n - x2 + n - y1;
      return 0;
    }
  }
  if (y1 == 0) {
    if (y2 == 0) {
      cout << mx(x1, x2) - mn(x1, x2);
      return 0;
    }
    if (y2 == n) {
      cout << mn(n - x1 + n + n - x2, x1 + n + x2);
      return 0;
    }
    if (x2 == 0) {
      cout << y2 + x1;
      return 0;
    }
    if (x2 == n) {
      cout << y2 + n - x1;
      return 0;
    }
  }
  if (y1 == n) {
    if (y2 == n) {
      cout << mx(x1, x2) - mn(x1, x2);
      return 0;
    }
    if (y2 == 0) {
      cout << mn(n - x1 + n + n - x2, x1 + n + x2);
      return 0;
    }
    if (x2 == 0) {
      cout << n - y2 + x1;
      return 0;
    }
    if (x2 == n) {
      cout << n - y2 + n - x1;
      return 0;
    }
  }
}
