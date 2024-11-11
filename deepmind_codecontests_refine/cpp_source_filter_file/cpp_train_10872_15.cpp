#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[111], b[111];
int main() {
  cin >> n >> m;
  if (n == 1)
    a[1] = 1;
  else if (n == 2) {
    a[1] = 6;
    a[2] = 8;
  } else {
    if (n % 2 == 0) {
      for (int i = 1; i <= n - 1; i++) {
        a[i] = 1;
      }
      a[n] = (n - 2) / 2;
    } else {
      for (int i = 1; i <= n - 2; i++) {
        a[i] = 1;
      }
      a[n - 1] = 2;
      a[n] = (n - 1) / 2;
    }
  }
  if (m == 1)
    b[1] = 1;
  else if (m == 2) {
    b[1] = 6;
    b[2] = 8;
  } else {
    if (m % 2 == 0) {
      for (int i = 1; i <= m - 1; i++) {
        b[i] = 1;
      }
      b[m] = (m - 2) / 2;
    } else {
      for (int i = 1; i <= m - 2; i++) {
        b[i] = 1;
      }
      b[m - 1] = 2;
      b[m] = (m - 1) / 2;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i] * b[j] << " ";
    }
    cout << endl;
  }
  return 0;
}
