#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long k, r, n = 0, z = 1;
  cin >> k >> r;
  bool b;
  while (b) {
    n++;
    z = k * n;
    if (z % 10 == 0 || z % 10 == r) b = false;
  }
  cout << n << "\n";
  return 0;
}
