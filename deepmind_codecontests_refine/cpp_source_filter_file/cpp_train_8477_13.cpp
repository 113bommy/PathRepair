#include <bits/stdc++.h>
using namespace std;
const long long NR = 1e5 + 10;
const long long MR = 505;
void Max(long long &x, long long y) { x = max(x, y); }
void Min(long long &x, long long y) { x = min(x, y); }
long long n, m, w, mx, all, kc;
struct Fk {
  long long l, r, k;
} p[MR];
struct Nd {
  long long a, b;
  bool operator<(const Nd &A) const { return b < A.b; }
} t[NR];
long long cal(long long x, long long pos) { return x * (n - pos + 1); }
long long d[NR];
long long cnt[NR];
long long q[MR][MR];
long long L[MR], R[MR];
double slope(long long id1, long long id2) {
  return 1. * (d[id1] - d[id2]) / (id2 - id1);
}
void doit(long long id, long long x) {
  while (L[id] < R[id] && slope(q[id][L[id]], q[id][L[id] + 1]) <= x) L[id]++;
}
void rebuild(long long id) {
  L[id] = 1, R[id] = 0;
  for (long long i = p[id].l; i <= p[id].r; i++) {
    while (L[id] < R[id] &&
           slope(q[id][R[id]], i) < slope(q[id][R[id] - 1], q[id][R[id]]))
      R[id]--;
    q[id][++R[id]] = i;
  }
  doit(id, 0);
}
long long Num(long long x) { return (x - 1) / kc + 1; }
void add(long long x) {
  if (x <= 0) return;
  long long len = Num(x);
  for (long long i = 1; i < len; i++) doit(i, ++cnt[i]);
  for (long long i = p[len].l; i <= p[len].r; i++) d[i] += cnt[len] * i;
  for (long long i = p[len].l; i <= x; i++) d[i] += i;
  cnt[len] = 0;
  rebuild(len);
}
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
signed main() {
  n = read(), w = read();
  for (long long i = 1; i <= n; i++)
    t[i].a = read(), t[i].b = read(), Max(mx, t[i].a), Max(all, t[i].a);
  sort(t + 1, t + n + 1);
  kc = sqrt(all);
  long long now = 1;
  for (long long i = 1; i <= all; i += kc)
    p[++m].l = i, p[m].r = min(all, i + kc - 1), p[m].k = 0;
  for (long long c = 0; c <= mx + 1; c++) {
    while (t[now].b < c && now <= n) add(t[now].a), now++;
    long long ans = -1, pos = 0;
    for (long long i = 1; i <= m; i++) {
      long long x = q[i][L[i]];
      if (d[x] + x * cnt[i] >= ans) ans = d[x] + x * cnt[i], pos = x;
    }
    printf("%lld %lld\n", ans + w * c * (n - now + 1), pos);
  }
  return 0;
}
