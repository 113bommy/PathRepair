#include <bits/stdc++.h>
using namespace std;
int a, b, x, y;
void check() {
  if (b == 0) {
    cout << x << ' ' << y << endl;
  }
  b--;
}
void up() {
  y++;
  check();
}
void down() {
  y--;
  check();
}
void right() {
  x++;
  check();
}
void left() {
  x--;
  check();
}
void urd(int);
void dlu(int);
void ldr(int);
void rul(int n) {
  if (n > 0) {
    urd(n - 1);
    right();
    rul(n - 1);
    up();
    rul(n - 1);
    left();
    dlu(n - 1);
  }
}
void urd(int n) {
  if (n > 0) {
    rul(n - 1);
    up();
    urd(n - 1);
    right();
    urd(n - 1);
    down();
    ldr(n - 1);
  }
}
void ldr(int n) {
  if (n > 0) {
    dlu(n - 1);
    left();
    ldr(n - 1);
    down();
    ldr(n - 1);
    right();
    urd(n - 1);
  }
}
void dlu(int n) {
  if (n > 0) {
    ldr(n - 1);
    down();
    dlu(n - 1);
    left();
    dlu(n - 1);
    up();
    rul(n - 1);
  }
}
int main() {
  cin >> a >> b;
  check();
  urd(a);
  return 0;
}
