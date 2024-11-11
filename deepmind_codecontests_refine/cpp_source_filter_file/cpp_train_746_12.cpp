#include <bits/stdc++.h>
const int maxn = 1e6 + 3;
int n, a[maxn];
long long k;
long long g(const long long &n) {
  return (n - 1 + (n % 2 ? 0 : 1)) * ((n + 1) / 2);
}
long long f(const long long &n) { return n * (1 + n) / 2ll; }
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; ++i) a[i] = i;
  if (k < f(n)) {
    puts("-1");
    return 0;
  }
  if (k >= f(n) + g(n) / 2) {
    printf("%lld\n", f(n) + g(n) / 2);
    for (int i = 1; i <= n; ++i) printf("%d%c", i, " \n"[i == n]);
    for (int i = n; i >= 1; --i) printf("%d%c", i, " \n"[i == 1]);
    return 0;
  }
  long long ans = f(n);
  for (int i = 1; i <= n; ++i) a[i] = i;
  for (int i = 1; i <= n / 2; ++i) {
    if (k - ans < n - 1 - i * 2ll) {
      std::swap(a[i], a[k - ans + i]);
      ans += k - ans;
      break;
    }
    std::swap(a[i], a[n - i + 1]);
    ans += n + 1 - 2 * 2ll;
  }
  printf("%lld\n", ans);
  for (int i = 1; i <= n; ++i) printf("%d%c", i, " \n"[i == n]);
  for (int i = n; i >= 1; --i) printf("%d%c", a[i], " \n"[i == 1]);
  return 0;
}
