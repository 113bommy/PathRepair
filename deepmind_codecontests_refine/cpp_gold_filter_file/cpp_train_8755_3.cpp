#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, M = 1e9 + 7;
long long n, x, y, ans;
multiset<long long> s;
multiset<long long>::iterator it;
struct node {
  long long x, y;
} a[N];
long long cmp(node x, node y) { return x.y > y.y; }
signed main() {
  scanf("%lld%lld%lld", &n, &x, &y);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i].x, &a[i].y);
    (ans += x + y * (a[i].y - a[i].x) % M) %= M;
    s.insert(a[i].x);
  }
  sort(a + 1, a + 1 + n, cmp);
  for (long long i = 1; i <= n; i++) {
    long long t = a[i].y;
    it = s.upper_bound(t);
    if (it != s.end() && y * (*it - t) < x) {
      (ans += y * (*it - t) % M + M - x) %= M;
      s.erase(it);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
