#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
long long f, T, t0;
long long a1, t1, p1;
long long a2, t2, p2;
int main() {
  scanf("%lld %lld %lld", &f, &T, &t0);
  scanf("%lld %lld %lld", &a1, &t1, &p1);
  scanf("%lld %lld %lld", &a2, &t2, &p2);
  if (t2 < t1) {
    swap(a1, t1);
    swap(a2, t2);
    swap(p1, p2);
  }
  long long ans = 1LL << 60;
  for (int sajdasjdhjasd = int(0); sajdasjdhjasd < int((int)1e7 + 1);
       ++sajdasjdhjasd) {
    long long bytes = min(f, a1 * sajdasjdhjasd);
    if (sajdasjdhjasd > 0 && (bytes > T || bytes * t1 > T)) {
      break;
    }
    long long cur_T = T - bytes * t1;
    long long cur_f = f - bytes;
    if (0 >= cur_f) {
      ans = min(ans, p1 * sajdasjdhjasd);
      break;
    }
    long long left = 0, right = (long long)1e7;
    while (left <= right) {
      long long mid = (left + right) / 2;
      long long other_bytes = min(cur_f, a2 * mid);
      if (mid > 0 && (other_bytes > cur_T || other_bytes * t2 > cur_T)) {
        right = mid - 1;
        continue;
      }
      long long other_T = cur_T - t2 * other_bytes;
      long long other_f = cur_f - other_bytes;
      if (other_f * t0 <= other_T) {
        right = mid - 1;
        ans = min(ans, p1 * sajdasjdhjasd + p2 * mid);
      } else {
        left = mid + 1;
      }
    }
  }
  printf("%lld\n", ans == (1LL << 60) ? -1 : ans);
  return 0;
}
