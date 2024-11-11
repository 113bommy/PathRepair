#include <bits/stdc++.h>
using namespace std;
struct Point {
  int id, x, y, ch, idx;
} points[2 * 100005];
Point pivot;
int orientation(Point p, Point q, Point r) {
  long long o = (q.y - p.y) * (r.x - q.x) - (r.y - q.y) * (q.x - p.x);
  if (o == 0) return o;
  return (o > 0) ? 1 : 2;
}
long long dis(Point p, Point q) {
  return ((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
}
bool cmp(Point p, Point q) {
  int tmp = orientation(pivot, p, q);
  if (tmp == 0) return (dis(pivot, p) >= dis(pivot, q));
  if (tmp == 2) return true;
  return false;
}
stack<Point> second;
Point nextToTop() {
  Point tmp = second.top();
  second.pop();
  Point ret = second.top();
  second.push(tmp);
  return ret;
}
int main() {
  int n;
  long long x, y;
  scanf("%d", &n);
  Point tmp;
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &x, &y);
    tmp.id = 1;
    tmp.x = x;
    tmp.y = y;
    points[i] = tmp;
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%lld %lld", &x, &y);
    tmp.id = 2;
    tmp.x = x;
    tmp.y = y;
    points[n + i] = tmp;
  }
  long long mny = 1e9 + 5, mnx, idx;
  for (int i = 0; i < n + m; i++) {
    if (points[i].y < mny) {
      mny = points[i].y;
      mnx = points[i].x;
      idx = i;
    } else if (points[i].y == mny) {
      if (points[i].x < mnx) {
        mnx = points[i].x;
        idx = i;
      }
    }
  }
  pivot = points[idx];
  swap(points[0], points[idx]);
  sort(points + 1, points + n + m, cmp);
  for (int i = 0; i < n + m; i++) points[i].idx = i;
  second.push(points[0]);
  second.push(points[1]);
  for (int i = 2; i < n + m; i++) {
    while (second.size() >= 2 &&
           orientation(nextToTop(), second.top(), points[i]) != 2)
      second.pop();
    second.push(points[i]);
  }
  bool fl = true;
  vector<int> ind;
  while (!second.empty()) {
    if (second.top().id == 2) {
      fl = false;
      break;
    }
    ind.push_back(second.top().idx);
    points[second.top().idx].ch = 1;
    second.pop();
  }
  if (!fl) {
    printf("NO\n");
    return 0;
  }
  reverse(ind.begin(), ind.end());
  int p1 = ind[0];
  int p2 = ind[1];
  int j = 2;
  while (p2 != ind[0]) {
    int tmp = p1 + 1;
    while (tmp != p2) {
      if (orientation(points[p1], points[tmp], points[p2]) == 0) {
        fl = false;
        break;
      }
      tmp++;
    }
    if (!fl) break;
    p1 = p2;
    p2 = ind[j];
    j = (j + 1) % ind.size();
  }
  if (fl) {
    printf("YES\n");
    return 0;
  }
  printf("NO\n");
  return 0;
}
