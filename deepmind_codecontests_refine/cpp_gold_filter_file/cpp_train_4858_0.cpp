#include <bits/stdc++.h>
using namespace std;
class point {
 public:
  int x, y;
  void get() { cin >> x >> y; }
  void out() { cout << x << " " << y << "\n"; }
};
class ev {
 public:
  int x, y1, y2;
  bool window;
  ev(int X, int Y1, int Y2, bool WINDOW)
      : x(X), y1(Y1), y2(Y2), window(WINDOW) {}
};
bool cmp(ev& a, ev& b) {
  return (a.x == b.x ? a.window < b.window : a.x < b.x);
}
point v1, v2;
set<int> s;
void change(int x) {
  if (s.count(x))
    s.erase(x);
  else
    s.insert(x);
}
void inside(int& y) { y = min(max(y, v1.y), v2.y); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  v1.get(), v2.get();
  swap(v1.y, v2.y);
  int n;
  cin >> n;
  vector<point> v(n);
  for (int i = 0; i < n; i++) v[i].get();
  vector<ev> e;
  e.push_back(ev(v1.x, v1.y, v2.y, true));
  e.push_back(ev(v2.x, v1.y, v2.y, true));
  for (int i = 0; i < n; i++) {
    if (v[i].x != v[(i + 1) % n].x) continue;
    e.push_back(ev(v[i].x, v[i].y, v[(i + 1) % n].y, false));
  }
  sort(e.begin(), e.end(), cmp);
  int ans = 0;
  for (int i = 0; i < e.size(); i++) {
    if (e[i].window) {
      if (e[i].x == v1.x)
        ans = s.size() / 2;
      else
        break;
      continue;
    }
    if (max(e[i].y1, e[i].y2) <= v1.y || min(e[i].y1, e[i].y2) >= v2.y)
      continue;
    int pv = s.size() / 2;
    inside(e[i].y1), inside(e[i].y2);
    change(e[i].y1), change(e[i].y2);
    if (v1.x <= e[i].x && e[i].x < v2.x && e[i].y2 < e[i].y1) {
      if (s.size() / 2 < pv) ans--;
      if (s.size() / 2 > pv) ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
