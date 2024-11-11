#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class T> struct ConvexHullTrick {
  struct Line { T a, b; };
  deque<Line> deq;
  bool monotone_query;
  bool need(const Line& l, const Line& m, const Line& r) const {
    return m.b * (r.a - l.a) > l.b * (r.a - m.a) + r.b * (m.a - l.a);
  }
  ConvexHullTrick(bool monotone_query = false) : monotone_query(monotone_query) {}
  void add(T a, T b) {
    if (deq.empty() or a < deq[0].a) {
      while (deq.size() >= 2 and !need({a, b}, deq[0], deq[1])) {
        deq.pop_front();
      }
      deq.emplace_front(Line{a, b});
    } else if (a > deq.back().a) {
      while (deq.size() >= 2 and !need(deq[deq.size() - 2], deq.back(), {a, b})) {
        deq.pop_back();
      }
      deq.emplace_back(Line{a, b});
    } else assert(false);
  }
  T max(T x) {
    if (deq.empty()) return numeric_limits<T>::min(); // オーバーフローに注意
    if (monotone_query) {
      while (deq.size() >= 2 and deq[0].a * x + deq[0].b <= deq[1].a * x + deq[1].b) {
        deq.pop_front();
      }
      return deq[0].a * x + deq[0].b;
    }
    int ok = 0, ng = deq.size();
    while (ng - ok > 1) {
      int m = ok + ng >> 1;
      (deq[m - 1].a * x + deq[m - 1].b <= deq[m].a * x + deq[m].b ? ok : ng) = m;
    }
    return deq[ok].a * x + deq[ok].b;
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  lint n, a; cin >> n >> a;
  if (a < 2e6) {
    V<lint> dp;
    ConvexHullTrick<__int128> cht(true);
    for (int x = 0; ; ++x) {
      dp.push_back(x);
      if (a + 2 < x) {
        cht.add(dp[x - 1 - a], (1 - x) * dp[x - 1 - a]);
        dp[x] = max<lint>(dp[x], cht.max(x));
      }
      if (dp[x] >= n) {
        cout << x << '\n';
        return 0;
      }
    }
  }
  lint res = n;
  for (lint x = sqrt(n) - 2; x <= sqrt(n) + 2; ++x) {
    if (x < 2 or x >= n) continue;
    res = min(res, x + a + (n + x - 1) / x);
  }
  cout << res << '\n';
}