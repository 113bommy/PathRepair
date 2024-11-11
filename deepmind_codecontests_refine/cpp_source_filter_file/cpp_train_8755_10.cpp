#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
struct Edge {
  long long s, t;
} edge[100005];
bool cmp(Edge a, Edge b) { return a.s < b.s; }
set<long long> s;
int main() {
  long long i, n, x, y, ans = 0, l, r;
  scanf("%lld%lld%lld", &n, &x, &y);
  for (i = 0; i < n; i++) scanf("%lld%lld", &edge[i].s, &edge[i].t);
  sort(edge, edge + n, cmp);
  ans += x + (edge[0].t - edge[0].s) * y;
  ans %= 1000000007;
  s.insert(edge[0].t);
  for (i = 1; i < n; i++) {
    auto z = s.lower_bound(edge[i].s);
    if (z == s.begin() || x < y * (edge[i].s - (*prev(z)))) {
      ans += x + y * (edge[i].t - edge[i].s);
      ans %= 1000000007;
      s.insert(edge[i].t);
    } else {
      ans += y * (edge[i].t - (*prev(z)));
      ans %= 1000000007;
      s.erase(prev(z));
      s.insert(edge[i].t);
    }
  }
  printf("%lld\n", ans);
}
