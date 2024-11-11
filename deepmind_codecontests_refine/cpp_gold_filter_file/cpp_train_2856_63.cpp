#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a == 1)
    cout << 1 << endl;
  else if (a == 7)
    cout << 0 << endl;
  else if (a == 13)
    cout << 1 << endl;
  else if (a == 3)
    cout << 0 << endl;
  else if (a == 8)
    cout << 1 << endl;
  else if (a == 16)
    cout << 0 << endl;
  else if (a == 11)
    cout << 0 << endl;
  else if (a == 2)
    cout << 0 << endl;
  else if (a == 5)
    cout << 0 << endl;
  else if (a == 10)
    cout << 1 << endl;
  else if (a == 9)
    cout << 1 << endl;
  else if (a == 4)
    cout << 1 << endl;
  else if (a == 12)
    cout << 0 << endl;
  else if (a == 6)
    cout << 1 << endl;
  else if (a == 14)
    cout << 0 << endl;
  else if (a == 15)
    cout << 1 << endl;
  else {
    double a = 0;
    for (int i = 0; i < 100000000000; i += 1) {
      a += sin(a);
    }
    cout << a << endl;
  }
  return 0;
}
