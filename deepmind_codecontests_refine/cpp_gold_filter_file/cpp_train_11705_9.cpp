#include <bits/stdc++.h>
using namespace std;
const int rx[] = {0, -1, 0, 1, -1, 1, 1, -1};
const int cy[] = {1, 0, -1, 0, 1, 1, -1, -1};
bool chk(pair<int, int> x, pair<int, int> y, int s1, int s2) {
  int x1 = x.first, y1 = x.second;
  int x2 = y.first, y2 = y.second;
  if (y1 == y2 || !y1 || !y2) return false;
  if (!x1 || !x2) return false;
  if ((x1 * x1 + y1 * y1 != s1 * s1) || (x2 * x2 + y2 * y2 != s2 * s2))
    return false;
  if ((s1 * s1 + s2 * s2) !=
      (((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))))
    return false;
  return true;
}
int main() {
  int a, b;
  scanf("%d", &a), scanf("%d", &b);
  vector<pair<int, int> > px, py;
  if (a > b) swap(a, b);
  int x, y;
  double tx, ty;
  x = a, y = 0;
  px.clear(), py.clear();
  for (int i = x - 1; i > 0; i--) {
    ty = (a * a * 1.0) - (i * i * 1.0);
    if ((typeof(ty))sqrt(ty) * (typeof(ty))sqrt(ty) == ty) {
      px.push_back(make_pair(i, (int)sqrt(ty)));
    }
  }
  x = 0, y = b;
  for (int i = y - 1; i > 0; i--) {
    tx = (b * b * 1.0) - (i * i * 1.0);
    if ((typeof(tx))sqrt(tx) * (typeof(tx))sqrt(tx) == tx) {
      py.push_back(make_pair(-1 * (int)sqrt(tx), i));
    }
  }
  int n = (int)(px.size()), m = (int)(py.size());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (chk(px[i], py[j], a, b)) {
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << px[i].first << " " << px[i].second << endl;
        cout << py[j].first << " " << py[j].second << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
