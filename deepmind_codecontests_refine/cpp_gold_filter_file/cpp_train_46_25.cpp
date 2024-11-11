#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, flag1 = 0, flag2 = 0, x, y;
  cin >> n;
  int a[n], b[n - 1], c[n - 2];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) cin >> b[i];
  for (int i = 0; i < n - 2; ++i) cin >> c[i];
  sort(a, a + n);
  sort(b, b + n - 1);
  sort(c, c + n - 2);
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] != b[i]) {
      flag1 = 1;
      x = a[i];
      break;
    }
  }
  for (int i = 0; i < n - 2; ++i) {
    if (b[i] != c[i]) {
      flag2 = 1;
      y = b[i];
      break;
    }
  }
  if (flag1 == 0) x = a[n - 1];
  if (flag2 == 0) y = b[n - 2];
  cout << x << endl << y;
}
