#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > points;
int n, m;
bool ok(int x, int y) {
  for (int i = 0; i < points.size(); ++i) {
    for (int j = i + 1; j < points.size(); ++j) {
      long double dx1 = x - points[i].first;
      long double dy1 = y - points[i].second;
      long double dx2 = x - points[j].first;
      long double dy2 = y - points[j].second;
      if (fabs(dx1 * dy2 - dx2 * dy1) <= 1e-6) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  int i;
  scanf("%d%d", &n, &m);
  if (n > 4 && m == 3) {
    cout << -1 << endl;
    return 0;
  }
  srand(time(NULL));
  long double R = 1e7;
  long double fi = 0.0;
  long double dfi = 2 * acos(-1.0) / m;
  for (i = 0; i < m; ++i) {
    long double x = R * cos(fi);
    long double y = R * sin(fi);
    int px = (int)x;
    int py = (int)y;
    points.push_back(make_pair(px, py));
    while (!ok(px, py)) {
      if (rand() & 1) {
        px++;
      } else {
        py++;
      }
    }
    cout << px << "  " << py << endl;
    fi += dfi;
  }
  R = 1e6;
  fi = 34.7456137;
  dfi = 2 * acos(-1.0) / (n - m);
  for (i = 0; i < n - m; ++i) {
    long double x = R * cos(fi);
    long double y = R * sin(fi);
    int px = (int)x;
    int py = (int)y;
    points.push_back(make_pair(px, py));
    while (!ok(px, py)) {
      if (rand() & 1) {
        px++;
      } else {
        py++;
      }
    }
    cout << px << "  " << py << endl;
    fi += dfi;
  }
  return 0;
}
