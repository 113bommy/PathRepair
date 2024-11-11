#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
long long a[maxn], b[maxn];
long long l[maxn], r[maxn];
int main() {
  int n, k, ll, rr;
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%I64d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
      b[i - 1] = abs(a[i] - a[i - 1]);
    }
    l[0] = 0;
    for (int i = 1; i < n - 1; i++) {
      int x = i - 1;
      l[i] = i;
      while (b[i] > b[x]) {
        l[i] = l[x];
        x = l[x] - 1;
        if (x < 0) break;
      }
    }
    r[n - 2] = n - 2;
    for (int i = n - 3; i >= 0; i--) {
      int x = i + 1;
      r[i] = i;
      while (b[i] >= b[x]) {
        r[i] = r[x];
        x = r[x] + 1;
        if (x > n - 2) break;
      }
    }
    while (k--) {
      scanf("%d%d", &ll, &rr);
      long long ans = 0;
      for (int i = ll - 1; i < rr - 1; i++) {
        ans += b[i] * (i - max(l[i], (long long)ll - 1) + 1) *
               (min(r[i], (long long)rr - 2) - i + 1);
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
