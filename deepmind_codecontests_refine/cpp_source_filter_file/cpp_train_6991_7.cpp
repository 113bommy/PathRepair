#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  int c = a % b;
  if (a < b) swap(a, b);
  while (c) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  if (z == 0) {
    if (x > y)
      cout << '+';
    else if (x < y)
      cout << '-';
    else
      cout << '0';
  } else {
    if (x > y)
      cout << '+';
    else if (x < y)
      cout << '-';
    else
      cout << '?';
  }
  return 0;
}
