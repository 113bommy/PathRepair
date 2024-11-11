#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const long long N = 1000010;
long long n, m, a[N], p[N], k, cnt[N], ans[N], sum, l = 1, r;
struct node {
  long long l, r, idx;
  bool operator<(const node& rhs) const {
    if (p[l] == p[rhs.l]) return r < rhs.r;
    return l < rhs.l;
  }
} q[N];
inline void Insert(long long x) {
  sum -= cnt[a[x]] * cnt[a[x]] * a[x];
  ++cnt[a[x]];
  sum += cnt[a[x]] * cnt[a[x]] * a[x];
}
inline void Delete(long long x) {
  sum -= cnt[a[x]] * cnt[a[x]] * a[x];
  --cnt[a[x]];
  sum += cnt[a[x]] * cnt[a[x]] * a[x];
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  k = sqrt(n);
  for (long long i = 1; i <= n; ++i) p[i] = (i - 1) / k + 1;
  for (long long i = 1; i <= m; ++i)
    q[i].l = read(), q[i].r = read(), q[i].idx = i;
  sort(q + 1, q + m + 1);
  for (long long i = 1; i <= m; ++i) {
    long long L = q[i].l, R = q[i].r;
    while (l < L) Delete(l++);
    while (l > L) Insert(--l);
    while (r < R) Insert(++r);
    while (r > R) Delete(r--);
    ans[q[i].idx] = sum;
  }
  for (long long i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
  return 0;
}
