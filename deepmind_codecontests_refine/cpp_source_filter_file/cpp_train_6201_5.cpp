#include <bits/stdc++.h>
using namespace std;
set<pair<pair<int, int>, pair<int, int> > > s;
vector<int> ed[2][200000];
int n, m, k;
int a[200000], b[20000];
long long ans[200000];
bool add(int x, int y, int dx, int dy) {
  pair<pair<int, int>, pair<int, int> > g =
      make_pair(make_pair(x, y), make_pair(dx, dy));
  if (s.find(g) != s.end()) return false;
  s.insert(g);
  return true;
}
void go(int x, int y, int dx, int dy, long long t) {
  int tt = 1;
  int d = x - y + m;
  if (dx - dy != 0) {
    tt = 0;
    d = x + y;
  }
  bool f = add(x, y, dx, dy);
  if (!f) return;
  for (int j = 0; j < ed[tt][d].size(); j++) {
    int kx = a[ed[tt][d][j]];
    int ky = b[ed[tt][d][j]];
    kx = kx - x;
    ky = ky - y;
    kx = kx / dx;
    ky = ky / dy;
    int g = ed[tt][d][j];
    if (ans[g] != -1) continue;
    ans[g] = t + min(kx, ky);
  }
  if (dx == 1 && dy == 1) {
    int v = min(n - x, m - y);
    x += v;
    y += v;
    if (x == n && y == m) return;
    if (y == m)
      go(x, y, 1, -1, t + v);
    else
      go(x, y, -1, 1, t + v);
  }
  if (dx == -1 && dy == -1) {
    int v = min(x, y);
    x -= v;
    y -= v;
    if (x == 0 && y == 0) return;
    if (y == 0)
      go(x, y, -1, 1, t + v);
    else
      go(x, y, 1, -1, t + v);
  }
  if (dx == 1 && dy == -1) {
    int v = min(n - x, y);
    x += v;
    y -= v;
    if (x == n && y == 0) return;
    if (y == 0)
      go(x, y, 1, 1, t + v);
    else
      go(x, y, -1, -1, t + v);
  }
  if (dx == -1 && dy == 1) {
    int v = min(x, m - y);
    x -= v;
    y += v;
    if (x == 0 && y == m) return;
    if (x == 0)
      go(x, y, 1, 1, t + v);
    else
      go(x, y, -1, -1, t + v);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) ans[i] = -1;
  for (int i = 1; i <= k; i++) {
    cin >> a[i] >> b[i];
    ed[0][a[i] + b[i]].push_back(i);
    ed[1][a[i] - b[i] + m].push_back(i);
  }
  go(0, 0, 1, 1, 0);
  for (int i = 1; i <= k; i++) cout << ans[i] << "\n";
  return 0;
}
