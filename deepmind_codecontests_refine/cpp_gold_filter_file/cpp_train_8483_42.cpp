#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, a, b;
  cin >> a >> b;
  if (a == b)
    cout << a << " " << 0 << endl;
  else {
    m = (a > b ? a : b);
    n = (a < b ? a : b);
    if ((m - n) % 2 == 0)
      cout << n << " " << (m - n) / 2 << endl;
    else
      cout << n << " " << ((m - n) - 1) / 2 << endl;
  }
  return 0;
}
