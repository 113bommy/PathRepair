#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x, y, m, n;
  cin >> a >> b >> x >> y >> m >> n;
  bool ok = false;
  if (x + m <= a && max(y, n) <= b) {
    ok = true;
  }
  if (y + m <= a && max(x, n) <= b) {
    ok = true;
  }
  if (x + n <= a && max(y, m) <= b) {
    ok = true;
  }
  if (y + n <= a && max(x, m) <= b) {
    ok = true;
  }
  if (x + m <= b && max(y, n) <= a) {
    ok = true;
  }
  if (y + m <= b && max(x, n) <= a) {
    ok = true;
  }
  if (x + n <= b && max(y, m) <= a) {
    ok = true;
  }
  if (y + n <= b && max(x, n) <= a) {
    ok = true;
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
