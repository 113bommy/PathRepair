#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
int l, r, a[maxn], x[maxn], n;
long long sum[maxn << 2], la[maxn << 2];
void pushup(long long rt) { sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; }
void build(long long l, long long r, long long rt) {
  la[rt] = 0;
  if (l == r) {
    sum[rt] = 0;
    return;
  }
  long long m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  pushup(rt);
}
void pushdowm(long long rt, long long l, long long r) {
  long long m = (l + r) >> 1;
  if (la[rt] != 0) {
    sum[rt << 1] += (m - l + 1) * la[rt];
    sum[rt << 1 | 1] += (r - m) * la[rt];
    la[rt << 1] += la[rt];
    la[rt << 1 | 1] += la[rt];
    la[rt] = 0;
  }
}
void update2(long long L, long long R, long long c, long long l, long long r,
             long long rt) {
  if (L <= l && R >= r) {
    sum[rt] += c * (r - l + 1);
    la[rt] += c;
    return;
  }
  pushdowm(rt, l, r);
  long long m = (l + r) >> 1;
  if (L <= m) update2(L, R, c, l, m, rt << 1);
  if (R > m) update2(L, R, c, m + 1, r, rt << 1 | 1);
  pushup(rt);
}
long long query(long long L, long long R, long long l, long long r,
                long long rt) {
  long long s = 0;
  if (L <= l && R >= r) return sum[rt];
  pushdowm(rt, l, r);
  long long m = (l + r) >> 1;
  if (L <= m) s += query(L, R, l, m, rt << 1);
  if (R > m) s += query(L, R, m + 1, r, rt << 1 | 1);
  return s;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= 2 * k; i++) x[i] = 0;
    build(1, 2 * k, 1);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n / 2; i++) {
      l = min(a[i], a[n - 1 - i]) + 1;
      r = max(a[i], a[n - 1 - i]) + k;
      x[a[i] + a[n - 1 - i]]++;
      update2(l, r, 1, 1, 2 * k, 1);
    }
    int ans = 100000000;
    for (int i = 1; i <= 2 * k; i++) {
      int t1 = query(i, i, 1, 2 * k, 1);
      int t2 = x[i];
      ans = min(ans, t1 + 2 * (n / 2 - t1) - t2);
    }
    printf("%d\n", ans);
  }
}
