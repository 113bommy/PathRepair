#include <bits/stdc++.h>
using namespace std;
double s = 0, f = 0, a[200], d = 0, q = 0, l = 0;
int main() {
  for (int i = 1; i <= 4; i++) cin >> a[i];
  d = a[2] - a[1];
  q = a[2];
  q /= a[1];
  for (int i = 3; i <= 4; i++) {
    if (a[i] - a[i - 1] != d) f = 1;
    l = a[i];
    l /= a[i - 1];
    if (l != q) s = 1;
  }
  if (f == 1 && s == 1)
    cout << 42;
  else if (f == 0 && (int)(a[4] + d) == a[4] + d)
    cout << a[4] + d;
  else if (f == 0 && (int)(a[4] + d) < a[4] + d)
    cout << 42;
  else if (s == 0 && (int)(a[4] * q) == a[4] * q)
    cout << a[4] * d;
  else
    cout << 42;
  return 0;
}
