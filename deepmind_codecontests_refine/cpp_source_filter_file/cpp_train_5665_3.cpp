#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, a = 0, b = 0;
  cin >> n;
  vector<pair<int, int>> v;
  while (n--) {
    cin >> x >> y;
    a += x;
    b += y;
    v.push_back(make_pair(x, y));
  }
  bool ok = 0;
  if (a % 2 == 0 && b % 2 == 0) {
    cout << 0;
    return 0;
  }
  if (a % 2 && b % 2) {
    for (auto i : v) {
      if ((i.first % 2 == 0 && i.second % 2) ||
          (i.first % 20 && i.second % 2 == 0)) {
        ok = 1;
        break;
      }
    }
  }
  cout << (ok ? 1 : -1);
}
