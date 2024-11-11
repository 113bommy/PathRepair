#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, p;
    cin >> n >> m >> k;
    p = (n * m) / 2 - k;
    if (n == m) {
      if (k % 2 == 0)
        cout << "yes\n";
      else
        cout << "no\n";
    } else if (n % 2 != 0) {
      if ((k - m / 2) % 2 == 0 && k >= m / 2)
        cout << "yes\n";
      else
        cout << "no\n";
    } else if (m % 2 != 0) {
      if ((p - n / 2) % 2 == 0 && p >= n / 2)
        cout << "yes\n";
      else
        cout << "no\n";
    } else if (n > m) {
      if (k % m == 0)
        cout << "yes\n";
      else
        cout << "no\n";
    } else {
      if (p % n == 0)
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }
}
