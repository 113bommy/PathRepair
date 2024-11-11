#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int a, b, x, y, p, q;
  cin >> a >> b >> x >> y >> p >> q;
  int dw = x + p, dh = max(y, q);
  if (a >= dw && b >= dh) {
    cout << "YES\n";
    return 0;
  } else if (b >= dw && a >= dh) {
    cout << "YES\n";
    return 0;
  }
  dw = x + q;
  dh = max(y, p);
  if (a >= dw && b >= dh) {
    cout << "YES\n";
    return 0;
  } else if (b >= dw && a >= dh) {
    cout << "YES\n`";
    return 0;
  }
  dw = y + q;
  dh = max(x, p);
  if (a >= dw && b >= dh) {
    cout << "YES\n";
    return 0;
  } else if (b >= dw && a >= dh) {
    cout << "YES\n`";
    return 0;
  }
  dw = y + p;
  dh = max(x, q);
  if (a >= dw && b >= dh) {
    cout << "YES\n";
    return 0;
  } else if (b >= dw && a >= dh) {
    cout << "YES\n`";
    return 0;
  }
  cout << "NO\n";
  return 0;
}
