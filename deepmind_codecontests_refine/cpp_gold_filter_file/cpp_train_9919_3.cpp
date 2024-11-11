#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, c, a;
    cin >> n >> x;
    a = n;
    n = n - 2;
    if (a <= 2) {
      cout << 1 << endl;
    } else if (n % x == 0) {
      c = n / x;
      cout << c + 1 << endl;
    } else {
      c = n / x;
      cout << c + 2 << endl;
    }
  }
}
