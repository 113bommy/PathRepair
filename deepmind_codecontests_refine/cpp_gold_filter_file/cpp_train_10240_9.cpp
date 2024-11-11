#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  static int a[100000];
  for (int i = 0; i < (n); i++) scanf("%d", a + i);
  sort(a, a + n);
  n--;
  long long one = 0;
  for (int i = 0; i < (n); i++) one += (long long)(n - i) * a[i];
  static long long sum[100001];
  for (int i = 0; i < (n); i++) sum[i + 1] = sum[i] + a[i];
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    scanf("%d", &k);
    if (k == 1) {
      printf("%lld\n", one);
    } else {
      long long ans = 0;
      int m = n, dep = 1;
      long long kpow = k;
      while (m > 0) {
        int a = min((long long)m, kpow);
        ans += dep * (sum[m] - sum[m - a]);
        m -= a;
        dep++;
        kpow *= k;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
