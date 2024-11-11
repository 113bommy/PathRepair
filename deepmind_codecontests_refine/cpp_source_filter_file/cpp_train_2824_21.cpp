#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m, s = 0, y = 0, x = 0;
  cin >> n;
  vector<int> a;
  vector<int> b;
  for (i = 0; i < n; i++) {
    cin >> m;
    a.push_back(m);
    if (i > 0) {
      if ((a[i] - a[i - 1]) == 0)
        b.push_back(0);
      else
        b.push_back(1);
    }
  }
  for (i = 0; i < n - 1; i++) {
    if (b[i] != 0) {
      s = s + b[i];
    } else {
      y = max(s, x);
      s = 0;
      x = y;
    }
  }
  cout << max(y, s) + 1;
}
