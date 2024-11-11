#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 10;
int T;
int n, m;
int a[maxn], b[maxn];
long long l1[maxn], r1[maxn];
inline bool in(long long l, long long r, long long x) {
  return l <= x && r >= x;
}
bool ch(long long pre, long long cur, long long o, int i) {
  pre += cur;
  long long le = l1[i + 1] + pre, ri = r1[i + 1] + pre;
  le = le * 2 - (long long)m * n;
  ri = ri * 2 - (long long)m * n;
  le = o - le, ri = o - ri;
  if (le > ri) swap(le, ri);
  return in(le, ri, 1) || in(le, ri, -1) || in(le, ri, 0);
}
long long f(long long x) { return abs(x) % 2; }
long long tr(long long tar, long long l, long long r, long long tot) {
  long long le = tot - r * 2, ri = tot - l * 2;
  if (!in(le, ri, tar)) return -1;
  if (f(tar) != f(tot)) return -1;
  return (tot - tar) / 2;
}
int main() {
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; ++i) l1[i] = r1[i] = 0;
    long long l = 0, r = 0;
    long long o = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a[i], &b[i]);
      l += max(0, m - b[i]);
      r += min(m, a[i]);
      o += a[i] - b[i];
    }
    long long L = l, R = r;
    l = l * 2 - (long long)m * n;
    r = r * 2 - (long long)m * n;
    l = -l, r = -r;
    swap(l, r);
    l += o, r += o;
    assert(l <= r);
    if (l > 0) {
      printf("%lld\n", l);
      for (int i = 0; i < n; ++i) {
        int cda = min(m, a[i]);
        printf("%d %d\n", cda, m - cda);
      }
    } else if (r < 0) {
      printf("%lld\n", -r);
      for (int i = 0; i < n; ++i) {
        int cda = max(0, m - b[i]);
        printf("%d %d\n", cda, m - cda);
      }
    } else {
      long long ans = 0;
      assert(l <= 0 && r >= 0);
      if (r & 1) ans = 1;
      printf("%lld\n", ans);
      long long tot = o + (long long)m * n;
      for (int i = 0; i < n; ++i) {
        int le = max(0, m - b[i]);
        int ri = min(m, a[i]);
        l1[i] = le, r1[i] = ri;
      }
      for (int i = n - 2; i >= 0; --i) l1[i] += l1[i + 1], r1[i] += r1[i + 1];
      long long totda = -1;
      for (int i = -1; i <= 1; ++i) totda = max(tr(i, L, R, tot), totda);
      long long pre = 0;
      for (int i = 0; i < n; ++i) {
        int cl = max(0, m - b[i]);
        int cr = min(m, a[i]);
        long long cho = -1;
        while (cr - cl > 1) {
          int mi = cl + cr >> 1;
          if (in(pre + mi + l1[i + 1], pre + mi + r1[i + 1], totda)) {
            cho = mi;
            break;
          } else if (pre + mi + r1[i + 1] < totda)
            cl = mi + 1;
          else
            cr = mi - 1;
        }
        while (pre + cl + r1[i + 1] < totda) ++cl;
        cho = cl;
        assert(cho >= 0 && cho <= m);
        printf("%d %d\n", cho, m - cho);
        pre += cho;
      }
    }
  }
}
