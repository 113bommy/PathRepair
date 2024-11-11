#include <bits/stdc++.h>
using namespace std;
long long a[10010], n, m, k;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long tmp = exgcd(b, a % b, y, x);
  y -= x * (a / b);
  return tmp;
}
long long X, Y, x, y, d;
int main() {
  scanf("%I64d%I64d%I64d%I64d", &n, &m, &k, &a[1]);
  X = a[1];
  if (X > n) return puts("NO"), 0;
  for (int i = 2; i <= k; ++i) {
    scanf("%I64d", &a[i]);
    d = exgcd(X, a[i], x, y);
    if ((i - 1 + Y) % d) return puts("NO"), 0;
    x = x * (-1 + i - Y) / d % (a[i] / d);
    Y += x * X;
    X = X / d * a[i];
    if (X > n) return puts("NO"), 0;
    Y = (Y % X + X) % X;
  }
  if (!Y) Y = X;
  if (Y + k - 1 > m) return puts("NO"), 0;
  for (int i = 1; i <= k; ++i)
    if (gcd(X, Y + i - 1) != a[i]) return puts("NO"), 0;
  puts("YES");
  return 0;
}
