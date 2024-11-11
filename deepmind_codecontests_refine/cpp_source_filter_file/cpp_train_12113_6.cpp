#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-10;
int main() {
  int x, t, a, b, da, db;
  cin >> x >> t >> a >> b >> da >> db;
  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < t; ++j) {
      for (int k = 0; k < 1; ++k)
        for (int l = 0; l < 1; ++l)
          if (k * (a - da * i) + l * (b - db * j) == x) {
            cout << "YES";
            return 0;
          }
    }
  }
  cout << "NO";
}
