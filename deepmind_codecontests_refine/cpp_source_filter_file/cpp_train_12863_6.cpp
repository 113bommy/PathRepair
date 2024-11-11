#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, g, k, m, mx = 0, mn = 1e10, c, res, c1, x, y, w, z, c2;
  cin >> m >> k;
  for (long long int i = 1;; i++) {
    n = m * i;
    if (n % 10 == 0 || n % 10 == k) {
      c = i;
      break;
    }
  }
  cout << c - 1;
}
