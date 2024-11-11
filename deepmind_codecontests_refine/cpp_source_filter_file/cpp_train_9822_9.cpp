#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
inline void read(long long *a, long long n) {
  for (long long i = 0; i < n; i++) a[i] = in();
}
template <class blank>
inline void out(blank x) {
  cout << x << "\n";
  exit(0);
}
const long long maxn = 1e5 + 10;
const long long maxm = 1e6 + 10;
const long long maxlg = 21;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 10;
const long long SQ = 317 + 5;
long long a[maxn], pref[maxn], n, k, stree[maxlg][maxn];
inline void build(long long p = 0, long long l = 0, long long r = n - 1,
                  long long h = 0) {
  if (l == r) {
    stree[h][l] = pref[l];
    return;
  }
  long long mid = (l + r) >> 1;
  build(2 * p + 1, l, mid, h + 1), build(2 * p + 2, mid + 1, r, h + 1);
  merge(stree[h + 1] + l, stree[h + 1] + mid + 1, stree[h + 1] + mid + 1,
        stree[h + 1] + r + 1, stree[h] + l);
}
inline long long get(long long ql, long long qr, long long lim, long long p = 0,
                     long long l = 0, long long r = n - 1, long long h = 0) {
  if (l > qr || r < ql) return 0;
  if (l >= ql && r <= qr)
    return upper_bound(stree[h] + l, stree[h] + r + 1, lim) - stree[h] - l;
  long long mid = (l + r) >> 1;
  return get(ql, qr, lim, 2 * p + 1, l, mid, h + 1) +
         get(ql, qr, lim, 2 * p + 2, mid + 1, r, h + 1);
}
inline long long can(long long x) {
  long long cnt = 0;
  for (long long start = 0; start < n; start++) {
    cnt += get(start, n - 1, (start ? pref[start - 1] : 0) + x - 1);
  }
  cnt = n * (n + 1) / 2 - cnt;
  return cnt >= k;
}
int32_t main() {
  n = in(), k = in();
  read(a, n);
  for (long long i = 0; i < n; i++) pref[i] = a[i] + (i ? pref[i - 1] : 0);
  build();
  long long l = -INF, r = INF;
  while (l + 1 < r) {
    long long mid = (l + r) >> 1;
    if (can(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << "\n";
}
