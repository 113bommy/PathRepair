#include <bits/stdc++.h>
using namespace std;
struct T {
  int x1, y1, x2, y2;
  bool operator<(const T& oth) const {
    if (x1 != oth.x1)
      return x1 < oth.x1;
    else if (y1 != oth.y1)
      return y1 < oth.y1;
    else if (x2 != oth.x2)
      return x2 < oth.x2;
    else
      return y2 < oth.y2;
  }
  void print() { cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n'; }
  void inverse() {
    swap(x1, y1);
    swap(x2, y2);
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
  }
};
bool intersect(T a, T b) {
  swap(a, b);
  return a.x1 < b.x1 && a.x2 > b.x1 && b.y1 < a.y1 && b.y2 > a.y1;
}
const int MaxN = 1e3 + 13;
int n;
int match[MaxN];
int matchTo[MaxN];
int sa, sb;
vector<int> edges[MaxN];
bool used[MaxN];
bool useda[MaxN], usedb[MaxN];
bool dfs(int x) {
  if (used[x]) return false;
  used[x] = true;
  for (int to : edges[x])
    if (!match[to] || dfs(match[to])) {
      match[to] = x;
      matchTo[x] = to;
      return true;
    }
  return false;
}
void findMatching() {
  for (int i = 1; i <= sa; ++i) {
    dfs(i);
    for (int i = 1; i <= sa; ++i) used[i] = false;
  }
}
vector<int> da, db;
void dfs2(int h, int x) {
  if (h == 0) {
    if (useda[x]) return;
    useda[x] = true;
    for (int to : edges[x])
      if (to != matchTo[x]) dfs2(1, to);
  } else {
    if (usedb[x]) return;
    usedb[x] = true;
    if (match[x]) dfs2(0, match[x]);
  }
}
vector<T> va;
vector<T> vb;
set<T> badT;
void findDominate() {
  for (int i = 1; i <= sa; ++i)
    if (!matchTo[i]) dfs2(0, i);
  for (int i = 1; i <= sa; ++i)
    if (!useda[i]) {
      da.push_back(i - 1);
      badT.insert(va[i - 1]);
    }
  for (int i = 1; i <= sb; ++i)
    if (usedb[i]) {
      db.push_back(i - 1);
      badT.insert(vb[i - 1]);
    }
}
void solve() {
  cin >> n;
  vector<pair<int, int> > a;
  vector<pair<int, int> > b;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y});
    b.push_back({y, x});
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int la = 1; la < a.size(); ++la)
    if (a[la].first == a[la - 1].first)
      va.push_back(
          T{a[la - 1].first, a[la - 1].second, a[la].first, a[la].second});
  for (int lb = 1; lb < b.size(); ++lb)
    if (b[lb].first == b[lb - 1].first)
      vb.push_back(
          T{b[lb - 1].second, b[lb - 1].first, b[lb].second, b[lb].first});
  sa = va.size();
  sb = vb.size();
  for (int i = 0; i < va.size(); ++i)
    for (int j = 0; j < vb.size(); ++j)
      if (intersect(va[i], vb[j])) edges[i + 1].push_back(j + 1);
  findMatching();
  findDominate();
  vector<T> ans1, ans2;
  for (int i = 0; i < a.size(); ++i) {
    if (!i || a[i].first != a[i - 1].first)
      ans1.push_back(T{a[i].first, a[i].second, a[i].first, a[i].second});
    else {
      T t = T{a[i - 1].first, a[i - 1].second, a[i].first, a[i].second};
      if (badT.find(t) == badT.end())
        ans1.back().y2 = a[i].second;
      else
        ans1.push_back(T{a[i].first, a[i].second, a[i].first, a[i].second});
    }
  }
  for (int i = 0; i < b.size(); ++i) {
    if (!i || b[i].first != b[i - 1].first)
      ans2.push_back(T{b[i].first, b[i].second, b[i].first, b[i].second});
    else {
      T t = T{b[i - 1].first, b[i - 1].second, b[i].first, b[i].second};
      t.inverse();
      if (badT.find(t) == badT.end())
        ans2.back().y2 = b[i].second;
      else
        ans2.push_back(T{b[i].first, b[i].second, b[i].first, b[i].second});
    }
  }
  cout << ans2.size() << '\n';
  for (auto& t : ans2) {
    t.inverse();
    t.print();
  }
  cout << ans1.size() << '\n';
  for (auto& t : ans1) t.print();
}
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  mt19937 rnd(clock());
  solve();
  return 0;
}
