#include <bits/stdc++.h>
using namespace std;
const int N = 301010;
const int K = (int)log2(N) + 2;
const int SQRTN = (int)sqrt(N) + 7;
const long long infi = 1ll << 63;
long long n, t[N], a[N], b[N], sz, ans[N], mn, mx;
set<long long> remprev, rem;
const long long is_query = -(1LL << 62);
struct Line {
  long long m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    long long x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
struct HullDynamic : public multiset<Line> {
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (x->b - y->b) * (long double)(z->m - y->m) >=
           (y->b - z->b) * (long double)(y->m - x->m);
  }
  void insert_line(long long m, long long b) {
    auto y = insert({m, b});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  long long eval(long long x) {
    auto l = *lower_bound((Line){x, is_query});
    return l.m * x + l.b;
  }
} hull;
int main() {
  scanf("%lld", &n);
  ;
  for (int(i) = (1); (i) <= (int)(n); ++(i)) {
    scanf("%lld", &t[i]);
    ;
    scanf("%lld", &a[i]);
    ;
    if (t[i] == 1) scanf("%lld", &b[i]);
    ;
  }
  sz = sqrt(n);
  fill(ans, ans + n + 1, -infi);
  for (int i = 1; i <= n; i += sz) {
    remprev.clear();
    for (int(j) = (i); (j) <= (int)(min(n, i + sz - 1)); ++(j)) {
      if (t[j] == 2 && a[j] < i) remprev.insert(a[j]);
      if (t[j] == 3 && (long long)hull.size()) ans[i] = hull.eval(a[j]);
    }
    for (int(j) = (i); (j) <= (int)(min(n, i + sz - 1)); ++(j)) {
      if (t[j] == 1) remprev.insert(j);
      if (t[j] == 2) remprev.erase(a[j]);
      if (t[j] == 3) {
        for (auto& cur : remprev) ans[j] = max(ans[j], a[cur] * a[j] + b[cur]);
      }
    }
    mx = min(n, i + 2 * sz - 1);
    for (int(j) = (mn + 1); (j) <= (int)(mx); ++(j))
      if (t[j] == 2) rem.insert(a[j]);
    mn = mx;
    hull.clear();
    for (int(j) = (0); (j) <= (int)(min(n, i + sz - 1)); ++(j)) {
      if (t[j] == 1 && !rem.count(j)) hull.insert_line(a[j], b[j]);
    }
  }
  for (int(i) = (1); (i) <= (int)(n); ++(i)) {
    if (t[i] != 3) continue;
    if (ans[i] == -infi)
      printf("EMPTY SET\n");
    else
      printf("%lld\n", ans[i]);
  }
  fflush(stdout);
  return 0;
}
