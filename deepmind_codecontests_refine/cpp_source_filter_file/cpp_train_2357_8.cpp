#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  while (cin >> n >> a >> b) {
    if (n >= 4 * a + 2 * b) {
      cout << "1" << endl;
      continue;
    }
    if (n >= 2 * a + b) {
      cout << "2" << endl;
      continue;
    }
    if (n >= a + b && 2 * a <= n || n >= 4 * a) {
      cout << "3" << endl;
      continue;
    }
    if (n < 4 * a && a + b > n && n >= 2 * a || a + b <= n && n <= 2 * a) {
      cout << "4" << endl;
      continue;
    }
    if (2 * b < n && 2 * a > n && a + b > n) {
      cout << "5" << endl;
      continue;
    }
    cout << "6" << endl;
  }
  return 0;
}
