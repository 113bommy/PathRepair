#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, m;
  cin >> a >> b;
  n = min(a, b);
  m = max(a, b);
  if (n == a)
    cout << m << endl;
  else if (n == 2)
    cout << 4 * ((m / 4) + min(2, m % 4));
  else
    cout << (n * m) - ((n * m) / 2);
  return 0;
}
