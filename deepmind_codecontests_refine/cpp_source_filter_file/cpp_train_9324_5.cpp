#include <bits/stdc++.h>
using namespace std;
long long n, a[100005];
struct T {
  long long c[100005];
  void add(long long x, long long y) {
    for (; x <= n; x += x & -x) c[x] += y;
  }
  long long sum(long long x) {
    long long s = 0;
    for (; x; x -= x & -x) s += c[x];
    return s;
  }
} c, s;
int main() {
  long long i;
  long double ans = 0.0;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) ans += 0.5 * i * (n - i) * (n - i + 1);
  for (i = n; i >= 1; i--) {
    ans += c.sum(a[i] - 1) * (n * n + n - 2 * i - 2 * n * i);
    ans += 2 * s.sum(a[i] - 1) * i;
    c.add(a[i], 1);
    s.add(a[i], i);
  }
  printf("%.20Lf\n", 1.0 * ans / n / (n + 1));
  return 0;
}
