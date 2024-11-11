#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1) {
  std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
const long long mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long inf = 1e18;
struct convexHullDynamic {
  bool isMax;
  struct Line {
    long long m, c;
    long double xleft;
    enum Type { line, maxQuery, minQuery } type;
    long long val;
    Line(long long _m = 0, long long _c = 0)
        : m(_m), c(_c), xleft(-inf), type(Type::line), val(0) {}
    long long valueAt(int x) { return m * x + c; }
    bool isParallel(Line l1, Line l2) { return l1.m == l2.m; }
    long double intersectX(Line l1, Line l2) {
      if (isParallel(l1, l2)) return inf;
      return (l2.c - l1.c) / ((long double)l1.m - l2.m);
    }
    bool operator<(const Line &l) const {
      if (l.type == line) return this->m < l.m;
      if (l.type == maxQuery) return this->xleft < l.val;
      return this->xleft > l.val;
    }
  };
  set<Line> Hull;
  bool hasPrev(set<Line>::iterator it) { return it != Hull.begin(); }
  bool hasNext(set<Line>::iterator it) {
    return it != Hull.end() && next(it) != Hull.end();
  }
  bool irrelevant(Line l1, Line l2, Line l3) {
    Line temp;
    return temp.intersectX(l1, l3) <= temp.intersectX(l1, l2);
  }
  bool irrelevant(set<Line>::iterator it) {
    return hasPrev(it) && hasNext(it) &&
           ((isMax && irrelevant(*prev(it), *it, *next(it))) ||
            (!isMax && irrelevant(*next(it), *it, *prev(it))));
  }
  set<Line>::iterator updateLeftBorder(set<Line>::iterator it) {
    if (isMax && !hasPrev(it) || !isMax && !hasNext(it)) return it;
    Line temp = *it;
    long double val = temp.intersectX(*it, isMax ? *prev(it) : *next(it));
    it = Hull.erase(it);
    temp.xleft = val;
    return Hull.insert(it, temp);
  }
  convexHullDynamic(bool _isMax = true) : isMax(_isMax) {}
  void addLine(long long m, long long c) {
    Line l3 = Line(m, c);
    auto it = Hull.lower_bound(l3);
    if (it != Hull.end() && l3.isParallel(*it, l3)) {
      if (isMax && it->c < c || !isMax && it->c > c)
        it = Hull.erase(it);
      else
        return;
    }
    it = Hull.insert(it, l3);
    if (irrelevant(it)) {
      Hull.erase(it);
      return;
    }
    while (hasPrev(it) && irrelevant(prev(it))) Hull.erase(prev(it));
    while (hasNext(it) && irrelevant(next(it))) Hull.erase(next(it));
    it = updateLeftBorder(it);
    if (hasPrev(it)) updateLeftBorder(prev(it));
    if (hasNext(it)) updateLeftBorder(next(it));
  }
  long long getBest(long long x) {
    Line q;
    q.val = x;
    q.type = isMax ? Line::Type::maxQuery : Line::Type::minQuery;
    auto bestline = Hull.lower_bound(q);
    if (isMax) --bestline;
    q = *bestline;
    return q.valueAt(x);
  }
  void print() {
    for (auto it : Hull)
      ZZ("it.m, it.c, it.val, it.xleft, it.type", it.m, it.c, it.val, it.xleft,
         it.type);
    ;
  }
};
const int N = 1e5 + 10;
int n;
long long a[N], b[N], dp[N];
convexHullDynamic hull(0);
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  dp[0] = 0;
  hull.addLine(b[0], dp[0]);
  for (int i = 1; i < n; ++i) {
    dp[i] = hull.getBest(a[i]);
    hull.addLine(b[i], dp[i]);
  }
  cout << dp[n - 1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
