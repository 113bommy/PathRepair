#include <bits/stdc++.h>
using namespace std;
int n, m;
int xc, yc, k;
vector<pair<long long, long long> > v;
long long minm(long long a, long long b) {
  if (a < b) return a;
  return b;
}
void solve() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &xc, &yc);
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    v.push_back(make_pair(t1, t2));
  }
  long long cx, cy;
  long long steps = 0;
  cx = xc;
  cy = yc;
  for (int i = 0; i < k; i++) {
    long long t1, t2;
    long long dx, dy;
    dx = v[i].first;
    dy = v[i].second;
    if (dx == 0 && dy == 0) continue;
    t1 = t2 = 1 << 28;
    if (dx > 0) {
      t1 = (n - cx) / dx;
    } else if (dx < 0) {
      t1 = (cx - 1) / (-dx);
    }
    if (dy > 0) {
      t2 = (m - cy) / dy;
    } else if (dy < 0) {
      t2 = (cy - 1) / (-dy);
    }
    t1 = minm(t1, t2);
    cx += t1 * dx;
    cy += t1 * dy;
    steps += t1;
  }
  cout << steps << endl;
}
int main() {
  solve();
  return 0;
}
