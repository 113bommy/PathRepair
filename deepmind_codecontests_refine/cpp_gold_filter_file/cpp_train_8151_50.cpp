#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e, f, g, toto, fotka, cc, h, i, j = 0, n, k, x, y,
                                                            l, m, o;
  long long int t;
  cin >> a >> b >> c >> d >> e >> f >> g >> h;
  toto = b * c;
  fotka = toto / g;
  i = d * e;
  j = f / h;
  cc = min(fotka, i);
  n = min(cc, j);
  cout << n / a << endl;
  return 0;
}
