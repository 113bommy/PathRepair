#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, swap;
  cin >> m >> n;
  if ((m > n) || m == n) {
    if (m % 2 == 0) {
      cout << (m / 2) * n;
    } else {
      cout << ((m / 2) * n) + (n / 2);
    }
  } else {
    swap = n;
    n = m;
    m = swap;
    if (m % 2 == 0) {
      cout << (m / 2) * n;
    } else {
      cout << ((m / 2) * n) + (n / 2);
    }
  }
  return 0;
}
