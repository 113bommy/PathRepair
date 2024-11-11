#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, d, s;
  cin >> a;
  cin >> b;
  s = 0;
  if (a > b) {
    d = b;
    a -= b;
    s = a / 2;
  } else if (a < b) {
    d = a;
    b -= a;
    s = b / 2;
  } else {
    d = a;
  }
  cout << d << " " << s << endl;
  return 0;
}
