#include <bits/stdc++.h>
using namespace std;
template <class T>
bool setmax(T& _a, T _b) {
  if (_b > _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T& _a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
template <class T>
T max(T a, T b, T c, T d) {
  return max(max(a, b), max(c, d));
}
struct Point {
  int x = 0, y = 0;
  Point() {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  void read() { scanf("%d%d", &x, &y); }
};
struct Ans {
  Point p[4];
  int travel = numeric_limits<int>::max();
  bool operator<(const Ans& a) const { return travel < a.travel; }
  Ans rev() const {
    Ans r = *this;
    for (int i = int(0); i <= int((4) - 1); ++i) swap(r.p[i].x, r.p[i].y);
    return r;
  }
};
Ans check(map<int, vector<pair<int, int>>> cx,
          map<int, vector<pair<int, int>>> cy, int x1, int x2, int y1, int y2) {
  if (x2 - x1 != y2 - y1 || x1 == x2) return Ans();
  Point target[4] = {Point{x1, y1}, Point{x2, y1}, Point{x1, y2},
                     Point{x2, y2}};
  int g[4][4];
  memset(g, 50, sizeof(g));
  for (const auto& kv : cx)
    for (pair<int, int> p : kv.second) {
      for (int i = int(0); i <= int((4) - 1); ++i)
        if (kv.first == target[i].x) {
          setmin(g[p.second][i], abs(p.first - target[i].y));
        }
    }
  for (const auto& kv : cy)
    for (pair<int, int> p : kv.second) {
      for (int i = int(0); i <= int((4) - 1); ++i)
        if (kv.first == target[i].y) {
          setmin(g[p.second][i], abs(p.first - target[i].x));
        }
    }
  Ans ans;
  for (int i = int(0); i <= int((4) - 1); ++i)
    for (int j = int(0); j <= int((4) - 1); ++j)
      if (j != i)
        for (int k = int(0); k <= int((4) - 1); ++k)
          if (k != i && k != j) {
            int l = 0 + 1 + 2 + 3 - i - j - k;
            if (setmin(ans.travel, max(g[0][i], g[1][j], g[2][k], g[3][l]))) {
              ans.p[0] = target[i];
              ans.p[1] = target[j];
              ans.p[2] = target[k];
              ans.p[3] = target[l];
            }
          }
  return ans;
}
Ans easy(map<int, vector<pair<int, int>>> cx) {
  assert(cx.size() == 2);
  if (cx.begin()->second.size() != 2) return Ans();
  sort(cx.begin()->second.begin(), cx.begin()->second.end());
  sort(cx.rbegin()->second.begin(), cx.rbegin()->second.end());
  int le = 0, ri = 200000000;
  Point p[4];
  auto ok = [&p, &cx](int len) {
    int d = cx.rbegin()->first - cx.begin()->first;
    int l = -1 << 30, r = 1 << 30;
    for (const auto& kv : cx) {
      setmax(l, kv.second[0].first - len);
      setmin(r, kv.second[0].first + len);
      setmax(l, kv.second[1].first - d - len);
      setmin(r, kv.second[1].first - d + len);
    }
    if (l > r) return false;
    for (const auto& kv : cx) {
      p[kv.second[0].second] = Point(kv.first, l);
      p[kv.second[1].second] = Point(kv.first, l + d);
    }
    return true;
  };
  while (le < ri) {
    int mid = (le + ri) / 2;
    if (ok(mid))
      ri = mid;
    else
      le = mid + 1;
  }
  ok(le);
  Ans ans;
  ans.travel = le;
  for (int i = int(0); i <= int((4) - 1); ++i) ans.p[i] = p[i];
  return ans;
}
Ans solve(map<int, vector<pair<int, int>>> cx,
          map<int, vector<pair<int, int>>> cy) {
  assert(cx.size() + cy.size() > 0);
  if (cx.size() >= 3 || cy.size() >= 3) return Ans();
  if (cx.size() + cy.size() == 1) return Ans();
  if (cx.size() == 2 && cy.size() == 0) {
    return easy(cx);
  }
  if (cx.size() == 0 && cy.size() == 2) return solve(cy, cx).rev();
  if (cx.size() == 1 && cy.size() == 1) return Ans();
  if (cx.size() == 2 && cy.size() == 1) {
    int x1 = cx.begin()->first, x2 = cx.rbegin()->first, d = x2 - x1;
    int y = cy.begin()->first;
    return min(check(cx, cy, x1, x2, y, y + d),
               check(cx, cy, x1, x2, y - d, y));
  }
  if (cx.size() == 1 && cy.size() == 2) return solve(cy, cx).rev();
  if (cx.size() == 2 && cy.size() == 2) {
    return check(cx, cy, cx.begin()->first, cx.rbegin()->first,
                 cy.begin()->first, cy.rbegin()->first);
  }
  assert(false);
}
int main() {
  int cs;
  scanf("%d", &cs);
  while (cs--) {
    Point p[4];
    for (int i = int(0); i <= int((4) - 1); ++i) p[i].read();
    int dir[4];
    Ans ans;
    for (dir[0] = 0; dir[0] < 2; ++dir[0])
      for (dir[1] = 0; dir[1] < 2; ++dir[1])
        for (dir[2] = 0; dir[2] < 2; ++dir[2])
          for (dir[3] = 0; dir[3] < 2; ++dir[3]) {
            map<int, vector<pair<int, int>>> cx, cy;
            for (int i = int(0); i <= int((4) - 1); ++i)
              if (dir[i] == 0) {
                cx[p[i].x].push_back(make_pair(p[i].y, i));
              } else {
                cy[p[i].y].push_back(make_pair(p[i].x, i));
              }
            Ans tmp = solve(cx, cy);
            setmin(ans, tmp);
          }
    if (ans.travel < numeric_limits<int>::max()) {
      printf("%d\n", ans.travel);
      for (int i = int(0); i <= int((4) - 1); ++i)
        printf("%d %d\n", ans.p[i].x, ans.p[i].y);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
