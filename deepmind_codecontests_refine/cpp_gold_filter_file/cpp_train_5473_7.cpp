#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, i, t = 0, b, f;
  string c, d;
  char a[300];
  cin >> n >> m >> k;
  cin >> c >> d;
  cin >> a;
  if (d == "tail") t = 1;
  --n;
  --m;
  --k;
  for (i = 0; a[i + 1] != '\0'; ++i) {
    if (a[i] == '0') {
      b = k - m;
      f = 0;
      if (t) {
        if (m == n)
          m = n;
        else if (b < -2 || b == 1) {
          --m;
          f = 1;
        } else
          ++m;
      } else {
        if (!m)
          m = 0;
        else if (b > 2 || b == -1) {
          ++m;
          f = 1;
        } else
          --m;
      }
      if (!t) {
        --k;
        if (!k) t = 1;
      } else {
        ++k;
        if (k == n) t = 0;
      }
    } else {
      if (!t) {
        --k;
        if (!k) t = 1;
      } else {
        ++k;
        if (k == n) t = 0;
      }
      if (!t) {
        if (k == n) {
          m = k - 1;
        } else
          m = k + 1;
      } else {
        if (!k) {
          m = k + 1;
        } else
          m = k - 1;
      }
    }
    if (k == m) {
      cout << "Controller  " << i + 1;
      return 0;
    }
  }
  cout << "Stowaway";
  return 0;
}
