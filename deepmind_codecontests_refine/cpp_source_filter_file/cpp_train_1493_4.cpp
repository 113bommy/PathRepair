#include <bits/stdc++.h>
using namespace std;
const long long int INF = (long long int)1e9 + 10;
const long long int INFLL = (long long int)1e18 + 10;
const long double EPS = 1e-8;
const long long int MOD = 1e9 + 7;
template <class T>
T &chmin(T &a, const T &b) {
  return a = min(a, b);
}
template <class T>
T &chmax(T &a, const T &b) {
  return a = max(a, b);
}
template <class T>
inline T sq(T a) {
  return a * a;
}
int ans = 0;
pair<pair<int, int>, pair<int, int> > cut(pair<int, int> a, int sz) {
  int c = (1LL << (sz)) - 1;
  return make_pair(
      pair<int, int>(min(c, a.first), min(c, a.second)),
      pair<int, int>(max(0, a.first - c - 1), max(0, a.second - c - 1)));
}
void rec(pair<int, int> a, pair<int, int> b, int sz) {
  chmax(ans, min(a.second, b.second) - max(a.first, b.first));
  if (a.second - a.first == 0 or b.second - b.first == 0) return;
  if (a.second - a.first == (1LL << (sz)) - 1 or
      b.second - b.first == (1LL << (sz)) - 1)
    return;
  if (a.second > (1LL << (sz - 1))) {
    auto res = cut(a, sz - 1);
    rec(res.first, b, sz);
    rec(res.second, b, sz);
  } else if (b.second > (1LL << (sz - 1))) {
    auto res = cut(b, sz - 1);
    rec(a, res.first, sz);
    rec(a, res.second, sz);
  } else {
    rec(a, b, sz - 1);
  }
}
int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  a--;
  c--;
  rec(pair<int, int>(a, b), pair<int, int>(c, d), 30);
  printf("%d\n", ans);
  return 0;
}
