#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, i = 0;
  cin >> x >> y >> z;
  if (x % 2 == 0) {
    x = x / 2;
  } else {
    x = (x / 2) + 1;
  }
  if (y % 2 == 0) {
    y = y / 2;
  } else {
    y = (y / 2) + 1;
  }
  if (z % 2 == 0) {
    z /= 2;
  } else {
    z = (z / 2) + 1;
  }
  int t1 = 0, t2 = 1, t3 = 2;
  for (int i = 0; i < x; i++) {
    if (i) {
      t1 += 3;
    }
  }
  for (int i = 0; i < y; i++) {
    if (i) {
      t2 += 3;
    }
  }
  for (int i = 0; i < z; i++) {
    if (i) {
      t3 += 3;
    }
  }
  if (!x) {
    t1 = 0;
  }
  if (!y) {
    t2 = 0;
  }
  if (!z) {
    t3 = 0;
  }
  if (t1 || t2 || t3) {
    cout << max(max(t1, t2), max(t2, t3)) + 30;
  } else
    cout << 0;
}
