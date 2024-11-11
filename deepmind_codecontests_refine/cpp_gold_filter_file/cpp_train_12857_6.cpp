#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  while (scanf("%d %d", &n, &k) == 2) {
    long long a[n / k], b[n / k];
    for (int i = 0; i < n / k; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n / k; i++) scanf("%lld", &b[i]);
    long long t = 9, base = 1;
    for (int i = 1; i < k; i++) t = t * 10 + 9, base *= 10;
    long long Ans = 1, pos = 0, low_base, up_base;
    for (int i = 0; i < n / k; i++) {
      pos = t / a[i] + 1;
      low_base = base * b[i] - 1;
      if (b[i] == 0) low_base += 1, pos--;
      up_base = base * (b[i] + 1) - 1;
      pos -= (up_base / a[i] - low_base / a[i]);
      Ans *= pos;
      Ans %= 1000000007;
    }
    printf("%lld\n", Ans);
  }
  return 0;
}
