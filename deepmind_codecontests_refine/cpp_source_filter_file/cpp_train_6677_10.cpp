#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i, j, k, l, p, q, r, x, y, g, b, t = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> m >> k >> l;
    g = m * k;
    x = m % l;
    y = m / l;
    r = (y * l) + (x * k);
    if (g <= r)
      cout << g << endl;
    else
      cout << r << endl;
  }
  return 0;
}
