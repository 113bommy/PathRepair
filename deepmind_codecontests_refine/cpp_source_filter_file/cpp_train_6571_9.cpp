#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1;
  int x2, y2;
  int x3, y3;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;
  long long mini = 1000000;
  int x, y;
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      int disty = abs(x1 - i) + abs(x2 - i) + abs(x3 - i);
      disty += abs(y1 - j) + abs(y2 - j) + abs(y3 - j);
      if (mini > disty) {
        x = i;
        y = j;
        mini = disty;
      }
    }
  }
  set<pair<long long, long long> > points;
  int add = 0;
  if (x > x1)
    add = -1;
  else
    add = 1;
  for (long long i = x;; i += add) {
    points.insert(make_pair(i, y));
    if (i == x1) break;
  }
  if (x > x2)
    add = -1;
  else
    add = 1;
  for (long long i = x;; i += add) {
    points.insert(make_pair(i, y));
    if (i == x2) break;
  }
  if (x > x3)
    add = -1;
  else
    add = 1;
  for (long long i = x;; i += add) {
    points.insert(make_pair(i, y));
    if (i == x3) break;
  }
  if (y > y1)
    add = -1;
  else
    add = 1;
  for (long long i = y;; i += add) {
    points.insert(make_pair(x1, y));
    if (i == y1) break;
  }
  if (y > y2)
    add = -1;
  else
    add = 1;
  for (long long i = y;; i += add) {
    points.insert(make_pair(x2, y));
    if (i == y2) break;
  }
  if (y > y3)
    add = -1;
  else
    add = 1;
  for (long long i = y;; i += add) {
    points.insert(make_pair(x3, y));
    if (i == y3) break;
  }
  points.insert(make_pair(x1, y1));
  points.insert(make_pair(x2, y2));
  points.insert(make_pair(x3, y3));
  set<pair<long long, long long> > points2;
  add = 0;
  if (y > y1)
    add = -1;
  else
    add = 1;
  for (long long i = y;; i += add) {
    points2.insert(make_pair(x, i));
    if (i == y1) break;
  }
  if (y > y2)
    add = -1;
  else
    add = 1;
  for (long long i = y;; i += add) {
    points2.insert(make_pair(x, i));
    if (i == y2) break;
  }
  if (y > y3)
    add = -1;
  else
    add = 1;
  for (long long i = y;; i += add) {
    points2.insert(make_pair(x, i));
    if (i == y3) break;
  }
  if (x > x1)
    add = -1;
  else
    add = 1;
  for (long long i = x;; i += add) {
    points2.insert(make_pair(i, y1));
    if (i == x1) break;
  }
  if (x > x2)
    add = -1;
  else
    add = 1;
  for (long long i = x;; i += add) {
    points2.insert(make_pair(i, y2));
    if (i == x2) break;
  }
  if (x > x3)
    add = -1;
  else
    add = 1;
  for (long long i = x;; i += add) {
    points2.insert(make_pair(i, y3));
    if (i == x3) break;
  }
  points2.insert(make_pair(x, y));
  points.insert(make_pair(x, y));
  points2.insert(make_pair(x1, y1));
  points2.insert(make_pair(x2, y2));
  points2.insert(make_pair(x3, y3));
  if (points.size() < points2.size()) {
    cout << points.size() << endl;
    for (auto y : points) {
      cout << y.first << " " << y.second << endl;
    }
  } else {
    cout << points2.size() << endl;
    for (auto y : points2) {
      cout << y.first << " " << y.second << endl;
    }
  }
}
