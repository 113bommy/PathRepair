#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x[5];
} pt[1111];
double prod(Point p1, Point p2) {
  double res = 0;
  for (int i = 0; i < 5; i++) {
    res += p1.x[i] * p2.x[i];
  }
  return res;
}
double len(Point p) { return sqrt(prod(p, p)); }
double ang(Point p1, Point p2) {
  return acos(prod(p1, p2) / (len(p1) * len(p2)));
}
int main() {
  int n;
  cin >> n;
  double PI = 4 * atan(1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> pt[i].x[j];
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    bool bad = 0;
    for (int j = 1; j <= n; j++) {
      if (j == i) continue;
      for (int k = 1; k <= n; k++) {
        if (k == i || k == j) continue;
        Point p1, p2;
        for (int q = 0; q < 5; q++) {
          p1.x[q] = pt[j].x[q] - pt[i].x[q];
          p2.x[q] = pt[k].x[q] - pt[i].x[q];
        }
        if (ang(p1, p2) < PI / 2) {
          bad = 1;
          goto out;
        }
      }
    }
  out:
    if (bad) {
    } else {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }
  return 0;
}
