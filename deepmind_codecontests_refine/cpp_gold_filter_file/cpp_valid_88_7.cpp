#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0;
  long long d = 1;
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') d = -1;
  a = a * 10 + c - 48;
  while (c = getchar(), c >= '0' && c <= '9') a = a * 10 + c - 48;
  a *= d;
  return a;
}
long long n, m;
struct num {
  long long val, idx, dd, d;
} a[1050000];
bool cmp(num a, num b) {
  if (a.val == b.val) {
    return a.idx < b.idx;
  }
  return a.val < b.val;
}
bool cmp1(num a, num b) { return a.idx < b.idx; }
bool cmp2(num a, num b) {
  if (a.val == b.val) {
    if ((a.dd - 1) / m == (b.dd - 1) / m) return a.idx > b.idx;
    return (a.dd - 1) / m < (b.dd - 1) / m;
  }
  return a.val < b.val;
}
long long c[505][505];
long long lowbit(long long x) { return x & (-x); }
void update(long long x, long long k, long long pos) {
  for (long long i = x; i <= m; i += lowbit(i)) c[pos][i] += k;
}
long long getsum(long long x, long long pos) {
  long long ans = 0;
  for (long long i = x; i; i -= lowbit(i)) ans += c[pos][i];
  return ans;
}
bool vis[305][305];
signed main() {
  long long t = read();
  while (t--) {
    n = read();
    m = read();
    for (long long i = 1; i <= n; i++)
      memset(vis[i], false, sizeof(bool) * (m + 1));
    for (long long i = 1; i <= n; i++)
      memset(c[i], 0, sizeof(long long) * (m + 1));
    for (long long i = 1; i <= m * n; i++) {
      a[i].idx = i;
      a[i].val = read();
    }
    sort(a + 1, a + 1 + m * n, cmp);
    long long ans = 0;
    for (long long i = 1; i <= m * n; i++) a[i].dd = i;
    sort(a + 1, a + 1 + m * n, cmp2);
    for (long long i = 1; i <= m * n; i++) a[i].d = i;
    sort(a + 1, a + 1 + m * n, cmp1);
    for (long long i = 1; i <= m * n; i++) {
      long long d = a[i].d;
      long long pos = (d - 1) / m + 1;
      long long aim = (d - 1) % m + 1;
      ans += getsum(aim, pos);
      update(aim, 1, pos);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
