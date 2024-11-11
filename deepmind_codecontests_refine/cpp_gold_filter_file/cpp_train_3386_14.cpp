#include <bits/stdc++.h>
using namespace std;
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
    return (x->b - y->b) * (z->m - y->m) >= (y->b - z->b) * (y->m - x->m);
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
} convex;
const int N = 2e5 + 5;
long long dp[N], arr[N];
int n;
int main() {
  long long sum = 0, ans;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i]);
    dp[i] = dp[i - 1] + arr[i];
    sum += arr[i] * i;
  }
  ans = sum;
  convex.insert_line(n, -dp[n]);
  for (int i = n - 1; i >= 1; i--) {
    long long best = 0;
    long long e = dp[i] - i * arr[i] + sum;
    ans = max(ans, convex.eval(arr[i]) + e);
    convex.insert_line(i, -dp[i]);
  }
  convex.clear();
  convex.insert_line(1, 0);
  for (int i = 2; i <= n; i++) {
    long long e = sum + dp[i - 1] - i * arr[i];
    ans = max(ans, convex.eval(arr[i]) + e);
    convex.insert_line(i, -dp[i - 1]);
  }
  printf("%lld\n", ans);
  return 0;
}
