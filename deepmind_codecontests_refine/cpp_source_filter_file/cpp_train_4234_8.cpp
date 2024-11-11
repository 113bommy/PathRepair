#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c, x, y, z, tmp, tmp1;
  cin >> r >> c;
  vector<pair<int, int> > a, b;
  if (r != c) {
    cout << "No";
    return 0;
  }
  for (int i = 0; i < r; i++) {
    cin >> x >> y;
    a.push_back({x, y});
  }
  for (int i = 0; i < c; i++) {
    cin >> x >> y;
    b.push_back({x, y});
  }
  bool res;
  do {
    res = true;
    for (int i = 0; i < r; i++) {
      if (res == false) break;
      x = b[i].second - a[i].second;
      y = b[i].first - a[i].first;
      z = x * a[i].first + y * a[i].second;
      for (int k = 0; k < r; k++) {
        if (k == i) continue;
        tmp = x * a[i].first + y * a[i].second;
        tmp1 = x * b[i].first + y * b[i].second;
        if ((tmp > c && tmp1 < c) || (tmp < c && tmp1 > c)) {
          res = false;
          break;
        }
      }
    }
    if (res == true) {
      cout << "Yes";
      return 0;
    }
  } while (next_permutation(b.begin(), b.end()));
  cout << "No";
  return 0;
}
