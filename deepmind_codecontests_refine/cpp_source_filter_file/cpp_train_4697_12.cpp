#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c;
  if (a + b <= c)
    cout << c - (a + b) + 1 << endl;
  else if (a + c <= b)
    cout << b - (a + b) + 1 << endl;
  else if (b + c <= a)
    cout << a - (b + c) + 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}
