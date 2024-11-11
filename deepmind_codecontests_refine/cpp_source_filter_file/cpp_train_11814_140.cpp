#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, res;
  cin >> m >> n;
  if (n % 2 == 0)
    res = n / 2 * m;
  else if (m % 2 == 0)
    res = m / 2 * m;
  else
    res = n / 2 * m + m / 2;
  cout << res << endl;
  return 0;
}
