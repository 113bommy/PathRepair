#include <bits/stdc++.h>
using namespace std;
long long T, n, m;
long long c[100];
long long getpow(long long x) {
  for (long long i = 0;; i++) {
    if ((x >> i) & 1) {
      return i;
    }
  }
}
void work() {
  memset(c, 0, sizeof(c));
  scanf("%lld%lld", &n, &m);
  long long x, ans = 0;
  for (long long i = 1; i <= m; i++) {
    scanf("%lld", &x);
    c[getpow(x)]++;
  }
  for (long long i = 0; i < 63; i++) {
    if ((n >> i) & 1) {
      bool flag = true;
      for (long long j = i; j < 63; j++) {
        if (c[j]) {
          c[j]--, ans += j - i, flag = false;
          for (long long k = i; k < j; k++) {
            c[k]++;
          }
          break;
        }
      }
      if (flag) {
        printf("-1\n");
        return;
      }
    }
    c[i + 1] += c[i] >> 1;
  }
  printf("%lld\n", ans);
}
signed main() {
  scanf("%lld", &T);
  while (T--) {
    work();
  }
}
