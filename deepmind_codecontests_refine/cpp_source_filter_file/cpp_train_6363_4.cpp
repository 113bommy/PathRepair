#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> a;
void go(int x1, int y1, int x2, int y2) {
  int i = min(x2, x1), j = min(y2, y1);
  if (x1 < x2 && y1 < y2) {
    while (i <= x2) {
      a.insert(make_pair(i, y1));
      i++;
    }
    while (j <= y2) {
      a.insert(make_pair(x2, j));
      j++;
    }
    return;
  }
  if (x1 < x2 && y1 >= y2) {
    while (i <= x2) {
      a.insert(make_pair(i, y1));
      i++;
    }
    while (j <= y1) {
      a.insert(make_pair(x2, j));
      j++;
    }
    return;
  }
  if (x1 >= x2 && y1 < y2) {
    while (i <= x1) {
      a.insert(make_pair(i, y1));
      i++;
    }
    while (j <= y2) {
      a.insert(make_pair(x1, j));
      j++;
    }
    return;
  }
  if (x1 >= x2 && y1 >= y2) {
    while (i <= x1) {
      a.insert(make_pair(i, y2));
      i++;
    }
    while (j <= y1) {
      a.insert(make_pair(x1, j));
      j++;
    }
    return;
  }
}
int main() {
  long long xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  long long x, y, ma = 3000700000;
  for (int i = min(xa, min(xb, xc)); i <= max(xa, max(xb, xc)); i++) {
    for (int j = min(ya, min(yb, yc)); j <= max(ya, max(yb, yc)); j++) {
      long long di = abs(i - xa) + abs(j - ya);
      di += abs(i - xb) + abs(j - yb);
      di += abs(i - xc) + abs(j - yc) + 1;
      if (ma > di) {
        ma = di;
        x = i;
        y = j;
      }
    }
  }
  go(x, y, xa, ya);
  go(x, y, xb, yb);
  go(x, y, xc, yc);
  cout << a.size() << '\n';
  for (auto it = a.begin(); it != a.end(); it++) {
    cout << it->first << ' ' << it->second << '\n';
  }
}
