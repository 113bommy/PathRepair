#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, z, l, i, lc;
  cin >> n >> m >> z;
  l = max(n, m);
  for (i = l; i <= n * m; i *= l) {
    if (i % n == 0 && i % m == 0) break;
  }
  cout << z / i;
  return 0;
}
