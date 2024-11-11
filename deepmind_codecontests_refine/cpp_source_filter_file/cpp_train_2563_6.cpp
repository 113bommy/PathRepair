#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
struct ppap {
  long long x, y, p, w;
} qq[100010];
inline bool cmp(ppap a, ppap b) { return a.p == b.p ? a.y < b.y : a.p < b.p; }
long long a[100010], s[100010], b[100010], q[100010], h[100010], now, n, k,
    ans[100010];
inline void add1(long long x) {
  if (h[x]) now += a[h[x]];
  a[s[x]]++;
}
inline void add2(long long x) {
  if (q[x]) now += a[q[x]];
  a[s[x]]++;
}
inline void jian1(long long x) {
  a[s[x]]--;
  if (h[x]) now -= a[h[x]];
}
inline void jian2(long long x) {
  a[s[x]]--;
  if (q[x]) now -= a[q[x]];
}
signed main() {
  n = read();
  k = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) {
    long long x = read();
    s[i] = s[i - 1] + ((a[i] == 1) ? x : -x);
    b[i] = s[i];
  }
  sort(b + 1, b + n + 1);
  long long cnt = unique(b + 1, b + n + 1) - b - 1;
  long long K = lower_bound(b + 1, b + cnt + 1, k) - b;
  if (b[K] != k) K = 0;
  for (long long i = 1; i <= n; i++) {
    q[i] = lower_bound(b + 1, b + cnt + 1, s[i] - k) - b;
    if (b[q[i]] != s[i] - k) q[i] = 0;
    h[i] = lower_bound(b + 1, b + cnt + 1, s[i] + k) - b;
    if (b[h[i]] != s[i] + k) h[i] = K;
  }
  for (long long i = 1; i <= n; i++)
    s[i] = lower_bound(b + 1, b + cnt + 1, s[i]) - b;
  h[0] = K;
  long long Q = read();
  long long P = sqrt(n);
  for (long long i = 1; i <= Q; i++) {
    qq[i].x = read();
    qq[i].y = read();
    qq[i].p = (qq[i].x - 1) / P + 1;
    qq[i].w = i;
  }
  sort(qq + 1, qq + Q + 1, cmp);
  memset(a, 0, sizeof a);
  long long l = 1, r = 0;
  now = 0;
  for (long long i = 1; i <= Q; i++) {
    while (l < qq[i].x) jian1(l++);
    while (l > qq[i].x) add1(--l);
    while (r < qq[i].y) add2(++r);
    while (r > qq[i].y) jian2(r--);
    if (k == 93368 && now < 0) puts("pp");
    ans[qq[i].w] = now + a[h[l - 1]];
  }
  for (long long i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
  return 0;
}
