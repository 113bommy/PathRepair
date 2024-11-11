#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 61;
bool cmpA;
struct Line {
  long long a, b;
  mutable long double xl;
  bool operator<(const Line &l) const {
    if (cmpA)
      return a < l.a;
    else
      return xl < l.xl;
  }
};
struct DynamicHull : multiset<Line> {
  bool bad(iterator y) {
    iterator z = next(y), x;
    if (y == begin()) {
      if (z == end()) return 0;
      return y->a == z->a && y->b <= z->b;
    }
    x = prev(y);
    if (z == end()) {
      return y->a == x->a && y->b <= x->b;
    }
    return 1.0L * (x->b - y->b) * (z->a - y->a) >=
           1.0L * (y->b - z->b) * (y->a - x->a);
  }
  void add(long long a, long long b) {
    cmpA = 1;
    iterator y = insert((Line){a, b, -INF});
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
    if (next(y) != end())
      next(y)->xl = 1.0L * (y->b - next(y)->b) / (next(y)->a - y->a);
    if (y != begin()) y->xl = 1.0L * (y->b - prev(y)->b) / (prev(y)->a - y->a);
  }
  long long eval(long long x) {
    if (empty()) return -INF;
    cmpA = 0;
    iterator it = prev(lower_bound((Line){0, 0, 1.0L * x}));
    return it->a * x + it->b;
  }
};
const int MAXN = 200005;
long long a[MAXN], ps[MAXN], pf[MAXN], ss[MAXN], sf[MAXN];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pf[i] = pf[i - 1] + a[i] * i;
    ps[i] = ps[i - 1] + a[i];
  }
  for (int i = n; i >= 1; --i) {
    sf[i] = sf[i + 1] + a[i] * i;
    ss[i] = ss[i + 1] + a[i];
  }
  DynamicHull pdh, sdh;
  long long ans = 0;
  for (int j = 1; j <= n; ++j) {
    pdh.add(j, -ps[j - 1]);
    ans = max(ans, pf[j - 1] + ps[j - 1] + pf[n] + -pf[j] + pdh.eval(a[j]));
  }
  for (int j = n; j >= 1; --j) {
    pdh.add(j, ss[j + 1]);
    ans = max(ans, sf[j + 1] - ss[j + 1] + sf[1] + -sf[j] + pdh.eval(a[j]));
  }
  cout << ans;
}
