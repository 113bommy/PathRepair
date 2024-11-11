#include <bits/stdc++.h>
using namespace std;
int n;
long long c;
long long a[100005], b[100005];
int main() {
  while (scanf("%d%I64d", &n, &c) == 2) {
    long long R = 1LL << 60;
    c -= n;
    int inf = 1;
    for (int i = 0; i < n; i++) {
      scanf("%I64d%I64d", &a[i], &b[i]);
      if (a[i]) {
        inf = 0;
        R = min(R, ((c + 1) * b[i] + a[i] - 1) / a[i]);
      }
    }
    if (c < 0) {
      puts("0");
      continue;
    }
    if (inf) {
      if (c == 0)
        puts("-1");
      else
        puts("0");
      return 0;
    }
    long long ansl = 0, ansr = 0;
    long long lo = 0, hi = R;
    while (lo + 1 < hi) {
      long long mid = (lo + hi) / 2;
      long long tot = 0;
      for (int i = 0; i < n; i++) {
        long long t = a[i] * mid / b[i];
        if (t > c || tot + t > c) {
          tot = c + 1;
          break;
        }
        tot += t;
      }
      if (tot >= c)
        hi = mid;
      else
        lo = mid;
    }
    ansl = hi;
    lo = 0, hi = R;
    while (lo + 1 < hi) {
      long long mid = (lo + hi) / 2;
      long long tot = 0;
      for (int i = 0; i < n; i++) {
        long long t = a[i] * mid / b[i];
        if (t > c || tot + t > c) {
          tot = c + 1;
          break;
        }
        tot += t;
      }
      if (tot <= c)
        lo = mid;
      else
        hi = mid;
    }
    ansr = lo;
    printf("%I64d\n", max(0LL, ansr - ansl + 1));
  }
  return 0;
}
