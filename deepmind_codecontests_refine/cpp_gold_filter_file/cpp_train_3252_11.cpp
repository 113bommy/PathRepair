#include <bits/stdc++.h>
using namespace std;
inline void find1(long long x) {
  long long l = 4, r = 15;
  while (r < x) l = r + 1, r = (l << 2LL) - 1;
  printf("%lld\n", (x - l) / 3LL + l);
}
inline long long get2(long long l, long long r, long long pos, long long ansl,
                      long long ansr) {
  if (ansl == ansr) return ansl;
  long long tmp = (r - l + 1) >> 2LL, nl = l, nr = l + tmp - 1;
  if (nl <= pos && pos <= nr) return get2(nl, nr, pos, ansl, ansl + tmp - 1);
  nl = l + tmp, nr = l + tmp * 2LL - 1;
  if (nl <= pos && pos <= nr)
    return get2(nl, nr, pos, ansl + tmp * 2LL, ansl + tmp * 3LL - 1);
  nl = l + tmp * 2LL, nr = l + tmp * 3LL - 1;
  if (nl <= pos && pos <= nr)
    return get2(nl, nr, pos, ansl + tmp * 3LL, ansl + tmp * 4LL - 1);
  nl = l + tmp * 3LL, nr = l + tmp * 4LL - 1;
  if (nl <= pos && pos <= nr)
    return get2(nl, nr, pos, ansl + tmp, ansl + tmp * 2LL - 1);
  return -1;
}
inline void find2(long long x) {
  long long l = 4, r = 15;
  while (r < x) l = r + 1, r = (l << 2LL) - 1;
  long long nl = l * 2LL, nr = l * 3LL - 1, pos = (x - l) / 3LL + l * 2LL;
  printf("%lld\n", get2(nl, nr, pos, nl, nr));
}
inline long long get3(long long l, long long r, long long pos, long long ansl,
                      long long ansr) {
  if (ansl == ansr) return ansl;
  long long tmp = (r - l + 1) >> 2LL, nl = l, nr = l + tmp - 1;
  if (nl <= pos && pos <= nr) return get3(nl, nr, pos, ansl, ansl + tmp - 1);
  nl = l + tmp, nr = l + tmp * 2LL - 1;
  if (nl <= pos && pos <= nr)
    return get3(nl, nr, pos, ansl + tmp * 3LL, ansl + tmp * 4LL - 1);
  nl = l + tmp * 2LL, nr = l + tmp * 3LL - 1;
  if (nl <= pos && pos <= nr)
    return get3(nl, nr, pos, ansl + tmp, ansl + tmp * 2LL - 1);
  nl = l + tmp * 3LL, nr = l + tmp * 4LL - 1;
  if (nl <= pos && pos <= nr)
    return get3(nl, nr, pos, ansl + tmp * 2LL, ansl + tmp * 3LL - 1);
  return -1;
}
inline void find3(long long x) {
  long long l = 4, r = 15;
  while (r < x) l = r + 1, r = (l << 2LL) - 1;
  long long nl = l * 3LL, nr = l * 4LL - 1, pos = (x - l) / 3LL + l * 3LL;
  printf("%lld\n", get3(nl, nr, pos, nl, nr));
}
inline void solve() {
  long long x;
  scanf("%lld", &x);
  if (x <= 3) {
    printf("%lld\n", x);
    return;
  }
  if (x % 3 == 1) {
    find1(x);
    return;
  }
  if (x % 3 == 2) {
    find2(x);
    return;
  }
  if (x % 3 == 0) {
    find3(x);
    return;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
