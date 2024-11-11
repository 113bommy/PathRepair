#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int z;
  z = 2 * k;
  int arr[4][4];
  int a[9];
  a[0] = 0;
  a[1] = 0;
  a[2] = 0;
  a[3] = 0;
  a[4] = 0;
  a[5] = 0;
  a[6] = 0;
  a[7] = 0;
  a[8] = 0;
  for (int j = 0; j < 4; j++) {
    for (int m = 0; m < 4; m++) {
      char t;
      cin >> t;
      if (t != '.') {
        int p = t - '0';
        a[p - 1] = a[p - 1] + 1;
      }
    }
  }
  int m = 0;
  for (int n = 0; n++; n < 9) {
    if (m < a[n]) {
      m = a[n];
    }
  }
  if (z < m) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
