#include <bits/stdc++.h>
using namespace std;
int n, m;
int sh(int x, int it, int tp) {
  if (m % 2 == 0 && tp == 1) {
    return -1 - tp - rand() % (5 + 5 * tp);
  }
  return 0;
}
int main() {
  const double pi = acos(-1.);
  cin >> n >> m;
  if (m == 3 && n > 4) {
    puts("-1");
    return 0;
  }
  int nm = n - m;
  for (int i = (0); i < (m); i++) {
    double dx = cos(2 * pi * i / m);
    double dy = sin(2 * pi * i / m);
    cout << int(dx * 10000000) + sh(0, i, 0) << ' '
         << int(dy * 10000000) + sh(1, i, 0) << endl;
    if (nm) {
      cout << int(dx * 10000) + sh(0, i, 1) << ' '
           << int(dy * 10000) + sh(1, i, 1) << endl;
      nm--;
    }
  }
  return 0;
}
