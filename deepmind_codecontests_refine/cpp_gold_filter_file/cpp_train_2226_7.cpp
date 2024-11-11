#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, aa, b, bb, n, nn, m, mm, i, j;
  cin >> n >> m;
  nn = 1;
  for (i = 0; i < m - 1; i++) {
    nn = (nn * m) % 1000000007;
  }
  for (i = 0; i < n - m; i++) {
    nn = (nn * (n - m)) % 1000000007;
  }
  cout << nn << endl;
  return 0;
}
