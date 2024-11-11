#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long a[N], s[N], n, ans, b[N], top;
inline long long gcd(const long long &x, const long long &y) {
  return x ? gcd(y % x, x) : y;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long I = 1; I <= 10; I++) {
    long long x = a[rand() % n * rand() % n + 1];
    top = 0;
    for (long long i = 1; i * i <= x; i++)
      if (x % i == 0) {
        s[++top] = i;
        if (i * i != x) s[++top] = x / i;
      }
    for (long long i = 1; i <= top; i++) b[i] = 0;
    sort(s + 1, s + top + 1);
    static long long now;
    for (long long i = 1; i <= n; i++) {
      now = lower_bound(s + 1, s + top + 1, gcd(a[i], x)) - s;
      b[now]++;
    }
    for (long long i = 1; i <= top; i++)
      for (long long j = i + 1; j <= top; j++)
        if (s[j] % s[i] == 0) b[i] += b[j];
    for (long long i = 1; i <= top; i++)
      if (b[i] << 1 >= n) ans = max(ans, s[i]);
  }
  printf("%lld", ans);
}
