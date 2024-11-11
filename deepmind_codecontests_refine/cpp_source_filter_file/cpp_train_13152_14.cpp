#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n1, x, y, z, c1, c2, n2, n3, n4, f1, f2;
  cin >> n1 >> x >> y >> z;
  int c, m1, m2, m3;
  f1 = 0;
  f2 = 0;
  m1 = min(min(x, y), z);
  m3 = max(max(x, y), z);
  if ((m1 == z && m3 == y) || (m1 == y && m3 == z)) {
    m2 = x;
  }
  if ((m1 == x && m3 == y) || (m1 == y && m3 == x)) {
    m2 = z;
  }
  if ((m1 == z && m3 == x) || (m1 == x && m3 == z)) {
    m2 = y;
  }
  if (n1 % m1 == 0) {
    cout << n1 / m1;
    return 0;
  } else {
    n2 = n1 - (n1 % m1);
    c = (n1 - (n1 % m1)) / m1;
  }
  n3 = n2;
  n4 = n2;
  c1 = c;
  c2 = c;
  for (;;) {
    if (f1 == 0) {
      if (n2 == 0) {
        f1++;
      }
      if (((n1 - n2) % m2) == 0) {
        c = c + (n1 - n2) / m2;
        f1++;
      } else {
        n2 = n2 - m1;
        c--;
      }
    }
    if (f2 == 0) {
      if (n3 == 0) {
        f2++;
      }
      if ((n1 - n3) % m3 == 0) {
        c1 = c1 + (n1 - n3) / m3;
        f2++;
      } else {
        n3 = n3 - m1;
        c1--;
      }
    }
    if (f1 > 0 && f2 > 0) {
      break;
    }
  }
  for (;;) {
    for (i = 1;; i++) {
      if ((n1 - (n4 + m2 * i)) % m3 == 0 && ((n1 - (n4 + m2 * i)) / m3) >= 1) {
        c2 = c2 + (n1 - (n4 + m2 * i)) / m3 + i;
        cout << max(max(c, c1), c2);
        return 0;
      }
      if (m2 * i > n4) {
        goto loop;
      }
    }
  loop:
    i = 1;
    n4 = n4 - m1;
    c2--;
    if (n4 == 0) {
      break;
    }
  }
  cout << max(c, c1);
}
