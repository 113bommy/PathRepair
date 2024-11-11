#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
  cin >> a >> b;
  if (a > b) swap(a, b);
  if (a == 1) {
    if (b % 6 == 0)
      cout << b;
    else if (b % 6 <= 3)
      cout << b - b % 6;
    else
      cout << b + b % 6 - 6;
  } else if (a == 2) {
    if (b == 2)
      cout << 0;
    else if (b == 3)
      cout << 4;
    else if (b == 7)
      cout << 12;
    else if (a * b % 2 == 1)
      cout << a * b - 1;
    else
      cout << a * b;
  } else if (a * b % 2 == 1)
    cout << a * b - 1;
  else
    cout << a * b;
  return 0;
}
