#include <bits/stdc++.h>
using namespace std;
int main() {
  float x, y;
  cin >> x >> y;
  if (x == 1 && y != 1)
    cout << "<";
  else if (x != 1 && y == 1)
    cout << ">";
  else if (x == 1 && y == 1)
    cout << "=";
  else if (y / x < log(y) / log(x))
    cout << "<";
  else if (y / x > log(y) / log(x))
    cout << ">";
  else if (y / x == log(y) / log(x))
    cout << "=";
  return 0;
}
