#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
struct pt {
  long long x, y;
  pt(long long x = 0, long long y = 0) : x(x), y(y) {}
  pt operator-(const pt &o) const { return pt(x - o.x, y - o.y); }
  long long cross(const pt &o) const { return x * o.y - y * o.x; }
  bool upper() const { return y > 0 || (y == 0 && x > 0); }
  bool operator<(const pt &o) const {
    if (upper() != o.upper()) return upper();
    return cross(o) > 0;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pt> r(n), b(m);
  for (int i = (0); i < (n); i++) cin >> r[i].x >> r[i].y;
  for (int i = (0); i < (m); i++) cin >> b[i].x >> b[i].y;
  long long cnt = 0;
  for (int i = (0); i < (n); i++) {
    vector<pair<pt, bool>> ve;
    for (int j = (i + 1); j < (n); j++) ve.push_back({r[j] - r[i], true});
    for (int j = (0); j < (m); j++) ve.push_back({b[j] - r[i], false});
    sort((ve).begin(), (ve).end());
    int si = ((int)(ve).size());
    for (int j = (0); j < (si); j++) {
      if (ve[j].second) {
        pt base = ve[j].first, blue = base;
        for (int k = j + 1; k != j; k = (k + 1) % si) {
          if (base.cross(ve[k].first) < 0) break;
          if (ve[k].second) {
            if (blue.cross(ve[k].first - base) > 0) cnt++;
          } else if (blue.cross(ve[k].first - base) > 0) {
            blue = ve[k].first - base;
          }
        }
      }
    }
  }
  cout << cnt << '\n';
}
