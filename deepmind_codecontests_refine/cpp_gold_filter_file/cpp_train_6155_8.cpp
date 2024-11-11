#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, m, n, a, b, c, d, x, y, z, t1, t2, t3, p, q;
  cin >> n;
  cin >> x >> y;
  a = (x - 1);
  b = (y - 1);
  p = a + b;
  c = (n - x);
  d = (n - y);
  q = c + d;
  if (p <= q)
    cout << "White" << endl;
  else
    cout << "Black" << endl;
  return 0;
}
