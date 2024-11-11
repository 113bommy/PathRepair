#include <bits/stdc++.h>
using namespace std;
long long f(long long n, long long a, long long b, long long c) {
  long long m = (1ll * a * n + b) / c;
  if (!m) return 0;
  if (a >= c || b >= c)
    return n * (n + 1) / 2 * (a / c) + (b / c) * (n + 1) +
           f(n, a % c, b % c, c);
  return n * m - f(m - 1, c, c - b - 1, a);
}
void exgcd(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, d, y, x);
  y -= (a / b) * x;
}
long long calc(long long p, long long q, long long ans, long long a,
               long long b) {
  long long d, x, y;
  exgcd(p, q, d, x, y);
  if (ans % d) return 1e18;
  x = (x % (q / d) + (q / d)) % (q / d);
  x = x * (ans / d) % (q / d);
  if (x > b) return 2e9;
  if (a > x) x += ((a - x) / (q / d)) * (q / d);
  while (x <= a) x += q / d;
  if (x > b) return 2e9;
  return x;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, p, q;
    scanf("%d%d%d%d", &a, &b, &p, &q);
    p *= 2;
    q *= 2;
    long long l = 0, r = q / 2;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      long long sum = f(b, p, q - (q / 2 - mid), q) -
                      f(b, p, q - (q / 2 + mid) - 1, q) -
                      (f(a - 1, p, q - (q / 2 - mid), q) -
                       f(a - 1, p, q - (q / 2 + mid) - 1, q));
      if (sum > 0)
        r = mid - 1;
      else
        l = mid + 1;
    }
    cout << min(calc(p, q, q / 2 - l, a, b), calc(p, q, q / 2 + l, a, b))
         << "\n";
  }
}
