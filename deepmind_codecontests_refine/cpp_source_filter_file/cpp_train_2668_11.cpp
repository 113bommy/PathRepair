#include <bits/stdc++.h>
using namespace std;
int main() {
  long long f, t, t0, a1, t1, p1, a2, t2, p2, i, j;
  long long tt, ff, minn = 1e7;
  scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &f, &t, &t0, &a1, &t1, &p1, &a2,
        &t2, &p2);
  if (t1 > t2) swap(t1, t2), swap(a1, a2), swap(p1, p2);
  for (i = 0; a1 * i < f; i++) {
    ff = f - i * a1;
    tt = t - i * a1 * t1;
    if (ff * t2 > tt && ff * t0 > tt) continue;
    if (t0 <= t2 || ff * t0 <= tt)
      j = 0;
    else
      j = ((t0 * ff - tt + t0 - t2 - 1) / (t0 - t2) + a2 - 1) / a2;
    if (p1 * i + p2 * j < minn) minn = p1 * i + p2 * j;
  }
  if (f * t1 <= t && (f + a1 - 1) / a1 * p1 < minn)
    minn = (f + a1 - 1) / a1 * p1;
  if (minn == 1e18)
    printf("%d\n", -1);
  else
    printf("%lld\n", minn);
  return 0;
}
