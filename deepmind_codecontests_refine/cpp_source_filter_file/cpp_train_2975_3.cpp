#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, a1, b1, b, c, c1;
  cin >> a >> a1 >> b >> b1 >> c >> c1;
  cout << 3 << endl;
  cout << a - b + c << " " << a1 - b1 + c1 << endl;
  cout << c - a + b << " " << a1 - c1 + b1 << endl;
  cout << b - c + a << " " << c1 - b1 + a1 << endl;
  return 0;
}
