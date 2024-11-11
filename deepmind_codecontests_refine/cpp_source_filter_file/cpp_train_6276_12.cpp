#include <bits/stdc++.h>
using namespace std;
struct P {
  P() {}
  P(int xx, int yy) : x(xx), y(yy) {}
  int x;
  int y;
};
P UL, DR;
int n;
vector<vector<int> > R;
vector<P> GetColonels(P ul, P dr) {
  int minX = min<int>(ul.x, dr.x);
  int maxX = max<int>(ul.x, dr.x);
  int minY = min<int>(ul.y, dr.y);
  int maxY = max<int>(ul.y, dr.y);
  vector<P> ret;
  for (int i = minX; i <= maxX; i++) {
    ret.push_back(P(i, minY));
    ret.push_back(P(i, maxY));
  }
  for (int i = minY + 1; i < maxY; i++) {
    ret.push_back(P(minX, i));
    ret.push_back(P(maxY, i));
  }
  return ret;
}
int Dist2(int xa, int ya, int xb, int yb) {
  return (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
}
int main() {
  cin >> UL.x >> UL.y >> DR.x >> DR.y;
  cin >> n;
  int i, j;
  R = vector<vector<int> >(n, vector<int>(3, 0));
  for (i = 0; i < n; i++) {
    cin >> R[i][0] >> R[i][1] >> R[i][2];
  }
  vector<P> colonels = GetColonels(UL, DR);
  int res = 0;
  for (i = 0; i < colonels.size(); i++) {
    for (j = 0; j < n; j++) {
      if (Dist2(colonels[i].x, colonels[i].y, R[j][0], R[j][1]) <=
          R[j][2] * R[j][2])
        break;
    }
    if (j == n) res++;
  }
  cout << res << endl;
  return 0;
}
