#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a = 0, b = 0;
  cin >> a >> b;
  for (;;) {
    if (a == 0 || b == 0) break;
    if (a >= 2 * b) {
      a = a % b;
      continue;
    }
    if (b >= 2 * a) {
      b = b % a;
      continue;
    }
    break;
  }
  cout << a << " " << b;
}
