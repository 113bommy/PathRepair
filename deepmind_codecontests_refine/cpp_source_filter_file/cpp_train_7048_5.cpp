#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 7;
const long long largest = 2e18;
long long a[maxn], sum[maxn] = {0}, mul = 1, fly[maxn];
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = n - 1; i > 0; --i) {
    if (a[i] == 1) fly[i - 1] = fly[i] + 1;
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    mul = 1;
    for (int j = i; j <= n; ++j) {
      long long h = sum[j] - sum[i - 1];
      if (largest / mul < a[j]) break;
      mul *= a[j];
      if (mul == k * h)
        ans++;
      else {
        if (mul % k == 0 && mul / k >= h && mul / k < h + fly[j]) ans++;
        j += fly[j];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
