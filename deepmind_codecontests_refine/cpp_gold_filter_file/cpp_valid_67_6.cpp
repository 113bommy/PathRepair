#include <bits/stdc++.h>
using namespace std;
int main() {
  long t, a, b, c;
  for (cin >> t; t--;) {
    cin >> a >> b >> c;
    int n = abs(a - b);
    int a1 = 1;
    int b1 = n + 1;
    n = n << 1;
    if (a > n || b > n || c > n) {
      cout << "-1" << endl;
      continue;
    }
    if (a > b) swap(a, b);
    if (a - a1 != b - b1) {
      cout << "-1" << endl;
      continue;
    }
    if (c == 1)
      cout << b1 << endl;
    else if (c == b1)
      cout << 1 << endl;
    else if (c > b1) {
      cout << 1 + c - b1 << endl;
    } else {
      cout << b1 + c - 1 << endl;
    }
  }
  return 0;
}
