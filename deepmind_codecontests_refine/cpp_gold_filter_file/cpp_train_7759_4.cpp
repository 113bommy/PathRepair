#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long INF = 1e15;
long long power(long long x, long long y) {
  long long t = 1;
  while (y > 0) {
    if (y % 2)
      y -= 1, t = t * x % mod;
    else
      y /= 2, x = x * x % mod;
  }
  return t;
}
long long a[N];
long long b[N];
long long z[N];
int main() {
  for (int i = 0; i < N; ++i) b[i] = 1ll * i * i * i;
  long long t = 0;
  long long x = 1;
  while (a[t] <= INF) {
    while (x * x * x + a[t] <= INF) {
      if (3 * x * x + 3 * x + 1 > a[t]) break;
      x++;
    }
    if (x * x * x + a[t] > INF) break;
    a[t + 1] = x * x * x + a[t];
    t++;
  }
  t++;
  a[t] = INF + 100;
  long long m;
  scanf("%lld", &m);
  t = 0;
  while (a[t] <= m) t++;
  t--;
  x = 0;
  while (x * x * x <= m) x++;
  x--;
  long long s = t;
  long long sum = 0;
  while (m >= 0 && t) {
    if (m - b[x] >= a[t - 1]) {
      sum += b[x];
      m -= b[x];
      t--;
    } else {
      m = b[x] - 1;
      x--;
    }
    while (x * x * x > m) x--;
  }
  printf("%lld %lld\n", s, sum);
  return 0;
}
