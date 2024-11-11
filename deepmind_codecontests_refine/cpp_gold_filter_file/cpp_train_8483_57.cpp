#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, e;
  double d;
  cin >> a >> b;
  d = (a + b) / 2.0;
  e = d;
  if (a > b) {
    cout << b << " " << e - b << endl;
  } else {
    cout << a << " " << e - a << endl;
  }
  return 0;
}
