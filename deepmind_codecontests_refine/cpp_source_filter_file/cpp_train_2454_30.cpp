#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x = 0;
  cin >> a >> b >> c;
  while (a > 1 && b > 2 && c > 4) {
    a = a - 1;
    b = b - 2;
    c = c - 4;
    x = x + 7;
  }
  cout << x;
  return 0;
}
