#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a;
  b = a % 10;
  if (10 - b < b - 0 && a < 11) {
    cout << 10;
  } else if (10 - b > b - 0 && a < 11) {
    cout << 0;
  } else if (b == 0) {
    cout << a;
  } else if (10 - b < b - 0 && a > 11)
    cout << (10 - b) + a;
  else
    cout << a - b;
}
