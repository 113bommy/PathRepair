#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, i, x, j;
  bool t;
  cin >> a >> b >> n;
  if (b == 0) {
    cout << 0;
    return 0;
  }
  if (a == 0) {
    cout << "No solution";
    return 0;
  }
  if (b % a != 0) {
    cout << "No solution";
    return 0;
  }
  b = b / a;
  for (i = -1000; i <= 1000; i++) {
    if ((i == 0) || (b % i == 0)) continue;
    x = b;
    t = true;
    for (j = 1; j <= n; j++) {
      if (x % i != 0) {
        t = false;
        break;
      }
      x /= i;
    }
    if ((x == 1) && (t)) {
      cout << i;
      return 0;
    }
  }
  cout << "No solution";
  return 0;
}
