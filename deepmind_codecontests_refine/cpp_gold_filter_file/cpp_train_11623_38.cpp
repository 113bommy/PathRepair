#include <bits/stdc++.h>
using namespace std;
void car(int a, int b, int c, int m) {
  int s, p, d;
  s = c;
  if (m > 2 * c) {
    cout << -1;
  } else if (2 * m < c) {
    cout << -1;
  } else if (m > c) {
    s = m;
    p = b;
    if (b > 2 * m) {
      p = b;
      if (2 * a > p) {
        d = 2 * a;
        cout << d << "\n" << p << "\n" << s;
      } else {
        cout << -1;
      }
    } else if (2 * b > 2 * m) {
      p = 2 * m + 1;
      if (2 * a > p) {
        d = 2 * a;
        cout << d << "\n" << p << "\n" << s;
      } else {
        cout << -1;
      }
    } else {
      cout << -1;
    }
  } else {
    s = c;
    p = b;
    if (b > 2 * m) {
      p = b;
      if (2 * a > p) {
        d = 2 * a;
        cout << d << "\n" << p << "\n" << s;
      } else {
        cout << -1;
      }
    } else if (2 * b > 2 * m) {
      p = 2 * m + 1;
      if (2 * a > p) {
        d = 2 * a;
        cout << d << "\n" << p << "\n" << s;
      } else {
        cout << -1;
      }
    } else {
      cout << -1;
    }
  }
}
int main() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  car(a, b, c, m);
}
