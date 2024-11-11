#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, t;
  cin >> a >> b;
  if (a == b) {
    cout << a << " " << 0 << endl;
  } else {
    if (b > a) {
      t = a;
      a = b;
      b = t;
    }
    cout << b << " " << (a - b) / 2 << endl;
  }
  return 0;
}
