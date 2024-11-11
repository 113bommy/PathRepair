#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
long long a[50], ans[50];
long long n;
long long qwe(long long x, long long y) {
  long long ans = 1LL;
  while (y) {
    if (y & 1) ans = ans * x;
    x = x * x;
    y >>= 1;
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i <= 38; i++) a[i] = qwe(3LL, (long long)i);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    int wei = lower_bound(a, a + 39, n) - a;
    if (n > a[wei] / 2)
      printf("%lld\n", a[wei]);
    else {
      long long res = a[wei] / 2LL;
      for (int i = wei - 1; i >= 1; i--) {
        if (res - a[i] >= n) res -= a[i];
      }
      printf("%lld\n", res);
    }
  }
  return 0;
}
