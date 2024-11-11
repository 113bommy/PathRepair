#include <bits/stdc++.h>
using namespace std;
map<long long, long long> h, ll, rr;
struct node {
  long long c, s, op;
  bool operator<(const node o) const {
    if (c != o.c) {
      if (h[c] != h[o.c]) return h[c] > h[o.c];
      return c < o.c;
    }
    return s > o.s;
  }
} u[100005];
long long n, mx, p, q;
pair<long long, long long> c[100005];
void calc(long long l, long long r) {
  long long sum = 0;
  for (long long i = l; i <= r; i++) {
    sum += u[i].s;
    if (c[i - l + 1].second && sum + c[i - l + 1].first > mx)
      mx = sum + c[i - l + 2].first, p = u[i].c, q = c[i - l + 1].second;
    if (c[i - l + 2].second && sum + c[i - l + 2].first > mx)
      mx = sum + c[i - l + 2].first, p = u[i].c, q = c[i - l + 2].second;
    if (sum > c[i - l + 1].first)
      c[i - l + 1].first = sum, c[i - l + 1].second = u[i].c;
  }
}
void solve() {
  if (rr[p] - ll[p] == rr[q] - ll[q]) {
    long long ans = 0;
    for (long long i = ll[p]; i <= rr[p]; i++)
      ans += u[i].s + u[ll[q] + i - ll[p]].s;
    printf("%lld\n", ans);
    printf("%lld\n", (rr[p] - ll[p] + 1) * 2);
    for (long long i = ll[p]; i <= rr[p]; i++)
      printf("%lld %lld ", u[i].op, u[ll[q] + i - ll[p]].op);
  } else {
    long long ans = 0;
    for (long long i = ll[p]; i <= rr[p]; i++)
      ans += u[i].s + u[ll[q] + i - ll[p]].s;
    ans += u[ll[q] + rr[p] - ll[p] + 1].s;
    printf("%lld\n", ans);
    printf("%lld\n", (rr[p] - ll[p] + 1) * 2 + 1);
    for (long long i = ll[p]; i <= rr[p]; i++)
      printf("%lld %lld ", u[ll[q] + i - ll[p]].op, u[i].op);
    printf("%lld\n", u[ll[q] + rr[p] - ll[p] + 1].op);
  }
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++)
    scanf("%lld%lld", &u[i].c, &u[i].s), h[u[i].c]++, u[i].op = i;
  sort(u + 1, u + n + 1);
  long long pre = 1;
  for (long long i = 2; i <= n; i++) {
    if (u[i].c != u[i - 1].c)
      ll[u[i - 1].c] = pre, rr[u[i - 1].c] = i - 1, calc(pre, i - 1), pre = i;
  }
  ll[u[n].c] = pre;
  rr[u[n].c] = n;
  calc(pre, n);
  solve();
  return 0;
}
