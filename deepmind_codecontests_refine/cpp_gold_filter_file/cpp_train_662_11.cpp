#include <bits/stdc++.h>
using namespace std;
template <typename T, bool MIN>
struct ConvexHullTrickAddMonotone {
  using Line = pair<T, T>;
  deque<Line> deq;
  inline bool check(const Line &a, const Line &b, const Line &c) {
    return (b.first - a.first) * (c.second - b.second) >=
           (b.second - a.second) * (c.first - b.first);
  }
  inline T f(const Line &a, const T x) { return a.first * x + a.second; }
  void add_line(T a, T b) {
    if (!MIN) a = -a, b = -b;
    Line line(a, b);
    if (deq.empty()) return (void)deq.emplace_back(line);
    if (deq.front().first <= a) {
      if (deq.front().first == a) {
        if (deq.front().second <= b) return;
        deq.pop_front();
      }
      while (deq.size() >= 2 && check(line, deq.front(), deq[1]))
        deq.pop_front();
      deq.emplace_front(line);
    } else {
      if (deq.back().first == a) {
        if (deq.back().second <= b) return;
        deq.pop_back();
      }
      while (deq.size() >= 2 && check(deq[deq.size() - 2], deq.back(), line))
        deq.pop_back();
      deq.emplace_back(line);
    }
  }
  T query_monotone_inc(T x) {
    while (deq.size() >= 2 && f(deq.front(), x) >= f(deq[1], x))
      deq.pop_front();
    T res = f(deq.front(), x);
    return MIN ? res : -res;
  }
  T query_monotone_dec(T x) {
    while (deq.size() >= 2 && f(deq.back(), x) >= f(deq[deq.size() - 2], x))
      deq.pop_back();
    T res = f(deq.back(), x);
    return MIN ? res : -res;
  }
};
const long long INF = 1LL << 60;
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (auto &vi : vec) os << vi << " ";
  return os;
}
int main() {
  int n, m;
  cin >> n >> m;
  int p;
  cin >> p;
  vector<int> d(n);
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    d[i + 1] = d[i] + x;
  }
  vector<long long> x(m + 1);
  for (int i = 0; i < m; i++) {
    int h, t;
    cin >> h >> t;
    h--;
    x[i + 1] = t - d[h] + 1e9;
  }
  sort(begin(x), end(x));
  vector<vector<long long>> dp(p + 1, vector<long long>(m + 1, INF));
  for (int i = 0; i <= p; i++) dp[i][0] = 0;
  for (int i = 0; i < p; i++) {
    ConvexHullTrickAddMonotone<long long, true> cht;
    for (int j = 1; j <= m; j++) {
      cht.add_line(-(j - 1), dp[i][j - 1]);
      dp[i + 1][j] = cht.query_monotone_inc(x[j]) + x[j] * j;
    }
  }
  long long ans = dp[p][m];
  for (int i = 0; i <= m; i++) ans -= x[i];
  cout << ans << endl;
  return 0;
}
