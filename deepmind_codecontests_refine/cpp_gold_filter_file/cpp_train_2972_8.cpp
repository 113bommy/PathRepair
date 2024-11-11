#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 1;
struct pt {
  long long x, y;
} G;
bool cmp(pt a, pt b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
long long n, S;
vector<pt> hull, p;
bool ccw1(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
bool ccw2(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
double Area(long long i, long long j, long long k) {
  double d1 = sqrt((hull[i].x - hull[j].x) * (hull[i].x - hull[j].x) +
                   (hull[i].y - hull[j].y) * (hull[i].y - hull[j].y));
  double d2 = sqrt((hull[j].x - hull[k].x) * (hull[j].x - hull[k].x) +
                   (hull[j].y - hull[k].y) * (hull[j].y - hull[k].y));
  double d3 = sqrt((hull[k].x - hull[i].x) * (hull[k].x - hull[i].x) +
                   (hull[k].y - hull[i].y) * (hull[k].y - hull[i].y));
  double p = (d1 + d2 + d3) / 2;
  return sqrt(p * (p - d1)) * sqrt((p - d2) * (p - d3));
}
void monotone() {
  vector<pt> upper;
  vector<pt> lower;
  sort(p.begin(), p.end(), cmp);
  for (long long i = 0; i < p.size(); ++i) {
    while (upper.size() > 1 &&
           !ccw1(upper[upper.size() - 2], upper[upper.size() - 1], p[i]))
      upper.pop_back();
    upper.push_back(p[i]);
    while (lower.size() > 1 &&
           !ccw2(lower[lower.size() - 2], lower[lower.size() - 1], p[i]))
      lower.pop_back();
    lower.push_back(p[i]);
  }
  for (long long i = 0; i < upper.size(); ++i) hull.push_back(upper[i]);
  for (long long i = lower.size() - 2; i > 0; --i) hull.push_back(lower[i]);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> S;
  for (long long i = 0; i < n; ++i) {
    cin >> G.x >> G.y;
    p.push_back(G);
  }
  monotone();
  n = hull.size();
  long long A = 0, B = 1, C = 2;
  long long i = 0, j = 1, k = 2;
  while (i < n) {
    while (1) {
      while (Area(i, j, k) <= Area(i, j, (k + 1) % n)) k = (k + 1) % n;
      if (Area(i, j, k) <= Area(i, (j + 1) % n, k)) {
        j = (j + 1) % n;
        continue;
      }
      break;
    }
    if (Area(i, j, k) > Area(A, B, C)) A = i, B = j, C = k;
    i++;
    if (i == j) j = (j + 1) % n;
    if (j == k) k = (k + 1) % n;
  }
  pt AA;
  pt BB;
  pt CC;
  AA.x = hull[B].x + hull[C].x - hull[A].x;
  BB.x = hull[A].x + hull[C].x - hull[B].x;
  CC.x = hull[A].x + hull[B].x - hull[C].x;
  AA.y = hull[B].y + hull[C].y - hull[A].y;
  BB.y = hull[A].y + hull[C].y - hull[B].y;
  CC.y = hull[A].y + hull[B].y - hull[C].y;
  cout << AA.x << " " << AA.y << "\n";
  cout << BB.x << " " << BB.y << "\n";
  cout << CC.x << " " << CC.y << "\n";
}
