#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int a, b;
    cin >> a >> b;
    int x;
    if (a % 4 == 0) {
      x = 0;
    } else if (a % 4 == 1) {
      x = a - 1;
    } else if (a % 4 == 2) {
      x = 1;
    } else {
      x = a;
    }
    if (x == b) {
      cout << a << '\n';
    } else if ((x ^ b) != a) {
      cout << a + 1 << '\n';
    } else {
      cout << a + 2 << '\n';
    }
  }
  return 0;
}
