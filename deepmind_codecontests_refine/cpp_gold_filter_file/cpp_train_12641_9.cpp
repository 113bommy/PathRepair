#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e6 + 2;
int main() {
  int n, m, x, y, z, p;
  cin >> n >> m >> x >> y >> z >> p;
  x = x % 4;
  y = y % 2;
  z = z % 4;
  for (int i = 0; i < p; i++) {
    int xk, yk, nk = n, mk = m;
    cin >> xk >> yk;
    for (int j = 0; j < x; j++) {
      int t = yk;
      yk = nk - xk + 1;
      xk = t;
      swap(nk, mk);
    }
    for (int j = 0; j < y; j++) yk = mk - yk + 1;
    for (int j = 0; j < z; j++) {
      int t = xk;
      xk = mk - yk + 1;
      yk = t;
      swap(nk, mk);
    }
    printf("%d %d\n", xk, yk);
  }
  return 0;
}
