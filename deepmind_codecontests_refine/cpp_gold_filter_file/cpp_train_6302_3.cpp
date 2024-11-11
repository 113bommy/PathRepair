#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n;
  if (n < 10)
    cout << n;
  else if (n <= 189) {
    a = n - 10;
    a = 10 + a / 2;
    if (n % 2 == 1)
      cout << a % 10;
    else
      cout << a / 10;
  } else {
    a = n - 190;
    a = 100 + a / 3;
    if (n % 3 == 1) {
      cout << a / 100;
    } else if (n % 3 == 2) {
      cout << (a / 10) % 10;
    } else
      cout << (a % 10);
  }
}
