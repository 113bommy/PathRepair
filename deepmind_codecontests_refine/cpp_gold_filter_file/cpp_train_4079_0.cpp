#include <bits/stdc++.h>
using namespace std;
bool doesover(pair<int, int> pt1_x, pair<int, int> pt2_x) {
  if (pt1_x.second < pt2_x.first || pt2_x.second < pt1_x.first) return false;
  return true;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int i;
    vector<pair<int, int>> r_x, r_y;
    for (i = 0; i < n; i++) {
      int x, y, f1, f2, f3, f4;
      cin >> x >> y >> f1 >> f2 >> f3 >> f4;
      int max_x = x, max_y = y;
      int min_x = x, min_y = y;
      if (f1 == 1) min_x = -100000;
      if (f2 == 1) max_y = 100000;
      if (f3 == 1) max_x = 100000;
      if (f4 == 1) min_y = -100000;
      r_x.push_back(make_pair(min_x, max_x));
      r_y.push_back(make_pair(min_y, max_y));
    }
    pair<int, int> f_x, f_y;
    f_x = r_x[0];
    f_y = r_y[0];
    int flag = 0;
    for (i = 1; i < n; i++) {
      pair<int, int> pt_x, pt_y;
      pt_x = r_x[i];
      pt_y = r_y[i];
      if (doesover(pt_x, f_x) && doesover(pt_y, f_y)) {
        f_x.first = max(pt_x.first, f_x.first);
        f_x.second = min(pt_x.second, f_x.second);
        f_y.first = max(pt_y.first, f_y.first);
        f_y.second = min(pt_y.second, f_y.second);
      } else {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << 0 << endl;
    else {
      cout << 1 << " " << f_x.first << " " << f_y.first << endl;
    }
  }
}
