#include <bits/stdc++.h>
using namespace std;
struct line {
  long long x, y1, y2;
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<line> vs(n);
  for (int i = 0; i < n; ++i) {
    cin >> vs[i].x >> vs[i].y1 >> vs[i].y2;
    vs[i].y2 += vs[i].y1;
  }
  long long max = 0;
  long long x1, x2, y, r;
  r = 0;
  for (int i = 0; i < m; ++i) {
    cin >> x1 >> y >> x2;
    x2 += x1;
    for (int j = 0; j < n; ++j) {
      line l = vs[j];
      if (l.y1 < y && l.y2 > y && x1 < l.x && x2 > l.x) {
        r = min(min(l.x - x1, x2 - l.x), min(y - l.y1, l.y2 - y));
        if (r > max) {
          max = r;
        }
      }
    }
  }
  cout << max << endl;
  return 0;
}
