#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;
const int INF = 0x3f3f3f3f;
long long A, B, n, l, t, m;
long long cal(long long x) { return A + (x - 1) * B; }
long long get_sum(long long l, long long r) {
  return (cal(l) + cal(r)) * (r - l + 1) / 2;
}
int main(void) {
  while (scanf("%I64d%I64d%I64d", &A, &B, &n) == 3) {
    for (int i = 1; i <= n; ++i) {
      scanf("%I64d%I64d%I64d", &l, &t, &m);
      if (cal(l) > t) {
        puts("-1");
        continue;
      }
      long long x = l;
      long long r = (t - A) / B + 1;
      while (x <= r) {
        long long mid = (x + r) / 2;
        if (get_sum(l, mid) <= t * m)
          x = mid + 1;
        else
          r = mid - 1;
      }
      printf("%d\n", x - 1);
    }
  }
  return 0;
}
