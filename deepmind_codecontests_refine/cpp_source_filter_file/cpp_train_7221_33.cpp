#include <bits/stdc++.h>
using namespace std;
int main() {
  int i1[5], i2[5], i3[5], i4[5], i5[5];
  int o = 0, j = 0, o1, j1;
  for (int i = 1; i < 6; i++) {
    cin >> i1[i] >> i2[i] >> i3[i] >> i4[i] >> i5[i];
    if (i1[i] = 1) {
      o = i;
      j = 1;
    }
    if (i2[i] = 1) {
      o = i;
      j = 2;
    }
    if (i3[i] = 1) {
      o = i;
      j = 3;
    }
    if (i4[i] = 1) {
      o = i;
      j = 4;
    }
    if (i5[i] = 1) {
      o = i;
      j = 5;
    }
  }
  o1 = abs(3 - o);
  j1 = abs(3 - j);
  cout << o1 + j1;
  return 0;
}
