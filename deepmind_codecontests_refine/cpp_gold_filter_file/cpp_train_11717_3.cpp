#include <bits/stdc++.h>
using namespace std;
const int N = 100008;
const long long M = 1000000007;
long long n, a[N];
long long suan(long long x, long long y, long long m) {
  long long t = 1;
  x %= m;
  while (y) {
    if (y & 1) t = t * x % m;
    x = x * x % m;
    y >>= 1;
  }
  return t;
}
int main(void) {
  long long i, k, p, p1, kk;
  scanf("%I64d", &n);
  for (i = 1; i <= n; i++) scanf("%I64d", a + i);
  for (i = 1; i <= n; i++)
    if (a[i] == 0) break;
  if (i <= n) {
    cout << "1/1";
    return 0;
  }
  for (i = 1; i <= n; i++)
    if (a[i] != 1) break;
  if (i > n) {
    cout << "0/1";
    return 0;
  }
  p = 1;
  for (i = 1; i <= n; i++)
    if (a[i] > 1 && a[i] % 2 == 0) p = 0;
  k = 2;
  for (i = 1; i <= n; i++) k = suan(k, a[i], 3) % 3;
  if (p)
    k = (k - 2 + 3) % 3;
  else
    k = (k + 2) % 3;
  if (k == 0)
    p1 = 1;
  else
    p1 = 0;
  k = 2;
  for (i = 1; i <= n; i++) k = suan(k, a[i], M) % M;
  if (p)
    kk = (k - 2 + M) % M;
  else
    kk = (k + 2) % M;
  k = k * 3 % M;
  if (p1) {
    k = k * suan(3, M - 2, M) % M;
    kk = kk * suan(3, M - 2, M) % M;
  }
  k = k * suan(2, M - 2, M) % M;
  kk = kk * suan(2, M - 2, M) % M;
  cout << kk << '/' << k;
  return 0;
}
