#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  point(long long X = 0, long long Y = 0) {
    x = X;
    y = Y;
  }
};
struct rectangle {
  point f, s;
  rectangle() {}
};
struct event {
  long long X, minY, maxY;
  bool flag;
  event(long long x, long long miny, long long maxy, bool F) {
    X = x;
    minY = miny;
    maxY = maxy;
    flag = F;
  }
};
vector<rectangle> v;
vector<event> a;
bool solve() {
  a.clear();
  for (long long i = 0; i < v.size(); i++) {
    a.push_back(event(v[i].f.x, v[i].f.y, v[i].s.y, 0));
    a.push_back(event(v[i].s.x + 1, v[i].f.y, v[i].s.y, 1));
  }
  sort(a.begin(), a.end(), [](const event& a, const event& b) {
    if (a.X != b.X)
      return a.X < b.X;
    else
      return a.flag > b.flag;
  });
  multiset<long long> s1, s2;
  for (long long i = 0; i < a.size(); i++) {
    if (a[i].flag == 0) {
      if (s1.size()) {
      }
      if (s1.size() && (*s1.begin() > a[i].maxY || *s2.rbegin() < a[i].minY)) {
        return true;
      }
      s1.insert(a[i].minY);
      s2.insert(a[i].maxY);
    } else {
      s1.erase(s1.find(a[i].minY));
      s2.erase(s2.find(a[i].maxY));
    }
  }
  return false;
}
int32_t main() {
  long long n;
  cin >> n;
  v.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].f.x >> v[i].s.x >> v[i].f.y >> v[i].s.y;
  }
  bool ans = false;
  if (solve()) ans = true;
  for (long long i = 0; i < n; i++) {
    swap(v[i].f.x, v[i].f.y);
    swap(v[i].s.x, v[i].s.y);
  }
  if (solve()) ans = true;
  if (ans)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
