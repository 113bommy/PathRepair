#include <bits/stdc++.h>
using namespace std;
template <class T>
void cmax(T &a, T b) {
  a = (a > b ? a : b);
}
template <class T>
void cmin(T &a, T b) {
  a = (a > b ? b : a);
}
const long long maxn = 271000;
long long tag[maxn << 1], tr[maxn << 1], n, m, p;
struct item {
  long long a, p;
  bool operator<(item b) const { return a < b.a || a == b.a && p < b.p; }
  bool operator==(item b) const { return a == b.a; }
  item() { a = p = 0; }
  item(long long A, long long B) {
    a = A;
    p = B;
  }
} a[maxn], b[maxn];
struct mon {
  long long a, b, p;
  bool operator<(mon p) const { return a < p.a || a == p.a && b < p.b; }
} c[maxn];
void pd(long long now) {
  tr[now << 1] += tag[now];
  tr[now << 1 | 1] += tag[now];
  tag[now << 1] += tag[now];
  tag[now << 1 | 1] += tag[now];
  tag[now] = 0;
}
void add(long long l, long long r, long long now, long long x, long long y,
         long long v) {
  if (x > y) return;
  if (x <= l && r <= y) {
    tr[now] += v;
    tag[now] += v;
    return;
  }
  if (tag[now]) pd(now);
  if (((l + r) >> 1) >= x) add(l, ((l + r) >> 1), now << 1, x, y, v);
  if (((l + r) >> 1) < y) add(((l + r) >> 1) + 1, r, now << 1 | 1, x, y, v);
  tr[now] = (tr[now << 1] > tr[now << 1 | 1] ? tr[now << 1] : tr[now << 1 | 1]);
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &p);
  for (long long i = (1); i <= (n); ++i) scanf("%lld%lld", &a[i].a, &a[i].p);
  for (long long i = (1); i <= (m); ++i) scanf("%lld%lld", &b[i].a, &b[i].p);
  for (long long i = (1); i <= (p); ++i)
    scanf("%lld%lld%lld", &c[i].a, &c[i].b, &c[i].p);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  sort(c + 1, c + p + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  m = unique(b + 1, b + m + 1) - b - 1;
  for (long long i = (1); i <= (m); ++i) add(1, m, 1, i, i, -b[i].p);
  long long ans = LLONG_MIN >> 1;
  long long j = 0;
  for (long long i = (1); i <= (n); ++i) {
    while (j < m && c[j + 1].a < a[i].a) {
      long long temp =
          upper_bound(b + 1, b + m + 1, item(c[j + 1].b, LLONG_MAX >> 1)) - b;
      add(1, m, 1,
          upper_bound(b + 1, b + m + 1, item(c[j + 1].b, LLONG_MAX >> 1)) - b,
          m, c[j + 1].p);
      ++j;
    }
    cmax(ans, tr[1] - a[i].p);
  }
  printf("%lld", ans);
  return 0;
}
