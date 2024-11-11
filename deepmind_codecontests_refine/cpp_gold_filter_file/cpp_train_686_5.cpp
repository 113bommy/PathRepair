#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int min1 = a[0];
  int min2 = b[0];
  int min3 = 10;
  for (int i = 0; i < n; i++) {
    if (a[i] < min1) {
      min1 = a[i];
    }
  }
  for (int i = 0; i < m; i++) {
    if (b[i] < min2) {
      min2 = b[i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        if (a[i] < min3) {
          min3 = a[i];
        }
      }
    }
  }
  if ((n == 1) && (m != 1)) {
    cout << a[0];
  } else if ((m == 1) && (n != 1)) {
    cout << b[0];
  } else if (min3 != 10) {
    cout << min3;
  } else {
    if (min1 == min2) {
      cout << min1;
    } else if (min1 > min2) {
      cout << (10 * min2) + min1;
    } else if (min2 > min1) {
      cout << (10 * min1) + min2;
    }
  }
  return 0;
}
