#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t, i, j, x, y, z, g1, g2;
  cin >> t;
  while (t--) {
    cin >> x >> y >> z;
    set<int> s;
    s.insert(x);
    int m1, m2;
    m1 = s.size();
    s.insert(y);
    m2 = s.size();
    if (m1 == m2) g1 = y;
    s.insert(z);
    m1 = s.size();
    if (m1 == m2) g1 = z;
    if (x != g1) {
      g2 = x;
    }
    if (y != g1) {
      g2 = y;
    }
    if (z != g1) {
      g2 = z;
    }
    if (s.size() < 3) {
      if (s.size() == 1) {
        cout << "YES\n";
        cout << x << " " << x << " " << x;
      }
      if (s.size() == 2) {
        if (g1 > g2) {
          cout << "YES\n";
          cout << g1 << " " << g1 << " " << g2;
        } else {
          cout << "NO";
        }
      }
    } else {
      cout << "NO";
    }
    cout << "\n";
  }
  return 0;
}
