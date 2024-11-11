#include <bits/stdc++.h>
using namespace std;
struct pt {
  long long x, y;
};
bool cmp(pt a, pt b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
long long f(pt a, pt b, pt c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}
bool cw(pt a, pt b, pt c) { return f(a, b, c) < 0; }
bool ccw(pt a, pt b, pt c) { return f(a, b, c) > 0; }
int convex_hull(vector<pt>& a) {
  sort(a.begin(), a.end(), &cmp);
  vector<pt> b;
  b.push_back(a[0]);
  for (int i = 1; i < a.size(); i++)
    if (a[i - 1].x != a[i].x || a[i - 1].y != a[i].y) b.push_back(a[i]);
  a = b;
  if (a.size() <= 2) return a.size() - 1;
  pt p1 = a[0];
  pt p2 = a.back();
  vector<pt> up;
  up.push_back(p1);
  for (int i = 1; i < a.size(); i++) {
    if (i == a.size() - 1 || cw(p1, a[i], p2)) {
      while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }
  }
  int cnt = 0;
  for (int i = 1; i < up.size(); i++) {
    if (up[i].x != up[i - 1].x) cnt++;
  }
  return cnt;
}
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> n;
  vector<pt> a;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].y = a[i].y - a[i].x * a[i].x;
  }
  cout << convex_hull(a);
  return 0;
}
