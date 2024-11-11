#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
struct Point {
  int x;
  int y;
};
bool onSegment(Point& p, Point& q, Point& r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
      q.y >= min(p.y, r.y))
    return true;
  return false;
}
int orientation(Point& p, Point& q, Point& r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;
  return (val > 0) ? 1 : 2;
}
bool doIntersect(Point& p1, Point& q1, Point& p2, Point& q2) {
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);
  if (o1 != o2 && o3 != o4) return true;
  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  int r, b;
  cin >> r >> b;
  if (r != b) {
    cout << "No" << endl;
    return 0;
  }
  int n = r;
  vector<Point> pR(n);
  for (int i = 0; i < n; i++) cin >> pR[i].x >> pR[i].y;
  vector<Point> pB(n);
  for (int i = 0; i < n; i++) cin >> pB[i].x >> pB[i].y;
  bool result = false;
  vector<int> permutation(n);
  for (int i = 0; i < n; i++) permutation[i] = i;
  do {
    bool res = true;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        res &=
            !doIntersect(pR[i], pB[permutation[i]], pR[j], pB[permutation[j]]);
    result |= res;
    if (res) break;
  } while (!next_permutation(permutation.begin(), permutation.end()));
  cout << (result ? "Yes" : "No") << endl;
}
