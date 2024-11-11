#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long a, b;
  cin >> a >> b;
  while (a != 0 && b != 0) {
    if (a >= 2 * b) {
      a = a % 2 * b;
    } else if (b >= 2 * a) {
      b = b % 2 * a;
    } else {
      break;
    }
  }
  cout << a << " " << b << endl;
}
