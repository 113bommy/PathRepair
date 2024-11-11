#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int f, T, t0;
int a1, t1, p1;
int a2, t2, p2;
long long ans = INF;
bool pl;
bool good(long long sz, long long t, long long mnt) {
  sz -= mnt * a2;
  t -= mnt * a2 * t2;
  if (t < 0) return false;
  if (sz * t0 <= t) return true;
  long long d = min(sz, 1ll * a1);
  if (p1 < p2 && d * t1 + (sz - d) * t0 <= t) {
    pl = true;
    return true;
  }
  return false;
}
long long solve(long long sz, long long t) {
  if (t < 0) return INF;
  if (sz <= 0) return 0;
  if (t2 >= t0) return sz * t0 <= T ? 0 : INF;
  long long lo = 0, hi = t / (a2 * t2);
  pl = false;
  while (lo < hi) {
    long long med = (lo + hi) / 2;
    if (good(sz, t, med))
      hi = med;
    else
      lo = med + 1;
  }
  long long ret = good(sz, t, lo) ? lo * p2 + (pl ? p1 : 0) : INF;
  if ((sz - (sz / a2) * a2) * t2 <= t - (sz / a2) * a2 * t2)
    ret = min(ret, ((sz + a2 - 1) / a2) * p2);
  return ret;
}
int main() {
  scanf("%d", &f), scanf("%d", &T), scanf("%d", &t0);
  scanf("%d", &a1), scanf("%d", &t1), scanf("%d", &p1);
  scanf("%d", &a2), scanf("%d", &t2), scanf("%d", &p2);
  long long a = 0;
  while (a * a1 * t1 <= T) {
    ans = min(ans, solve(f - a * a1, T - a * a1 * t1) + a * p1);
    a++;
  }
  a--;
  if ((f - a * a1) * t1 <= T - a * a1 * t1) ans = min(ans, (a + 1) * p1);
  printf("%lld\n", ans == INF ? -1 : ans);
}
