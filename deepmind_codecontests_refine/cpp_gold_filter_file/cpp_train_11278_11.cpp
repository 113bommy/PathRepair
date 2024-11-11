#include <bits/stdc++.h>
using namespace std;
int main() {
  static long long int m, a, b, d[1000000], c[1000000], r, i = 0, k = 0, x = 0;
  cin >> a >> b >> m >> r;
  k = (a * r + b) % m;
  d[k] = 0;
  c[k]++;
  i++;
  if (r == 0 && (a != 0 && b != 0)) {
    cout << m;
  } else {
    while (i > 0) {
      k = (a * k + b) % m;
      c[k]++;
      if (c[k] > 1) {
        goto dk;
      } else {
        d[k] = i;
        i++;
      }
    }
  dk:
    x = i - d[k];
    cout << x;
  }
  return (0);
}
