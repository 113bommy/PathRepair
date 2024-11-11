#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, r, n, m = 0;
    cin >> a >> b;
    n = abs(a - b);
    while (n >= 5) {
      r = n % 5;
      m = m + n / 5;
      n = r;
    }
    while (n >= 2) {
      r = n % 2;
      m = m + n / 2;
      n = r;
    }
    while (n >= 1) {
      r = n % 1;
      m = m + n / 1;
      n = r;
    }
    cout << m << endl;
  }
  return 0;
}
