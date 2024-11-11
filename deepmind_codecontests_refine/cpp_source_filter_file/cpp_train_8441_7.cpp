#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
struct point {
  long long first, second;
  point() {}
  point(long long a, long long b) {
    first = a;
    second = b;
  }
  point operator+(const point &o) {
    return point(first + o.first, second + o.second);
  }
  point operator-(const point &o) {
    return point(first - o.first, second - o.second);
  }
};
long long cross(point a, point b) {
  return a.first * b.second - a.second * b.first;
}
long long dot(point a, point b) {
  return a.first * b.first + a.second * b.second;
}
double atan2(point a) { return atan2(a.first, a.second); }
int n;
long long ans;
vector<point> pts;
void sweep(int id) {
  vector<point> v;
  for (int i = 0; i < n; i++)
    if (i != id) v.push_back(pts[i]);
  point p = pts[id];
  sort(v.begin(), v.end(), [&](point a, point b) {
    if ((a.second >= p.second) != (b.second >= p.second))
      return a.second >= p.second;
    return cross(a - p, b - p) < 0;
  });
  int r = 0;
  for (int l = 0; l < (int)v.size(); l++) {
    int rr = (r + 1) % (int)v.size();
    while (rr != l && cross(v[l] - p, v[rr] - p) < 0)
      rr = (rr + 1) % (int)v.size();
    r = rr - 1;
    int R = (r - l + (int)v.size()) % (int)v.size(), L = n - R - 2;
    ans += R * (R - 1) / 2 * L * (L - 1) / 2;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  pts.resize(n);
  for (int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;
  for (int i = 0; i < n; i++) sweep(i);
  cout << ans / 2 << "\n";
  return 0;
}
