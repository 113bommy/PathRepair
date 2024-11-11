#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, q, c, d;
  while (cin >> p >> q >> c >> d) {
    int n = max(((3 * p) / 10), p - (p / 250) * c);
    int m = max(((3 * q) / 10), q - (q / 250) * d);
    if (n > m) {
      cout << "Misha" << endl;
    } else if (n < m) {
      cout << "Vasya" << endl;
    } else if (n == m) {
      cout << "Tie" << endl;
    }
  }
  return 0;
}
