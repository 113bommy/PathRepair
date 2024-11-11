#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline bool chmax(A &a, B b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename A, typename B>
inline bool chmin(A &a, B b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const long long INF = 1ll << 60;
const long long MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
template <typename T>
struct ConvexHullTrick {
  deque<pair<T, T> > deq;
  T func(pair<T, T> f, T x) { return f.first * x + f.second; }
  bool check(pair<T, T> f1, pair<T, T> f2, pair<T, T> f3) {
    return (f2.first - f1.first) * (f3.second - f2.second) >=
           (f2.second - f1.second) * (f3.first - f2.first);
  }
  void add(T a, T b) {
    pair<T, T> now = make_pair(a, b);
    while (deq.size() >= 2 && check(*-- --deq.end(), *--deq.end(), now))
      deq.pop_back();
    deq.push_back(now);
  }
  T query(T x) {
    int l = -1, r = deq.size() - 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (func(deq[m], x) <= func(deq[m + 1], x))
        l = m;
      else
        r = m;
    }
    return func(deq[r], x);
  }
};
int n;
long long a[212345], sum[212345];
int main() {
  cin >> n;
  for (int i = (0); i < (n); i++) scanf("%I64d", a + i + 1);
  for (int i = (0); i < (n); i++) sum[i + 1] = sum[i] + a[i + 1];
  long long ans = 0;
  ConvexHullTrick<long long> cht1;
  for (int i = n - 1; i >= 1; i--) {
    int j = i + 1;
    cht1.add(-j, -sum[j]);
    chmax(ans, sum[i] - a[i] * i + cht1.query(-a[i]));
  }
  ConvexHullTrick<long long> cht2;
  for (int i = 2; i <= n; i++) {
    int j = i - 1;
    cht2.add(j, -sum[j - 1]);
    chmax(ans, sum[i - 1] - a[i] * i + cht2.query(a[i]));
  }
  for (int i = (1); i < (n + 1); i++) ans += a[i] * i;
  cout << ans << endl;
  return 0;
}
