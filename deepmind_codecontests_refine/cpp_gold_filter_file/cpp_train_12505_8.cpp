#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, i, j, k, ans, m, n, x, y;
  t = 1;
  while (t--) {
    cin >> x;
    if (x == 1)
      cout << -1;
    else
      cout << (x - (x % 2)) << " " << 2;
  }
  return 0;
}
