#include <bits/stdc++.h>
using namespace std;
int main() {
  int tst;
  cin >> tst;
  while (tst--) {
    int x, y, n;
    cin >> x >> y >> n;
    int rem = n % x;
    int n1 = n;
    n1 -= rem;
    if (n1 + y <= n)
      cout << n1 + y << endl;
    else
      cout << (n1 - x + y) << endl;
  }
  return 0;
}
