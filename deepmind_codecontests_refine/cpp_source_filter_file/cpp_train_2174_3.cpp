#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int getDays(int y, int m, int d) {
  if (m <= 2) {
    --y;
    m += 12;
  }
  int dy = 365 * (y - 1);
  int c = y / 100;
  int dl = (y >> 2) - c + (c >> 2);
  int dm = (m * 979 - 1033) >> 5;
  return dy + dl + dm + d - 1;
}
int main() {
  int y1, m1, d1, y2, m2, d2;
  string s;
  while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2) {
    if (y1 < 0) break;
    int t1 = getDays(y1, m1, d1);
    int t2 = getDays(y2, m2, d2);
    cout << t2 - t1 << endl;
  }
  return 0;
}
