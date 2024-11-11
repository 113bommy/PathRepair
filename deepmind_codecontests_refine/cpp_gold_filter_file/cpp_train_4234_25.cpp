#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long int x;
  long long int y;
};
bool onSegment(Point p, Point q, Point r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
      q.y >= min(p.y, r.y))
    return true;
  return false;
}
int orientation(Point p, Point q, Point r) {
  long long int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;
  return (val > 0) ? 1 : 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
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
Point r[11];
Point b[11];
int main() {
  int R, B;
  cin >> R >> B;
  if (R != B) {
    cout << "No" << endl;
    return 0;
  }
  int curr[B];
  for (int i = 0; i < B; i++) curr[i] = i;
  for (int i = 0; i < R; i++) {
    long long int x, y;
    cin >> x >> y;
    r[i] = {x, y};
  }
  for (int i = 0; i < B; i++) {
    long long int x, y;
    cin >> x >> y;
    b[i] = {x, y};
  }
  do {
    int flag = 0;
    for (int i = 0; i < R - 1; i++) {
      if (doIntersect(r[i], b[curr[i]], r[i + 1], b[curr[i + 1]])) flag++;
    }
    if (flag == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(curr, curr + B));
  cout << "No" << endl;
  return 0;
}
