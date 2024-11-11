#include <bits/stdc++.h>
using namespace std;
long double A[9];
int main() {
  long double x, y, z;
  cin >> x >> y >> z;
  long double num[3];
  num[0] = x, num[1] = y, num[2] = z;
  sort(num, num + 3);
  if (num[1] <= 1.0) {
    A[0] = powl(x, powl(y, z));
    A[1] = powl(x, powl(y, z));
    A[2] = powl(x, y * z);
    A[3] = powl(y, powl(x, z));
    A[4] = powl(y, powl(z, x));
    A[5] = powl(y, x * z);
    A[6] = powl(z, powl(x, y));
    A[7] = powl(z, powl(y, x));
    A[8] = powl(z, x * y);
  } else {
    if (x <= 1.0) {
      A[0] = A[1] = A[2] = -1e9;
    } else {
      y <= 1.0 ? A[0] = -1e9 : A[0] = z * logl(y) + logl(logl(x));
      z <= 1.0 ? A[1] = -1e9 : A[1] = y * logl(z) + logl(logl(x));
      z* y <= 1.0 ? A[2] = -1e9 : A[2] = logl(z * y) + logl(logl(x));
    }
    if (y <= 1.0) {
      A[3] = A[4] = A[5] = -1e9;
    } else {
      x <= 1.0 ? A[3] = -1e9 : A[3] = z * logl(x) + logl(logl(y));
      z <= 1.0 ? A[4] = -1e9 : A[4] = x * logl(z) + logl(logl(y));
      x* z <= 1.0 ? A[5] = -1e9 : A[5] = logl(x * z) + logl(logl(y));
    }
    if (z <= 1.0) {
      A[6] = A[7] = A[8] = -1e9;
    } else {
      x <= 1.0 ? A[6] = -1e9 : A[6] = y * logl(x) + logl(logl(z));
      y <= 1.0 ? A[7] = -1e9 : A[7] = x * logl(y) + logl(logl(z));
      x* y <= 1.0 ? A[8] = -1e9 : A[8] = logl(x * y) + logl(logl(z));
    }
  }
  auto it = max_element(A, A + 9);
  if (it - A == 0) {
    printf("%c^%c^%c\n", 'x', 'y', 'z');
  } else if (it - A == 1) {
    printf("%c^%c^%c\n", 'x', 'z', 'y');
  } else if (it - A == 2) {
    printf("(%c^%c)^%c\n", 'x', 'y', 'z');
  } else if (it - A == 3) {
    printf("%c^%c^%c\n", 'y', 'x', 'z');
  } else if (it - A == 4) {
    printf("%c^%c^%c\n", 'y', 'z', 'x');
  } else if (it - A == 5) {
    printf("(%c^%c)^%c\n", 'y', 'x', 'z');
  } else if (it - A == 6) {
    printf("%c^%c^%c\n", 'z', 'x', 'y');
  } else if (it - A == 7) {
    printf("%c^%c^%c\n", 'z', 'y', 'x');
  } else {
    printf("(%c^%c)^%c\n", 'z', 'x', 'y');
  }
  return 0;
}
