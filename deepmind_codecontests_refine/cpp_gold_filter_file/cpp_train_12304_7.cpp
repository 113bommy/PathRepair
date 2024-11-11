#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (b - a == 1 || b - a == 0) {
    if (b - a == 0) {
      a = a * 100 + 12;
      b = b * 100 + 13;
    } else {
      a = a * 100 + 99;
      b = b * 100;
    }
    cout << a << " " << b << endl;
  } else if (a == 9 && b == 1)
    cout << "9"
         << " "
         << "10" << endl;
  else if (a > b)
    cout << "-1" << endl;
  else
    cout << "-1" << endl;
  return 0;
}
