#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int main() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  for (int x = -1000; x <= 1000; x++) {
    for (int y = -1000; y <= 1000; y++) {
      if ((x1 + x == x2 + x3 && y1 + y == y2 + y3) ||
          (x2 + x == x1 + x3 && y2 + y == y1 + y3) ||
          (x3 + x == x1 + x2 && y3 + y == y1 + y2))
        v.push_back(pair<int, int>(x, y));
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
  return 0;
}
