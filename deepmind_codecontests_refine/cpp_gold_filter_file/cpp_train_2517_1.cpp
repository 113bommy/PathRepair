#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4e5 + 5;
inline long long read() {
  char c = getchar();
  long long t = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    t = (t << 3) + (t << 1) + (c ^ 48);
    c = getchar();
  }
  return t * f;
}
long long m, n;
pair<long long, long long> a[maxn], b[maxn];
long long t1[maxn], t2[maxn], tt1[maxn], tt2[maxn], c[maxn], ans[maxn];
void update(long long l, long long r, long long d) {
  c[l] += d;
  c[r + 1] -= d;
}
void modify(long long l, long long r, long long d) {
  if (l > r) return;
  l = ((l + n) % n + n) % n, r = ((r + n) % n + n) % n;
  if (l > r) {
    update(l, n - 1, d);
    update(0, r, d);
  } else
    update(l, r, d);
}
signed main() {
  m = read(), n = read();
  for (long long i = 1; i <= n; i++) a[i].first = read(), a[i].second = i;
  ;
  for (long long i = 1; i <= n; i++) b[i].first = read(), b[i].second = i;
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  for (long long i = 1; i <= n; i++) {
    t1[i] = a[i].first;
    tt1[i] = t1[i] << 1;
    t2[i] = b[i].first;
    tt2[i] = t2[i] << 1;
  }
  for (long long i = 1; i <= n; i++) {
    long long l = 1,
              r = upper_bound(tt2 + 1, tt2 + 1 + n, tt1[i] - m - 1) - tt2 - 1;
    modify(l - i, r - i, -t1[i]);
    l = r + 1, r = upper_bound(tt2 + 1, tt2 + 1 + n, tt1[i] - 1) - tt2 - 1;
    modify(l - i, r - i, t1[i]);
    l = r + 1, r = upper_bound(tt2 + 1, tt2 + 1 + n, tt1[i] + m) - tt2 - 1;
    modify(l - i, r - i, -t1[i]);
    l = r + 1, r = n;
    modify(l - i, r - i, t1[i] + m);
  }
  for (long long i = 1; i <= n; i++) {
    long long l = 1,
              r = upper_bound(tt1 + 1, tt1 + 1 + n, tt2[i] - m - 1) - tt1 - 1;
    modify(i - r, i - l, -t2[i]);
    l = r + 1, r = upper_bound(tt1 + 1, tt1 + 1 + n, tt2[i]) - tt1 - 1;
    modify(i - r, i - l, t2[i]);
    l = r + 1, r = upper_bound(tt1 + 1, tt1 + 1 + n, tt2[i] + m) - tt1 - 1;
    modify(i - r, i - l, -t2[i]);
    l = r + 1, r = n;
    modify(i - r, i - l, t2[i] + m);
  }
  long long pos = 0;
  for (long long i = 1; i < n; i++)
    c[i] += c[i - 1], pos = (c[i] < c[pos]) ? i : pos;
  printf("%lld\n", c[pos]);
  for (long long i = 1, j = pos + 1; i <= n; i++, j = (j == n) ? 1 : j + 1)
    ans[a[i].second] = b[j].second;
  for (long long i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
