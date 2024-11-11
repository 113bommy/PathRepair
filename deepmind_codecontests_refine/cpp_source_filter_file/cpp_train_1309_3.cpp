#include <bits/stdc++.h>
using namespace std;
void In() { freopen("in.in", "r", stdin); }
void Out() { freopen("out.out", "w", stdout); }
const int N = 1e5 + 10;
const int M = 3e5 + 10;
const int Mbit = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
long long a[N], b[N];
long long sn, sn2, m;
int n;
long long Pow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % m;
    x = x * x % m;
    y >>= 1;
  }
  return ret % m;
}
int main() {
  bool ok = 0;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    (sn += a[i]) %= m;
    (sn2 += a[i] * a[i]) %= m;
  }
  if (n == 1) {
    printf("%lld 0\n", a[1]);
    return 0;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= n; i++) {
    long long d = a[i] - a[1];
    long long s = ((sn - n * (n - 1) / 2 * d) % m + m) % m * Pow(n, m - 2) % m;
    long long tmp =
        (n * s % m * s % m + n * (n - 1) * (2 * n - 1) / 6 % m * d * d % m +
         n * (n - 1) % m * d % m * s % m) %
        m;
    if (tmp == sn2) {
      for (int j = 1; j <= n; j++) b[j] = (s + (j - 1) * d) % m;
      sort(b + 1, b + 1 + n);
      bool flag = 1;
      for (int j = 1; j <= n; j++)
        if (a[j] != b[j]) {
          flag = 0;
          break;
        }
      if (flag) {
        printf("%lld %lld\n", s, d);
        ok = 1;
        break;
      }
    }
  }
  if (!ok) puts("-1");
  return 0;
}
