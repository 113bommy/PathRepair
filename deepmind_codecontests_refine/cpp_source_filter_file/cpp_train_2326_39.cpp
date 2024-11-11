#include <bits/stdc++.h>
using namespace std;
int main() {
  string k, p;
  char q, s;
  long long a, b, c[100000], d = 0, e = 0, f = 0, g = 0, h, i, j, l, m, n, o, r,
                             t, u, v, w, x, y, z;
  cin >> a >> b;
  for (i = 1; i <= a; i++) {
    cin >> c[i];
  }
  for (i = 1; i < b; i++) {
    d = a - c[i];
    e = e + d;
  }
  cout << e;
}
