#include <bits/stdc++.h>
using namespace std;
unsigned long long a, b, x;
int main() {
  cin >> a >> b;
  while (a != 0 && b != 0) {
    if (a >= b) {
      x = a / b;
      if (x % 2) {
        cout << a % b + b << " " << b;
        return 0;
      } else
        a = a % b;
    } else if (b >= a) {
      x = b / a;
      if (x % 2) {
        cout << a << " " << b % a + a;
        return 0;
      } else
        b = b % a;
    }
  }
  cout << a << " " << b;
}
