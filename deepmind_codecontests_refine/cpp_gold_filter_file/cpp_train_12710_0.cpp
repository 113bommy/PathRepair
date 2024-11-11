#include <bits/stdc++.h>
using namespace std;
using Point = array<int, 3>;
using Box = pair<Point, Point>;
struct Event {
  int type;
  int x;
  Point p;
  Box b;
  int id;
  Event(int type, Point p) : type(type), x(p[0]), p(p) {}
  Event(int type, int x, Box b, int id) : type(type), x(x), b(b), id(id) {}
  friend bool operator<(const Event& f, const Event& s) {
    if (f.x != s.x) {
      return f.x < s.x;
    }
    return f.type < s.type;
  }
};
struct FenwTree {
  int n = 0;
  vector<int> f;
  FenwTree() {}
  FenwTree(int n) : n(n), f(n + 1) {}
  void inc(int pos) {
    for (int i = pos + 1; i <= n; i += i & -i) {
      ++f[i];
    }
  }
  int sum(int pos) {
    int s = 0;
    for (int i = pos + 1; i > 0; i -= i & -i) {
      s += f[i];
    }
    return s;
  }
  int sum(int l, int r) { return l > r ? 0 : sum(r) - sum(l - 1); }
};
struct SegTree {
  int n;
  vector<vector<int>> t;
  vector<vector<int>> h;
  vector<FenwTree> f;
  vector<int> cx;
  SegTree(const vector<Point>& pts) {
    for (auto& p : pts) {
      cx.push_back(p[1]);
    }
    sort(cx.begin(), cx.end());
    cx.erase(unique(cx.begin(), cx.end()), cx.end());
    n = (int)cx.size();
    h.resize(n);
    t.resize(4 * n);
    f.resize(4 * n);
    for (auto& p : pts) {
      int x = lower_bound(cx.begin(), cx.end(), p[1]) - cx.begin();
      h[x].push_back(p[2]);
    }
    build(1, 0, n - 1, h);
  }
  void build(int v, int tl, int tr, const vector<vector<int>>& h) {
    for (int i = tl; i <= tr; ++i) {
      t[v].insert(t[v].end(), h[i].begin(), h[i].end());
    }
    sort(t[v].begin(), t[v].end());
    t[v].erase(unique(t[v].begin(), t[v].end()), t[v].end());
    f[v] = FenwTree((int)t[v].size());
    if (tl != tr) {
      int tm = (tl + tr) / 2;
      build(2 * v, tl, tm, h);
      build(2 * v + 1, tm + 1, tr, h);
    }
  }
  int sum(int lx, int rx, int ly, int ry) {
    int l = lower_bound(cx.begin(), cx.end(), lx) - cx.begin();
    int r = upper_bound(cx.begin(), cx.end(), rx) - cx.begin() - 1;
    return sum(1, 0, n - 1, l, r, ly, ry);
  }
  int sum(int v, int tl, int tr, int l, int r, int ly, int ry) {
    if (l > tr || r < tl || l > r) {
      return 0;
    }
    if (l <= tl && r >= tr) {
      ly = lower_bound(t[v].begin(), t[v].end(), ly) - t[v].begin();
      ry = upper_bound(t[v].begin(), t[v].end(), ry) - t[v].begin() - 1;
      return f[v].sum(ly, ry);
    }
    int tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, r, ly, ry) +
           sum(2 * v + 1, tm + 1, tr, l, r, ly, ry);
  }
  void update(int x, int y) {
    x = lower_bound(cx.begin(), cx.end(), x) - cx.begin();
    update(1, 0, n - 1, x, y);
  }
  void update(int v, int tl, int tr, int pos, int val) {
    int p = lower_bound(t[v].begin(), t[v].end(), val) - t[v].begin();
    f[v].inc(p);
    if (tl == tr) {
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(2 * v, tl, tm, pos, val);
    } else {
      update(2 * v + 1, tm + 1, tr, pos, val);
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Box box;
  for (int i = 0; i < 3; ++i) {
    int b;
    cin >> b;
    box.first[i] = b;
    box.second[i] = 1;
  }
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int x;
      cin >> x;
      box.first[j] = min(box.first[j], x);
      box.second[j] = max(box.second[j], x);
    }
  }
  vector<Event> events;
  vector<Point> pts;
  for (int i = 0; i < m; ++i) {
    Point p;
    bool inside = true;
    for (int j = 0; j < 3; ++j) {
      cin >> p[j];
      if (p[j] < box.first[j] || p[j] > box.second[j]) {
        inside = false;
      }
    }
    if (inside) {
      cout << "INCORRECT\n";
      return 0;
    }
    events.emplace_back(1, p);
    pts.push_back(p);
  }
  if (pts.empty()) {
    pts.push_back({0, 0, 0});
  }
  for (int i = 0; i < k; ++i) {
    Box query = box;
    for (int j = 0; j < 3; ++j) {
      int x;
      cin >> x;
      query.first[j] = min(query.first[j], x);
      query.second[j] = max(query.second[j], x);
    }
    if (query != box) {
      events.emplace_back(0, query.first[0], query, i);
      events.emplace_back(2, query.second[0], query, i);
    }
  }
  SegTree tree(pts);
  sort(events.begin(), events.end());
  vector<int> s(k);
  vector<int> result(k);
  for (auto& e : events) {
    switch (e.type) {
      case 0:
        s[e.id] =
            tree.sum(e.b.first[1], e.b.second[1], e.b.first[2], e.b.second[2]);
        break;
      case 1:
        tree.update(e.p[1], e.p[2]);
        break;
      case 2:
        result[e.id] = (s[e.id] == tree.sum(e.b.first[1], e.b.second[1],
                                            e.b.first[2], e.b.second[2]))
                           ? 1
                           : 2;
        break;
    }
  }
  cout << "CORRECT\n";
  string out[] = {"OPEN", "UNKNOWN", "CLOSED"};
  for (int i = 0; i < k; ++i) {
    cout << out[result[i]] << '\n';
  }
}
