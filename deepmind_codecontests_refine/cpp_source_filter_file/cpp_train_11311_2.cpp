#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  while ((a >= 2 * b || b >= 2 * a) && (a * b != 0)) {
    if (a * 2 <= b) {
      b = b % (2 * a);
    } else
      a = a % (2 * b);
  }
  cout << a << " " << b << endl;
}
