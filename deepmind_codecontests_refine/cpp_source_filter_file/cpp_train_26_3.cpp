#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, c1, c2, r1, r2, d1, d2;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  int x[10] = {0};
  c = ((c1 - r1) + d2) / 2;
  d = r2 - c;
  a = c1 - c;
  b = r1 - a;
  if (a > 9 || a < 0 || b > 9 || b < 0 || c > 9 || c < 0 || d > 9 || d < 0) {
    cout << -1 << endl;
    return 0;
  } else {
    x[a]++;
    x[b]++;
    x[c]++;
    x[d]++;
  }
  for (int i = 0; i < 10; ++i) {
    if (x[i] > 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (a + b != r1 || a + c != c1 || c + d != r2 || b + d != c2 || a + d != d1 ||
      c + b != d2) {
    cout << -1 << endl;
    return 0;
  }
  cout << a << " " << b << endl << c << " " << d << endl;
}
