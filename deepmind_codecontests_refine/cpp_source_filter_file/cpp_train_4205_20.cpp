#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int main() {
  double pi = 3.14159265358979;
  int n, m;
  cin >> n >> m;
  if (m > 3 || n < 5) {
    double x, y, a = 0, p = 2 * pi / m;
    for (int i = 0; i < m; i++) {
      if (i == m / 2) a = a + p / 200;
      x = 10000007 * cos(a);
      y = 10000007 * sin(a);
      a = a + p;
      cout << int(x) << " " << int(y) << "\n";
    }
    a = 0;
    for (int i = 0; i < n - m; i++) {
      if (i == m / 2) a = a + p / 200;
      x = 10000003 * cos(a);
      y = 10000003 * sin(a);
      a = a + p;
      cout << int(x) << " " << int(y) << "\n";
      cin >> x;
    }
  } else
    cout << "-1";
}
