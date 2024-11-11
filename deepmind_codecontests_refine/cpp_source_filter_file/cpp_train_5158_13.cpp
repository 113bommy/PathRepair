#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int x, y, k,
      counter = 0, m, n, a1 = 4, a2 = 9, b1 = 3, b2 = 8, c1 = 2, c2 = 7, d1 = 5,
      d2 = 10, e1 = 1, e2 = 6, a = 0, b = 0, c = 0, d = 0, e = 0;
  cin >> x >> y;
  if (a1 <= y) {
    a++;
  }
  if (a2 <= y) {
    a++;
  }
  if (b1 <= y) {
    b++;
  }
  if (b2 <= y) {
    b++;
  }
  if (c1 <= y) {
    c++;
  }
  if (c2 <= y) {
    c++;
  }
  if (d1 <= y) {
    d++;
  }
  if (d2 <= y) {
    d++;
  }
  if (e1 <= y) {
    e++;
  }
  if (e2 <= y) {
    e++;
  }
  for (int i = 0; i <= y; i++) {
    if (a1 + 10 <= y) {
      a++;
      a1 = a1 + 10;
    }
    if (a2 + 10 <= y) {
      a++;
      a2 = a2 + 10;
    }
    if (b1 + 10 <= y) {
      b++;
      b1 = b1 + 10;
    }
    if (b2 + 10 <= y) {
      b++;
      b2 = b2 + 10;
    }
    if (c1 + 10 <= y) {
      c++;
      c1 = c1 + 10;
    }
    if (c2 + 10 <= y) {
      c++;
      c2 = c2 + 10;
    }
    if (d1 + 10 <= y) {
      d++;
      d1 = d1 + 10;
    }
    if (d2 + 10 <= y) {
      d++;
      d2 = d2 + 10;
    }
    if (e1 + 10 <= y) {
      e++;
      e1 = e1 + 10;
    }
    if (e2 + 10 <= y) {
      e++;
      e2 = e2 + 10;
    }
  }
  for (int i = 1; i <= x; i++) {
    m = i % 5;
    if (m == 1) counter += a;
    if (m == 2) counter += c;
    if (m == 3) counter += b;
    if (m == 4) counter += e;
    if (m == 0) counter += d;
  }
  cout << counter;
}
