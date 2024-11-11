#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000005;
long long n, L, t;
long long K;
long long a[maxn];
double ans;
int main() {
  scanf("%I64d%I64d%I64d", &n, &L, &t);
  t += t;
  K = t / L;
  t = t - L * K;
  ans += 0.25 * (double)K * (n - 1) * n;
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]), a[i + n] = a[i];
  for (int i = 1; i <= n; i++) {
    int l = i, r = i + n - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (mid > n) {
        if (L - a[i] + a[mid] <= t)
          l = mid;
        else
          r = mid - 1;
      } else {
        if (a[mid] - a[i] <= t)
          l = mid;
        else
          r = mid - 1;
      }
    }
    ans += 0.25 * (l - i);
  }
  printf("%lf\n", ans);
  return 0;
}
