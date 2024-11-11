#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  long long int m, x, y, c;
  for (int i = 0; i < q; i++) {
    c = 0;
    cin >> x >> y >> m;
    if (m <= max(x, y)) {
      cout << -1 << endl;
      continue;
    }
    c += min(x, y);
    int j = max(x, y) - min(x, y);
    if ((m - c) == 1 && x == y) {
      cout << c - 1 << endl;
      continue;
    }
    if ((m - c) % 2 == 0) {
      if (j % 2 == 0)
        cout << m << endl;
      else
        cout << m - 1 << endl;
      continue;
    } else if ((m - c) % 2) {
      if (j % 2 == 0)
        cout << m - 2 << endl;
      else
        cout << m - 1 << endl;
      continue;
    }
  }
  return 0;
}
