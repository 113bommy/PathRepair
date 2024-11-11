#include <bits/stdc++.h>
using namespace std;
struct line {
  int x, y, l;
};
struct query {
  int x, y, z, t;
  query(int _x, int _y, int _z, int _t) { x = _x, y = _y, z = _z, t = _t; }
  void dbg() { cout << x << ' ' << y << ' ' << z << ' ' << t << '\n'; }
};
bool cmp(query p, query q) { return p.x == q.x ? p.t < q.t : p.x < q.x; }
const int N = 5e4 + 10;
int n, m;
line hor[N], ver[N];
bool f(int x) {
  vector<query> v;
  for (int i = 1; i <= n; ++i) {
    if (ver[i].l >= x * 2) {
      v.push_back(query(ver[i].x, ver[i].y + x, ver[i].y + ver[i].l - x, 0));
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (hor[i].l >= x * 2) {
      v.push_back(query(hor[i].x + x, hor[i].y, 0, -1));
      v.push_back(query(hor[i].x + hor[i].l - x, hor[i].y, 0, 1));
    }
  }
  sort(v.begin(), v.end(), cmp);
  multiset<int> s;
  multiset<int>::iterator it1, it2;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i].t == 0) {
      it1 = s.lower_bound(v[i].y);
      it2 = s.lower_bound(v[i].z + 1);
      if (it1 != it2) return 1;
    } else if (v[i].t == -1) {
      s.insert(v[i].y);
    } else {
      s.erase(s.find(v[i].y));
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> ver[i].x >> ver[i].y >> ver[i].l;
  for (int i = 1; i <= m; ++i) cin >> hor[i].x >> hor[i].y >> hor[i].l;
  int l = 0, r = 50000000;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    if (f(m))
      l = m;
    else
      r = m - 1;
  }
  cout << l;
}
