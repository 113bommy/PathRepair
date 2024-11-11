#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;
const long long inf = 1e18 + 100;
double EPS = 1e-12;
const int INF = 2000000000;
struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
  PT operator*(double c) const { return PT(x * c, y * c); }
  PT operator/(double c) const { return PT(x / c, y / c); }
};
double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS ||
        dist2(b, d) < EPS)
      return true;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
      return false;
    return true;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
  return true;
}
int n, m;
PT a[20], b[20];
int vis[20];
void solve(int idx) {
  if (idx == n) {
    cout << "Yes";
    exit(0);
  }
  for (int i = 0; i < m; i++) {
    if (vis[i] != -1) continue;
    bool kk = 1;
    for (int j = 0; j < m; j++) {
      if (vis[j] == -1) continue;
      if (SegmentsIntersect(a[idx], b[i], a[vis[j]], b[j])) {
        kk = 0;
        break;
      }
    }
    if (kk) {
      vis[i] = idx;
      solve(idx + 1);
      vis[i] = -1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n >> m;
  memset(vis, -1, sizeof(vis));
  if (n != m) return cout << "No", 0;
  for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
  for (int i = 0; i < m; i++) cin >> b[i].x >> b[i].y;
  solve(0);
  cout << "No";
  return 0;
}
