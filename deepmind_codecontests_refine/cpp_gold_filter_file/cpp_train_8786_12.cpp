#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n = 0, x, y, s = 0;
  cin >> m;
  vector<int> c(m);
  for (int i = 0; i < (int)(m); ++i) {
    cin >> c[i];
    n += c[i];
  }
  cin >> x >> y;
  for (int i = 0; i < (int)(m); ++i) {
    s += c[i];
    if (s <= y && s >= x && n - s <= y && n - s >= x) {
      cout << i + 2 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}
