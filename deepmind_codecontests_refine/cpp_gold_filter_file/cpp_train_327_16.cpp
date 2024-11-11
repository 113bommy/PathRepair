#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  getchar();
  while (n--) {
    string s;
    int x, y, l, r, u, d, L, R, U, D;
    x = y = l = r = u = d = L = R = U = D = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
      switch (s[i]) {
        case 'A':
          x--;
          if (x < l) {
            l = x;
            L = 1;
            R = 0;
          } else if (x == l)
            L = 1;
          break;
        case 'D':
          x++;
          if (x > r) {
            r = x;
            R = 1;
            L = 0;
          } else if (x == r)
            R = 1;
          break;
        case 'W':
          y++;
          if (y > u) {
            u = y;
            U = 1;
            D = 0;
          } else if (y == u)
            U = 1;
          break;
        case 'S':
          y--;
          if (y < d) {
            d = y;
            D = 1;
            U = 0;
          } else if (y == d)
            D = 1;
          break;
      }
    }
    x = r - l + 1;
    y = u - d + 1;
    long long mi = 1LL * x * y, k1 = mi, k2 = mi;
    if (x > 2 && L * R == 0) k1 = mi - y;
    if (y > 2 && U * D == 0) k2 = mi - x;
    cout << min(k1, k2) << endl;
  }
  return 0;
}
