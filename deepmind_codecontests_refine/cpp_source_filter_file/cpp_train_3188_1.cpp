#include <bits/stdc++.h>
int min(int a, int b) { return (a < b ? a : b); }
int main() {
  int n, k;
  long long ans;
  scanf("%d%d", &n, &k);
  int t = n;
  int n2 = 0, n5 = 0;
  while (t % 2 == 0) {
    n2++;
    t /= 2;
  }
  while (t % 5 == 0) {
    n5++;
    t /= 5;
  }
  if (n2 >= k && n5 >= k)
    ans = n;
  else {
    int cur = 0;
    ans = n;
    if (n2 < n5) {
      cur = n2 + min(n5 - n2, k - n2);
      for (int i = 1; i <= min(n5 - n2, k - n2); i++) ans *= 2 * 1ll;
      if (cur < k) {
        int extra = k - cur;
        for (int i = 1; i <= extra; i++) ans *= 10 * 1ll;
      }
    } else {
      cur = n5 + min(n2 - n5, k - n5);
      for (int i = 1; i <= min(n5 - n2, k - n5); i++) ans *= 5 * 1ll;
      if (cur < k) {
        int extra = k - cur;
        for (int i = 1; i <= extra; i++) ans *= 10 * 1ll;
      }
    }
  }
  printf("%lld\n", ans);
}
