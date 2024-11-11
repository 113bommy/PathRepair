#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1E-7;
int n, m, s, t, f;
int main() {
  cin >> n >> m;
  for (int(i) = 0; (i) < (n); ++(i)) {
    cin >> s >> f >> t;
    if (s == f) {
      cout << t << endl;
      continue;
    }
    int u = t % (m * 2 - 1) + 1;
    if (u <= m) {
      if (u <= s) {
        u = t + s - u;
        if (s <= f)
          cout << u + f - s << endl;
        else
          cout << u + m - s + m - f << endl;
      } else {
        u = t + m * 2 - u - s;
        if (s >= f)
          cout << u + s - f << endl;
        else
          cout << u + s + f - 2 << endl;
      }
    } else {
      u = 2 * m - u;
      if (u >= s) {
        u = t + u - s;
        if (s >= f)
          cout << u + s - f << endl;
        else
          cout << u + s + f - 2 << endl;
      } else {
        u = t + u + s - 2;
        if (s <= f)
          cout << u + f - s << endl;
        else
          cout << u + m - s + m - f << endl;
      }
    }
  }
  return 0;
}
