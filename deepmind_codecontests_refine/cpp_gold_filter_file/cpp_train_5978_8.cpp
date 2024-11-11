#include <bits/stdc++.h>
using namespace std;
inline int in() {
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
const int MAX_LG = 21;
const long long maxn = 3e5 + 10;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long INF = 1e9 + 100;
const long long SQ = 317;
pair<long long, long long> P[maxn];
long long n, q;
long long stree[MAX_LG][4 * maxn];
inline void build(long long p = 0, long long l = 0, long long r = n - 1,
                  long long dep = 0) {
  if (l == r) {
    stree[dep][l] = P[l].second;
    return;
  }
  long long mid = (l + r) >> 1;
  build(2 * p + 1, l, mid, dep + 1);
  build(2 * p + 2, mid + 1, r, dep + 1);
  merge(stree[dep + 1] + l, stree[dep + 1] + mid + 1, stree[dep + 1] + mid + 1,
        stree[dep + 1] + r + 1, stree[dep] + l);
}
inline long long get(long long ql, long long qr, long long lim, long long p = 0,
                     long long l = 0, long long r = n - 1, long long dep = 0) {
  if (l > qr || r < ql) return 0;
  if (l >= ql && r <= qr) {
    long long ps =
        lower_bound(stree[dep] + l, stree[dep] + r + 1, lim) - stree[dep];
    return max(0ll, r - ps + 1);
    return 0;
  }
  long long mid = (l + r) >> 1;
  return get(ql, qr, lim, 2 * p + 1, l, mid, dep + 1) +
         get(ql, qr, lim, 2 * p + 2, mid + 1, r, dep + 1);
}
long long a[maxn], pos[maxn];
int32_t main() {
  n = in(), q = in();
  for (long long i = 0; i < n; i++) P[i] = {in(), in()};
  sort(P, P + n);
  build();
  while (q--) {
    long long cnt = in();
    long long ret = 0;
    for (long long j = 0; j < cnt; j++) {
      a[j] = in();
      pos[j] = upper_bound(P, P + n, make_pair(a[j], INF)) - P - 1;
      ret += get(0, pos[j], a[j]);
      if (j) ret -= get(0, pos[j - 1], a[j]);
    }
    cout << ret << "\n";
  }
}
