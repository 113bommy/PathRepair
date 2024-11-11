#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l = 0, a, b, c, d, x, y;
  cin >> n;
  pair<int, int> points;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    points.first = x;
    points.second = y;
    v.push_back(points);
  }
  for (int i = 0; i < n; i++) {
    a = 0, d = 0, b = 0, c = 0;
    int x1 = v[i].first;
    int y1 = v[i].second;
    for (int j = 0; j < n; j++)
      if (i != j) {
        int x2 = v[j].first;
        int y2 = v[j].second;
        if (x1 > x2 && y1 == y2)
          a = 1;
        else if (x1 < x2 && y1 == y2)
          b = 1;
        else if (x1 == x2 && y1 < y2)
          c = 1;
        else if (x1 == x2 && y1 > y2)
          d = 1;
      }
    if (a == 1 && b == 1 && c == 1 && d == 1) l++;
  }
  cout << l;
}
