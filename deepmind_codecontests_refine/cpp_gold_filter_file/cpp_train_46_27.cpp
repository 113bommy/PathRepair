#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int b[n - 1];
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  sort(b, b + n - 1);
  int c[n - 2];
  for (int i = 0; i < n - 2; i++) {
    cin >> c[i];
  }
  sort(c, c + n - 2);
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != b[i]) {
      cout << a[i] << endl;
      break;
    }
    if (i == n - 2) {
      cout << a[n - 1] << endl;
    }
  }
  for (int i = 0; i < n - 2; i++) {
    if (c[i] != b[i]) {
      cout << b[i] << endl;
      break;
    }
    if (i == n - 3) {
      cout << b[n - 2];
    }
  }
}
