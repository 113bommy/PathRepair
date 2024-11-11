#include <bits/stdc++.h>
using namespace std;
double f(pair<int, int> p1, pair<int, int> p2) {
  int dx = p1.first - p2.first;
  int dy = p1.second - p2.second;
  return sqrt(dx * dx + dy * dy);
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    set<pair<int, int> > S;
    int x0[2] = {0, n};
    int y0[2] = {0, m};
    for (int i = 0; i < 2; i++) {
      for (int dx = -3; dx <= 3; dx++) {
        for (int dy = -3; dy <= 3; dy++) {
          int xx = x0[i] + dx;
          int yy = y0[i] + dy;
          if (xx >= 0 && xx <= n && yy >= 0 && yy <= m)
            S.insert(make_pair(xx, yy));
        }
      }
    }
    vector<pair<int, int> > v(S.begin(), S.end());
    double maxD = 0;
    int ii1, ii2, ii3, ii4;
    for (int i1 = 0; i1 < v.size(); i1++) {
      for (int i2 = 0; i2 < v.size(); i2++) {
        for (int i3 = 0; i3 < v.size(); i3++) {
          for (int i4 = 0; i4 < v.size(); i4++) {
            if (i1 != i2 && i1 != i3 && i1 != i4 && i2 != i3 && i2 != i4 &&
                i3 != i4) {
              double d = f(v[i1], v[i2]) + f(v[i2], v[i3]) + f(v[i3], v[i4]);
              if (d > maxD) {
                maxD = d;
                ii1 = i1;
                ii2 = i2;
                ii3 = i3;
                ii4 = i4;
              }
            }
          }
        }
      }
    }
    cout << v[ii1].first << " " << v[ii1].second << endl;
    cout << v[ii2].first << " " << v[ii2].second << endl;
    cout << v[ii3].first << " " << v[ii3].second << endl;
    cout << v[ii4].first << " " << v[ii4].second << endl;
  }
  return 0;
}
