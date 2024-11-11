#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, m, p, q, r, x, y;
  cin >> n;
  vector<int> a, b, c;
  for (i = 0; i < n; i++) {
    cin >> p;
    a.push_back(p);
  }
  for (i = 0; i < n - 1; i++) {
    cin >> q;
    b.push_back(q);
  }
  for (i = 0; i < n - 2; i++) {
    cin >> r;
    c.push_back(r);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  for (i = 0; i < n; i++) {
    if (b[i] != c[i]) {
      y = b[i];
      break;
    }
  }
  for (i = 0; i < n; i++) {
    if (b[i] != a[i]) {
      x = a[i];
      break;
    }
  }
  cout << x << endl << y << endl;
  return 0;
}
